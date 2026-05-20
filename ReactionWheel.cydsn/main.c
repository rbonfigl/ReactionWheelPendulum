#include "project.h"
#include <math.h>
#include <stdio.h>

#define PWM_CENTER       600
#define PI               3.14159265f
#define POLE_PAIRS       7.0f
#define AS5600_ADDR      0x36
#define AS5600_ANGLE_REG 0x0E

uint16 Read_AS5600_Angle(void)
{
    uint8 msb = 0, lsb = 0;
    uint32 timeout = 50;
    I2C_I2CMasterSendStart(AS5600_ADDR, I2C_I2C_WRITE_XFER_MODE, timeout);
    I2C_I2CMasterWriteByte(AS5600_ANGLE_REG, timeout);
    I2C_I2CMasterSendRestart(AS5600_ADDR, I2C_I2C_READ_XFER_MODE, timeout);
    I2C_I2CMasterReadByte(I2C_I2C_ACK_DATA, &msb, timeout);
    I2C_I2CMasterReadByte(I2C_I2C_NAK_DATA, &lsb, timeout);
    I2C_I2CMasterSendStop(timeout);
    return (msb << 8) | lsb;
}

void IMU_WakeUp(void)
{
    uint8_t buf[2];
    buf[0] = 0x7F; buf[1] = 0x00;
    I2C_I2CMasterWriteBuf(0x69, buf, 2, I2C_I2C_MODE_COMPLETE_XFER);
    while(!(I2C_I2CMasterStatus() & I2C_I2C_MSTAT_WR_CMPLT));
    I2C_I2CMasterClearStatus();
    buf[0] = 0x06; buf[1] = 0x01;
    I2C_I2CMasterWriteBuf(0x69, buf, 2, I2C_I2C_MODE_COMPLETE_XFER);
    while(!(I2C_I2CMasterStatus() & I2C_I2C_MSTAT_WR_CMPLT));
    I2C_I2CMasterClearStatus();
}

