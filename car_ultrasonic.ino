int in1 = 4, in2 = 5;
int in3 = 6, in4 = 7;

int enA = 3, enB = 9;
int trig = 11, echo = 10;

int red = 8, green = 12;
int buzz = 2;

float distance = 0;

void setup() {
  pinMode(in1, OUTPUT); pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT); pinMode(in4, OUTPUT);
  pinMode(enA, OUTPUT); pinMode(enB, OUTPUT);

  pinMode(red, OUTPUT); pinMode(green, OUTPUT);
  pinMode(buzz, OUTPUT);

  pinMode(trig, OUTPUT); pinMode(echo, INPUT);

  digitalWrite(trig, LOW);
  Serial.begin(9600);
}

void loop() {
  distance = ultrasonic();

  Serial.print("Distance: ");
  Serial.println(distance);

  if (distance < 25) {
    digitalWrite(buzz, HIGH);
    digitalWrite(red, HIGH);
    digitalWrite(green, LOW);

    right();
    delay(350);
    stop();
    delay(100);
  } else {
    digitalWrite(buzz, LOW);
    digitalWrite(red, LOW);
    digitalWrite(green, HIGH);

    forward();
  }

  delay(50);
}

void forward() {
  digitalWrite(in1, HIGH); digitalWrite(in2, LOW);
  // digitalWrite(in3, LOW); digitalWrite(in4, HIGH);

  
  analogWrite(enA, 180);
  analogWrite(enB, 180);
}

void right() {
  digitalWrite(in1, HIGH); digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);  digitalWrite(in4, LOW);
  analogWrite(enA, 180);
  analogWrite(enB, 180);
}

void stop() {
  digitalWrite(in1, LOW); digitalWrite(in2, LOW);
  digitalWrite(in3, LOW); digitalWrite(in4, LOW);
  analogWrite(enA, 0);
  analogWrite(enB, 0);
}

float ultrasonic() {
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  // 30,000 us timeout ≈ ~5 meters max distance
  long duration = pulseIn(echo, HIGH, 30000);

  if (duration == 0) {
    return 999; // "no echo" => treat as far away
  }

  return (duration * 0.0343) / 2.0;
}
