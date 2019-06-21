#include <CapacitiveSensor.h>
CapacitiveSensor cs_7_8 = CapacitiveSensor(7,8); //10M Resistor between pins 7 and 8, you may also connect an antenna on pin 8
CapacitiveSensor cs_9_10 = CapacitiveSensor(9,10);
CapacitiveSensor cs_11_12 = CapacitiveSensor(11,12);

CapacitiveSensor sensors[] = {CapacitiveSensor(7,8), CapacitiveSensor(9,10)};
int sensorsSize = 2;

int sensorLimit = 40;
int sensorResolution = 50;

void setup() {
  for (int i = 0; i < sensorsSize; i++) {
    sensors[i].set_CS_AutocaL_Millis(0xFFFFFFFF);
  }
//  cs_7_8.set_CS_AutocaL_Millis(0xFFFFFFFF);
//  cs_10_11.set_CS_AutocaL_Millis(0xFFFFFFFF);
  Serial.begin(57600);
}

void loop() {
  CSread();
}

void CSread() {
  for (int i = 0; i < sensorsSize; i++) {
    long cs = sensors[i].capacitiveSensor(sensorResolution);
    int colorSwitcher = 0;
    if (cs > sensorLimit) {
      colorSwitcher = 1;
    }
    Serial.print(colorSwitcher);
    if (i < sensorsSize - 1) {
      Serial.print(",");
    }
  }
  Serial.println(",");
  delay(200);
//  long cs1 = cs_7_8.capacitiveSensor(sensorResolution); //a: Sensor resolution is set to 50
//  long cs2 = cs_9_10.capacitiveSensor(sensorResolution);
//  int colorSwitcher1 = 0;
//  int colorSwitcher2 = 0;
//  if (cs1 > sensorLimit) {
//    colorSwitcher1 = 1;
//  }
//  if (cs2 > sensorLimit) {
//    colorSwitcher2 = 1;
//  }
//  Serial.print(colorSwitcher1);
//  Serial.print(",");
//  Serial.print(colorSwitcher2);
//  Serial.println(",");
//  delay(200);
}

