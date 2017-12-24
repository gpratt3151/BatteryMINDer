/*
 * Based on delay sketch & http://arduino-info.wikispaces.com/ArduinoPower#4-8
 * Based on "Arrays" from Arduino IDE
 */

const long oneSecond = 1000;  // a second is a thousand milliseconds
const long tenSeconds = oneSecond * 5;
const long oneMinute = oneSecond * 60;
const long oneHour   = oneMinute * 60;
const long oneDay    = oneHour * 24;

/*-----( Import needed libraries )-----*/
/*-----( Declare Constants )-----*/
#define RELAY_ON 0
#define RELAY_OFF 1
/*-----( Declare objects )-----*/
/*-----( Declare Variables )-----*/
// #define Relay_1  2  // Arduino Digital I/O pin number
// #define Relay_2  12
// #define Relay_3  8
// #define Relay_4  7

int relayPins[] = {
  2, 12, 8, 7
};    // an array of pin number to which relays are attached
int pinCount = 4;  // the number of pins (i.e. the length of the array)

void setup()
{
  // the array elements are numbered from 0 to (pinCount - 1).
    // use a for loop to initialize each pin as an output:
  for (int thisPin = 0; thisPin < pinCount; thisPin++) {
    pinMode(relayPins[thisPin], OUTPUT);
  }
  
  //-------( Initialize Pins so relays are inactive at reset )----
  for (int thisPin = 0; thisPin < pinCount; thisPin++) {
    digitalWrite(relayPins[thisPin], RELAY_OFF);
  }  
  delay(4000); //Check that all relays are inactive at Reset
  
  Serial.begin(9600);

  for (int thisPin = 0; thisPin < pinCount; thisPin++) {
    Serial.print("Set Relay #");
    Serial.print(relayPins[thisPin]);
    Serial.println(" On");
    digitalWrite(relayPins[thisPin], RELAY_ON);
    Serial.println("On for 10 seconds");
    delay(tenSeconds);
    Serial.print("Set Relay #");
    Serial.print(relayPins[thisPin]);
    Serial.println(" Off");
    digitalWrite(relayPins[thisPin], RELAY_OFF);
    Serial.println("Delay 1 second");
    delay(oneSecond);
  }
}

void loop()
{
  for (int thisPin = 0; thisPin < pinCount; thisPin++) {
    Serial.print("Set Relay #");
    Serial.print(relayPins[thisPin]);
    Serial.println(" On");
    digitalWrite(relayPins[thisPin], RELAY_ON);
    Serial.println("On for 10 seconds");
    delay(oneHour);
    Serial.print("Set Relay #");
    Serial.print(relayPins[thisPin]);
    Serial.println(" Off");
    digitalWrite(relayPins[thisPin], RELAY_OFF);
    Serial.println("Delay 1 second");
    delay(oneSecond);
  }
}
