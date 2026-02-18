# Arduino Robotics Projects

Hands-on embedded systems and robotics experiments using Arduino. Focused on building functional prototypes with sensors, motors, and wireless control.

## Projects Included

1. **Bluetooth-Controlled Car**
   - **Description**: A 4-wheel robot car controlled via Bluetooth from Arduino Bluetooth Controller app. Uses the HC-06 blutooth module.
   - **Features**:
     - Forward/backward, left/right turning
   - **Hardware**:
     - Arduino Nano
     - L298N motor driver
     - 4 DC motors + chassis
     - HC-06 Bluetooth module
     - LI - ion battery pack
   - **Code**: `car_bluetooth.ino` — Reads serial commands from Bluetooth and maps to motor direction pins.
   - **Demo**: [Bluetooth Car Driver.MOV](Bluetooth%20Car%20Driver.MOV) (video of it moving!)

2. **Ultrasonic Obstacle-Avoiding Car**
   - **Description**: Autonomous robot that detects obstacles with an ultrasonic sensor and avoids them by turning. A RGB LED and buzzer are also included. The RGB is green until faced with an obstacle [turns red and the buzzer turns on]
   - **Features**:
     - Continuous distance measurement
     - Stop/turn logic when obstacle < 20 cm
   - **Hardware**:
     - Same chassis/motors as above
     - Ultrasonic sensor
     - RGB LED
     - Buzzer
   - **Code**: `car_ultrasonic.ino.
   - **Demo**: [Ultrasonic Car.MOV](UltrasonicCar.MOV)

## How to Run / Replicate
1. Upload the .ino file to Arduino Nano using Arduino IDE.
2. Connect hardware as per standard schematics.
3. For Bluetooth: Pair HC-06 with phone, send commands like 'F' for forward.


Feel free to fork or ask questions — happy building! 🤖
