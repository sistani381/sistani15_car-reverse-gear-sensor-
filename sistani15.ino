long duration;
int distance;
int ledred = 11;
int BUZZER_PIN = 6;
const int trig = 9;
const int echo = 10;
void setup() {
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(6, OUTPUT);
  pinMode(11, OUTPUT);
  Serial.begin(9600);
}
void loop() {
  distance = calculateDistance();
  Serial.print("distance = ");
  Serial.print(distance);
  Serial.println(" cm");
  if (distance < 10) {
    digitalWrite(6, HIGH);
    digitalWrite(11, HIGH);
  }
  else if (distance > 30) {
    digitalWrite(6, LOW);
    digitalWrite(11, LOW);
  }
  else  {
    int ultra = map(distance, 10, 30, 255, 0);
    analogWrite(6, ultra);
    analogWrite(11, ultra);
  }
}
int calculateDistance() {
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  duration = pulseIn(echo, HIGH);
  distance = duration * 0.034 / 2;
  return distance;
}
