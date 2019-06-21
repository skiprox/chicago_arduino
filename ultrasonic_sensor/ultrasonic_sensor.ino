const int pingPin1 = 10; // Trigger Pin of Ultrasonic Sensor 1
const int echoPin1 = 9; // Echo Pin of Ultrasonic Sensor 1
const int pingPin2 = 3; // Trigger Pin of Ultrasonic Sensor 2
const int echoPin2 = 11;

void setup() {
  Serial.begin(57600); // Starting Serial Terminal
}

void loop() {
  // The ultrasonic sensor 1
  long duration1, inches1, cm1;
  int serial1;
  pinMode(pingPin1, OUTPUT);
  digitalWrite(pingPin1, LOW);
  delayMicroseconds(10);
  digitalWrite(pingPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(pingPin1, LOW);
  pinMode(echoPin1, INPUT);
  duration1 = pulseIn(echoPin1, HIGH);
  inches1 = microsecondsToInches(duration1);
  cm1 = microsecondsToCentimeters(duration1);
  if (cm1 >= 150) {
    serial1 = 0;
  } else {
    serial1 = 1;
  }
  Serial.print(serial1);
//  Serial.print(",");
//  // The ultrasonic sensor 2
//  long duration2, inches2, cm2;
//  int serial2;
//  pinMode(pingPin2, OUTPUT);
//  digitalWrite(pingPin2, LOW);
//  delayMicroseconds(10);
//  digitalWrite(pingPin2, HIGH);
//  delayMicroseconds(10);
//  digitalWrite(pingPin2, LOW);
//  pinMode(echoPin2, INPUT);
//  duration2 = pulseIn(echoPin2, HIGH);
//  inches2 = microsecondsToInches(duration2);
//  cm2 = microsecondsToCentimeters(duration2);
//  if (cm2 >= 60) {
//    serial2 = 0;
//  } else {
//    serial2 = 1;
//  }
//  Serial.print(serial2);
  Serial.println(",");
  delay(250);
}

long microsecondsToInches(long microseconds) {
   return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds) {
   return microseconds / 29 / 2;
}
