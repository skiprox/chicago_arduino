

void setup() {
  // put your setup code here, to run once:
  Serial.begin(57600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int val = digitalRead(6);
  Serial.println(val);
  delay(100);
}
