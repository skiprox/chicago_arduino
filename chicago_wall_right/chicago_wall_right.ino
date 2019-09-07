#include <CapacitiveSensor.h>

// Capacitive Sensor Stuff
CapacitiveSensor sensors[] = {
  CapacitiveSensor(2,3),
  CapacitiveSensor(4,5),
  CapacitiveSensor(6,7),
  CapacitiveSensor(8,9),
  CapacitiveSensor(10,11),
  CapacitiveSensor(12,13),
  CapacitiveSensor(A1,A0),
  CapacitiveSensor(A3,A2),
  CapacitiveSensor(A5,A4)
};
int numSensors = 9;
int sensorLimit = 90;
int sensorResolution = 50;

// Button Reset Stuff
int buttonPin = 50;
int buttonState = 1;

void setup() {
  for (int i = 0; i < numSensors; i++) {
    sensors[i].set_CS_AutocaL_Millis(0xFFFFFFFF);
  }
  pinMode(buttonPin, INPUT_PULLUP);
  Serial.begin(57600);
}

void loop() {
  CSread();
}

void CSread() {
  for (int i = 0; i < numSensors; i++) {
    long cs = sensors[i].capacitiveSensor(sensorResolution);
    int colorSwitcher = 0;
    if (cs > sensorLimit) {
      colorSwitcher = 1;
    }
    Serial.print(colorSwitcher);
    Serial.print(",");
  }
  buttonState = digitalRead(buttonPin);
  Serial.print(buttonState);
  Serial.println(",");
  delay(200);
}

