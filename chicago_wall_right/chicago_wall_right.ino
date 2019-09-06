#include <CapacitiveSensor.h>
// CapacitiveSensor cs_7_8 = CapacitiveSensor(7,8); //10M Resistor between pins 7 and 8, you may also connect an antenna on pin 8

CapacitiveSensor sensors[] = {
  CapacitiveSensor(2,3),
  CapacitiveSensor(4,5),
  CapacitiveSensor(6,7),
  CapacitiveSensor(8,9),
  CapacitiveSensor(10,11),
  CapacitiveSensor(12,13),
  CapacitiveSensor(22,23),
  CapacitiveSensor(24,25),
  CapacitiveSensor(26,27)
};
int numSensors = 9;

int sensorLimit = 90;
int sensorResolution = 50;

void setup() {
  for (int i = 0; i < numSensors; i++) {
    sensors[i].set_CS_AutocaL_Millis(0xFFFFFFFF);
  }
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
    if (i < numSensors - 1) {
      Serial.print(",");
    }
  }
  Serial.println(",");
  delay(200);
}

