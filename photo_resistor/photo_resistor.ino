/* FSR testing sketch. 
 
Connect one end of FSR to 5V, the other end to Analog 0.
Then connect one end of a 10K resistor from Analog 0 to ground
Connect LED from pin 11 through a resistor to ground 
 
For more information see www.ladyada.net/learn/sensors/fsr.html */
 
int photoPin = 0; // FSR is connected to analog 0
int photoReading;      // the analog reading from the FSR resistor divider
 
void setup(void) {
  Serial.begin(57600);   // We'll send debugging information via the Serial monitor
}
 
void loop(void) {
  photoReading = analogRead(photoPin);
  Serial.print("Analog reading = ");
  Serial.println(photoReading);
  delay(100);
}
