#include <CapacitiveSensor.h>
CapacitiveSensor cs_7_8 = CapacitiveSensor(7,8); //10M Resistor between pins 7 and 8, you may also connect an antenna on pin 8

void setup() {
  cs_7_8.set_CS_AutocaL_Millis(0xFFFFFFFF);
  Serial.begin(57600);
}

void loop() {
  CSread();
}

void CSread() {
  long cs = cs_7_8.capacitiveSensor(40); //a: Sensor resolution is set to 80
  int colorSwitcher = 0;
  if (cs > 80) {
    //Serial.print("WE TOUCH?  ");
    //Serial.println(cs);
    colorSwitcher = 1;
  } else {
    //Serial.print("NO TOUCH?  ");
    //Serial.println(cs);
  }
  //Serial.print(cs);
  //Serial.print(" ");
  Serial.print(colorSwitcher);
  Serial.println(",");
  delay(100);
}

