#include "project.h"
#include <math.h>
#include <stdio.h>

#define PWM_CENTER    1200
#define PI            3.14159265
#define POLE_PAIRS    7.0


#define AS5600_ADDR       0x36
#define AS5600_ANGLE_REG  0x0E

// I2C read function 
uint16 Read_AS5600_Angle(void)
{
    uint8 msb = 0;
    uint8 lsb = 0;
    uint32 timeout = 50; 

    I2C_I2CMasterSendStart(AS5600_ADDR, I2C_I2C_WRITE_XFER_MODE, timeout);
    I2C_I2CMasterWriteByte(AS5600_ANGLE_REG, timeout);
    I2C_I2CMasterSendRestart(AS5600_ADDR, I2C_I2C_READ_XFER_MODE, timeout);
    I2C_I2CMasterReadByte(I2C_I2C_ACK_DATA, &msb, timeout);
    I2C_I2CMasterReadByte(I2C_I2C_NAK_DATA, &lsb, timeout);
    I2C_I2CMasterSendStop(timeout);

    return (msb << 8) | lsb;
}

int main(void)
{
    CyGlobalIntEnable;

    UART_Start();
    I2C_Start();
    IN_1_Start();
    IN_2_Start();
    IN_3_Start();

    EN_PIN_Write(1);
    
    int AMPLITUDE = 250;

    //Calibration
    // Force the motor to electrical angle 0
    IN_1_WriteCompare(PWM_CENTER + (AMPLITUDE * sin(0)));
    IN_2_WriteCompare(PWM_CENTER + (AMPLITUDE * sin(2.0 * PI / 3.0)));
    IN_3_WriteCompare(PWM_CENTER + (AMPLITUDE * sin(4.0 * PI / 3.0)));
    
    // Wait for the mechanical jolt to settle
    CyDelay(1000); 
    
    // Read the sensor at this locked position
    uint16 zeroRaw = Read_AS5600_Angle();
    float zeroMech = ((float)zeroRaw / 4096.0) * (2.0 * PI);
    float zeroOffset = fmod((zeroMech * POLE_PAIRS), (2.0 * PI));
    //End calibration
    
 
    uint16 rawAngle;
    float mechanicalAngle;
    float electricalAngle;
    float theta;
    uint16 compareA, compareB, compareC;
    char debugStr[64];
    
    AMPLITUDE = -500;
    float lastMechAngle = 0;
    float velocity = 0;
    float filteredVelocity = 0;
    int direction = 1;
    for(;;)
    {
        //Read position
        rawAngle = Read_AS5600_Angle();
        mechanicalAngle = ((float)rawAngle / 4096.0) * (2.0 * PI);
        
        float deltaAngle = mechanicalAngle - lastMechAngle;
        
        // If the jump is bigger than PI, we assume it wrapped around
        if (deltaAngle > PI)  deltaAngle -= (2.0 * PI); 
        if (deltaAngle < -PI) deltaAngle += (2.0 * PI);
        
        velocity = deltaAngle * 2000.0;
        lastMechAngle = mechanicalAngle;
        
        // 4. LOW PASS FILTER (Cleans up sensor noise)
        filteredVelocity = (0.9 * filteredVelocity) + (0.1 * velocity);
        
        electricalAngle = fmod((mechanicalAngle * POLE_PAIRS), (2.0 * PI));
        
        electricalAngle -= zeroOffset;
        if (electricalAngle < 0.0) 
        {
            electricalAngle += (2.0 * PI);
        }

        theta = electricalAngle + (PI / 2.0);

        compareA = PWM_CENTER + (AMPLITUDE * sin(theta));
        compareB = PWM_CENTER + (AMPLITUDE * sin(theta + (2.0 * PI / 3.0)));
        compareC = PWM_CENTER + (AMPLITUDE * sin(theta + (4.0 * PI / 3.0)));

        IN_1_WriteCompare(compareA);
        IN_2_WriteCompare(compareB);
        IN_3_WriteCompare(compareC);
        
        if(direction){
            if(AMPLITUDE > 750){

                direction = 0;
            }
            AMPLITUDE++;
        }

        if(!direction){
            if(AMPLITUDE < -750){
                direction = 1;
            }
            AMPLITUDE--;

        }
        CyDelayUs(500);
    }
}