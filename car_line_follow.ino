#define lineOnBlack   LOW
#define noLine         HIGH
#define obstacle        LOW
#define noObstacle     HIGH


int right = 2; int center = 3; int left = 4;

int leftIR = 5; int rightIR = 6;

int enA = 10; int enB = 11;

int in1 = 7; int in2 = 8;

int in3 = 9; int in4 = 12;


const int   BASE_SPEED   = 140;
const float KP           = 0.25;
const float KI           = 0.004;
const float KD           = 0.20;

int   lastError = 0;
float integral  = 0.0;

const int POS_LEFT   = -2000;
const int POS_CENTER = 0;
const int POS_RIGHT  = 2000;
const int LOST_LINE  = 9999;


void setup() {
  
  pinMode(left,   INPUT_PULLUP);
  pinMode(center, INPUT_PULLUP);
  pinMode(right,  INPUT_PULLUP);

  pinMode(leftIR,  INPUT_PULLUP);
  pinMode(rightIR, INPUT_PULLUP);


  pinMode(in1, OUTPUT); pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT); pinMode(in4, OUTPUT);
  pinMode(enA, OUTPUT); pinMode(enB, OUTPUT);

  digitalWrite(in1, LOW); digitalWrite(in2, LOW);
  digitalWrite(in3, LOW); digitalWrite(in4, LOW);
  analogWrite(enA, 0); analogWrite(enB, 0);

  Serial.begin(9600);
  delay(1500);

}

void loop() {
  // Read obstacle sensors first (priority)
  bool obsLeft  = (digitalRead(leftIR)  == OBSTACLE);
  bool obsRight = (digitalRead(rightIR) == OBSTACLE);

  if (obsLeft || obsRight) {
    avoidObstacle(obsLeft, obsRight);
  } else {
    followLineWithPID();
  }

  delay(10);   // small loop delay → ~100 Hz → good for PID
}

// =============================================
//  OBSTACLE AVOIDANCE (simple reactive)
// =============================================
void avoidObstacle(bool left, bool right) {
  integral = 0;     // reset PID accumulator
  lastError = 0;

  stopMotors();     // brief stop to think
  delay(80);

  if (left && right) {
    // Both sides blocked → back up slowly
    moveBackward(100);
    Serial.println("Both obstacles → back");
  } 
  else if (left) {
    // Left blocked → turn right
    turnRight(140);
    Serial.println("Left obstacle → turn RIGHT");
  } 
  else if (right) {
    // Right blocked → turn left
    turnLeft(140);
    Serial.println("Right obstacle → turn LEFT");
  }

  delay(300);   // give time to rotate away
  stopMotors();
  delay(100);
}

// =============================================
//  PID LINE FOLLOWING
// =============================================
void followLineWithPID() {
  int error = readLinePosition();

  if (error == LOST_LINE) {
    stopMotors();
    Serial.println("Line lost → stopped");
    integral = 0;
    return;
  }

  // PID calculation
  integral += error;
  integral = constrain(integral, -4000, 4000);   // prevent windup

  float derivative = error - lastError;
  float correction = (KP * error) + (KI * integral) + (KD * derivative);

  int leftSpeed  = BASE_SPEED + (int)correction;
  int rightSpeed = BASE_SPEED - (int)correction;

  // Limit PWM range
  leftSpeed  = constrain(leftSpeed, -255, 255);
  rightSpeed = constrain(rightSpeed, -255, 255);

  // Drive motors (allow reverse if needed for sharp turns)
  driveMotors(leftSpeed, rightSpeed);

  // Optional debug (uncomment to tune)
  // Serial.print("Err: "); Serial.print(error);
  // Serial.print(" | corr: "); Serial.print(correction);
  // Serial.print(" | L: "); Serial.print(leftSpeed);
  // Serial.print(" R: "); Serial.println(rightSpeed);

  lastError = error;
}

// =============================================
//  Read 3 sensors → compute position error
// =============================================
int readLinePosition() {
  int l = digitalRead(left);
  int c = digitalRead(center);
  int r = digitalRead(right);

  // All sensors see white → line lost
  if (l == NO_LINE && c == NO_LINE && r == NO_LINE) {
    return LOST_LINE;
  }

  // Weighted position (negative = line to the left, positive = to the right)
  int position = 0;
  int count = 0;

  if (l == LINE_ON_BLACK) { position += POS_LEFT;   count++; }
  if (c == LINE_ON_BLACK) { position += POS_CENTER; count++; }
  if (r == LINE_ON_BLACK) { position += POS_RIGHT;  count++; }

  if (count == 0) return LOST_LINE;

  return position / count;   // average if multiple sensors see line
}


