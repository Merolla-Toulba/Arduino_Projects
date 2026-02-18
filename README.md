# Arduino Robotics Projects

Hands-on embedded systems and robotics experiments using Arduino. Focused on building functional prototypes with sensors, motors, and wireless control — ideal for exploring Mechatronics basics like sensor fusion, motor control, and autonomous behavior.

## Projects

### 1. Bluetooth-Controlled Car
**Description**: 4-wheel robot car controlled via Bluetooth from a smartphone app (e.g., Arduino Bluetooth Controller). Uses HC-06 module + L298N driver.

**Features**:
- Forward/backward, left/right turning
- Variable speed via PWM

**Hardware**:
- Arduino Nano
- L298N motor driver
- 4 DC motors + chassis
- HC-06 Bluetooth module
- Li-ion battery pack

**Pin Connections** (example):
- HC-06 TX → D0 (RX)
- HC-06 RX → D1 (TX)
- L298N IN1–IN4 → D4–D7
- ENA/ENB → D9/D10 (PWM)

**Code**: `car_bluetooth.ino` — Reads serial commands and controls motors.

**Demo**:
<video src="Bluetooth%20Car%20Driver.MOV" controls width="600"></video>

### 2. Ultrasonic Obstacle-Avoiding Car
**Description**: Autonomous robot using HC-SR04 to detect obstacles (<20 cm) and avoid by turning. Includes RGB LED (green → red on obstacle) and buzzer alert.

**Features**:
- Continuous distance measurement
- Stop/turn logic
- Visual/audio feedback

**Hardware**:
- Same chassis/motors as above
- HC-SR04 ultrasonic sensor
- RGB LED + buzzer

**Pin Connections** (example):
- HC-SR04 Trig → D8, Echo → D9
- RGB → D5/D6/D3 (PWM)
- Buzzer → D11

**Code**: `car_ultrasonic.ino`

**Demo**:
<video src="UltrasonicCar.MOV" controls width="600"></video>

## How to Replicate
1. Upload .ino to Arduino using IDE.
2. Wire as per connections (add photos/schematics soon).
3. For Bluetooth: Pair module, send commands (F=forward, etc.).

## What I Learned & Challenges
- Bluetooth serial parsing and reliable wireless control.
- Ultrasonic noise filtering and timing.
- Integrating multiple components (sensors + actuators + feedback).
- Debugging real hardware issues — built my practical Mechatronics skills!

Happy building! Questions? Fork or reach out 🤖