int main(void)
{
    CyGlobalIntEnable;
    UART_Start();
    CyDelay(50);
    UART_UartPutString("BOOT\r\n");
    I2C_Start();
    IMU_WakeUp();
    IN_1_Start();
    IN_2_Start();
    IN_3_Start();
    Timer_Start();
    EN_PIN_Write(1);

    //Calibration
    IN_1_WriteCompare(PWM_CENTER + (int)(250 * sin(0)));
    IN_2_WriteCompare(PWM_CENTER + (int)(250 * sin(2.0f * PI / 3.0f)));
    IN_3_WriteCompare(PWM_CENTER + (int)(250 * sin(4.0f * PI / 3.0f)));
    CyDelay(3000);

    //Average 10 encoder
    uint32 sum = 0;
    for(int i = 0; i < 10; i++) {
        sum += Read_AS5600_Angle();
        CyDelay(10);
    }
    uint16 zeroRaw   = (uint16)(sum / 10);
    float zeroMech   = ((float)zeroRaw / 4096.0f) * (2.0f * PI);
    float zeroOffset = fmod(zeroMech * POLE_PAIRS, 2.0f * PI);

    char msg[128];
    sprintf(msg, "zeroOffset: %d\r\n", (int)(zeroOffset * 1000));
    UART_UartPutString(msg);

    
    volatile float currentAngle        = 0.0f;
    float integralSum         = 0.0f;
    float filteredGyro        = 0.0f;
    float filteredMotorVel    = 0.0f;
    float previousMechAngle   = zeroMech;
    float alpha               = 0.98f;
    int   printCounter        = 0;
    uint16 prevTicks          = Timer_ReadCounter();
    uint8_t dataIMU[12];

    float targetAngle = .60f; 
    float Kp          = 64.0f;
    float Kd          = 7.5f;
    float Ki          = 0.25f; 
    float Kw          = .08f;
    float max_effort  = 600.0f;

    UART_UartPutString("Running...\r\n");

    for(;;)
    {
        uint16 curTicks   = Timer_ReadCounter();
        uint16 deltaTicks = prevTicks - curTicks;
        prevTicks = curTicks;
        float dt = (float)deltaTicks / 1000000.0f;
        if (dt < 0.0001f || dt > 0.05f) dt = 0.002f;

        //Read IMU
        uint8_t regPtr = 0x2D;
        I2C_I2CMasterWriteBuf(0x69, &regPtr, 1, I2C_I2C_MODE_COMPLETE_XFER);
        while(!(I2C_I2CMasterStatus() & I2C_I2C_MSTAT_WR_CMPLT));
        I2C_I2CMasterClearStatus();
        I2C_I2CMasterReadBuf(0x69, dataIMU, 12, I2C_I2C_MODE_COMPLETE_XFER);
        while(!(I2C_I2CMasterStatus() & I2C_I2C_MSTAT_RD_CMPLT));
        I2C_I2CMasterClearStatus();

        int16_t accelX = (int16_t)((dataIMU[0] << 8) | dataIMU[1]);
        int16_t accelY = (int16_t)((dataIMU[2] << 8) | dataIMU[3]);
        int16_t gyroZ  = (int16_t)((dataIMU[10] << 8) | dataIMU[11]);

        //Low pass filter gyro to kill buzz
        float rawGyroRate = (float)gyroZ / 131.0f;
        if (rawGyroRate > -1.5f && rawGyroRate < 1.5f) rawGyroRate = 0.0f; // deadband
        filteredGyro = 0.07f * rawGyroRate + 0.93f * filteredGyro;

        //Complementary filter for angle
        float accelAngle = atan2((float)accelY, (float)-accelX) * (180.0f / PI);
        currentAngle = alpha * (currentAngle + filteredGyro * dt)
                     + (1.0f - alpha) * accelAngle;

        uint16 rawAngle       = Read_AS5600_Angle();
        float mechanicalAngle = ((float)rawAngle / 4096.0f) * (2.0f * PI);
        
        float rawMotorVel = mechanicalAngle - previousMechAngle;
        if (rawMotorVel >  PI) rawMotorVel -= 2.0f * PI;
        if (rawMotorVel < -PI) rawMotorVel += 2.0f * PI;
        rawMotorVel /= dt;
        previousMechAngle = mechanicalAngle;
        filteredMotorVel = 0.1f * rawMotorVel + 0.9f * filteredMotorVel;

        //PID
        float error = targetAngle - currentAngle;

        integralSum += error * dt;
        if (integralSum >  100.0f) integralSum =  100.0f;
        if (integralSum < -100.0f) integralSum = -100.0f;

        float controlEffort = -((Kp * error) + (Ki * integralSum) - (Kd * filteredGyro));

        controlEffort -= Kw * filteredMotorVel;

        if (controlEffort >  max_effort) controlEffort =  max_effort;
        if (controlEffort < -max_effort) controlEffort = -max_effort;

        //FOC
        float electricalAngle = fmod(mechanicalAngle * POLE_PAIRS, 2.0f * PI);
        electricalAngle -= zeroOffset;
        if (electricalAngle < 0.0f) electricalAngle += 2.0f * PI;

        float theta = electricalAngle + (PI / 2.0f);

        float fA = PWM_CENTER + (controlEffort * sin(theta));
        float fB = PWM_CENTER + (controlEffort * sin(theta + (2.0f * PI / 3.0f)));
        float fC = PWM_CENTER + (controlEffort * sin(theta + (4.0f * PI / 3.0f)));

        if (fA < 0.0f) fA = 0.0f; if (fA > 1200.0f) fA = 1200.0f;
        if (fB < 0.0f) fB = 0.0f; if (fB > 1200.0f) fB = 1200.0f;
        if (fC < 0.0f) fC = 0.0f; if (fC > 1200.0f) fC = 1200.0f;

        IN_1_WriteCompare((uint16)fA);
        IN_2_WriteCompare((uint16)fB);
        IN_3_WriteCompare((uint16)fC);

        printCounter++;
        if (printCounter >= 70)
        {
            sprintf(msg, "Ang: %d | Eff: %d | Gyro: %d | WheelV: %d | dt_us: %d\r\n",
                    (int)(currentAngle * 10.0f),
                    (int)controlEffort,
                    (int)filteredGyro,
                    (int)filteredMotorVel,
                    (int)(dt * 1000000.0f));
            UART_UartPutString(msg);
            printCounter = 0;
        }
    }
}