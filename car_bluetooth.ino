int in1 = 4, in2 = 5;
int in3 = 6, in4 = 7;
int enA = 3, enB = 9;

void setup() {
  pinMode(in1, OUTPUT); pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT); pinMode(in4, OUTPUT);
  pinMode(enA, OUTPUT); pinMode(enB, OUTPUT);

  stop();
  Serial.begin(9600);
}

void loop() {
  if (!Serial.available()) return;

  char c = Serial.read();
  if (c == '\n' || c == '\r') return;

  if (c >= 'a' && c <= 'z') c = c - 'a' + 'A';

  switch (c) {
    case 'F': forward(); break;
    case 'B': backward(); break;
    case 'L': left(); break;
    case 'R': right(); break;
    case 'S': stop(); break;
  }
}

void forward(){
  digitalWrite(in1, HIGH); digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);  digitalWrite(in4, HIGH);
  analogWrite(enA, 180);   analogWrite(enB, 180);
}
void backward(){
  digitalWrite(in1, LOW);  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH); digitalWrite(in4, LOW);
  analogWrite(enA, 180);   analogWrite(enB, 180);
}
void right(){
  digitalWrite(in1, LOW);  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);  digitalWrite(in4, HIGH);
  analogWrite(enA, 180);   analogWrite(enB, 180);
}
void left(){
  digitalWrite(in1, HIGH); digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH); digitalWrite(in4, LOW);
  analogWrite(enA, 180);   analogWrite(enB, 180);
}
void stop(){
  digitalWrite(in1, LOW); digitalWrite(in2, LOW);
  digitalWrite(in3, LOW); digitalWrite(in4, LOW);
  analogWrite(enA, 0);    analogWrite(enB, 0);
}
