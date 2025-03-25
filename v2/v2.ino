const int irLedPin = 7;
const int irReceiverPin = A0;
const int trigPin = 9;
const int echoPin = 10;

float readUltrasonic();
int arrayMax(int arr[], int size);
int arrayMin(int arr[], int size);
float arrayMaxFloat(float arr[], int size);
float arrayMinFloat(float arr[], int size);

void setup() {
  Serial.begin(9600);
  pinMode(irLedPin, OUTPUT);
  digitalWrite(irLedPin, HIGH);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  int irAvg = getAverageIR();
  float distanceAvg = getAverageDistance();
  Serial.print("IR Avg: ");
  Serial.print(irAvg);
  Serial.print(" | Distance Avg: ");
  Serial.print(distanceAvg);
  Serial.println(" cm");
  analyzeFabric(irAvg, distanceAvg);
  Serial.println("-----------------------");
  delay(1000);
}

int getAverageIR() {
  long sum = 0;
  for (int i = 0; i < 5; i++) {
    sum += analogRead(irReceiverPin);
    delay(50);
  }
  return sum / 5;
}

float getAverageDistance() {
  float sum = 0;
  for (int i = 0; i < 5; i++) {
    sum += readUltrasonic();
    delay(50);
  }
  return sum / 5;
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
  if (ir < 300 && dist > 25) {
    Serial.println("No fabric detected");
    return;
  }
  bool wrinkled = isWrinkled();
  if (wrinkled) {
    Serial.println("Fabric detected - WRINKLED");
  } else {
    Serial.println("Fabric detected - SMOOTH");
  }
}

bool isWrinkled() {
  int irReadings[5];
  float distReadings[5];
  for (int i = 0; i < 5; i++) {
    irReadings[i] = analogRead(irReceiverPin);
    distReadings[i] = readUltrasonic();
    delay(50);
  }
  int irRange = arrayMax(irReadings, 5) - arrayMin(irReadings, 5);
  float distRange = arrayMaxFloat(distReadings, 5) - arrayMinFloat(distReadings, 5);
  return (irRange > 50 || distRange > 1.5);
}

int arrayMax(int arr[], int size) {
  int maxVal = arr[0];
  for (int i = 1; i < size; i++) {
    if (arr[i] > maxVal) maxVal = arr[i];
  }
  return maxVal;
}

int arrayMin(int arr[], int size) {
  int minVal = arr[0];
  for (int i = 1; i < size; i++) {
    if (arr[i] < minVal) minVal = arr[i];
  }
  return minVal;
}

float arrayMaxFloat(float arr[], int size) {
  float maxVal = arr[0];
  for (int i = 1; i < size; i++) {
    if (arr[i] > maxVal) maxVal = arr[i];
  }
  return maxVal;
}

float arrayMinFloat(float arr[], int size) {
  float minVal = arr[0];
  for (int i = 1; i < size; i++) {
    if (arr[i] < minVal) minVal = arr[i];
  }
  return minVal;
}
