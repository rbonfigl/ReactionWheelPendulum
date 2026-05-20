

https://github.com/user-attachments/assets/79cb2683-9264-4119-930e-6eb8ff439746



This project implements a Reaction Wheel Pendulum, a form of self-balancing inverted pendulum that uses a high-speed flywheel (reaction wheel) to maintain upright stability. The system demonstrates real-time embedded control, sensor fusion, and motor actuation in a closed-loop control system.

<img width="219" height="230" alt="image" src="https://github.com/user-attachments/assets/24f7f9df-7b40-4ce6-960a-5243e7402e2f" />

-Overview-

The reaction wheel pendulum maintains balance by controlling the angular momentum of a spinning flywheel. By accelerating or decelerating the wheel, an opposing torque is generated that stabilizes the pendulum in the upright position.

This project was developed as a real-time embedded systems implementation, combining hardware integration with control theory and firmware design.

-Hardware Architecture-

The system is built around the following components:

Microcontroller: Cypress PSoC 4 (PSoC 044)
Inertial Measurement Unit (IMU): Communicates via I2C for real-time angular position and rate feedback
BLDC Motor: Used as the reaction wheel actuator
Motor Encoder: Provides rotational position/speed feedback via I2C
Motor Driver: Texas Instruments motor driver for high-current control of the BLDC motor
Software & Control System

The firmware implements a real-time closed-loop control system featuring:

I2C Communication Drivers for IMU and encoder data acquisition
Sensor Fusion for estimating pendulum angle and angular velocity
PID Control Loop for stabilizing the inverted pendulum
Motor Control Interface to regulate BLDC torque output through PWM and driver commands
Real-time Execution Loop optimized for deterministic control timing

-System Behavior-

The control system continuously:
Reads angular position and angular velocity from the IMU
Processes encoder feedback from the reaction wheel
Computes control output using a PID controller
Adjusts motor torque to counteract deviations from the upright equilibrium
