const int irLedPin = 7;
const int irReceiverPin = A0;
const int trigPin = 9;
const int echoPin = 10;

void setup() {
  Serial.begin(9600);
  pinMode(irLedPin, OUTPUT);
  digitalWrite(irLedPin, HIGH);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  int irValue = readIRSensor();
  float distance = readUltrasonic();

  Serial.print("IR Value: ");
  Serial.print(irValue);
  Serial.print(" | Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  analyzeFabric(irValue, distance);

  Serial.println("-----------------------");
  delay(500);
}

int readIRSensor() {
  return analogRead(irReceiverPin);
}

float readUltrasonic() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH);
  return duration * 0.034 / 2.0;
}

void analyzeFabric(int ir, float dist) {
  if (ir > 700 && dist < 15) {
    Serial.println("Fabric detected - Possibly thick or wrinkled");
  } else if (ir > 400 && dist < 20) {
    Serial.println("Fabric detected - Possibly thin or smooth");
  } else {
    Serial.println("No fabric detected");
  }
}
