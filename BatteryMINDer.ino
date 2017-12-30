/*
 * Based on delay sketch & http://arduino-info.wikispaces.com/ArduinoPower#4-8
 * Based on "Arrays" from Arduino IDE
 */

const long oneSecond = 1000;  // a second is a thousand milliseconds
const long tenSeconds = oneSecond * 10;
const long thirtySeconds = oneSecond * 30;
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
  // 2, 12, 8, 7  // Uncomment for Arduino UNO
  0, 2, 3, 4  // Uncomment for Adafruit Trinket
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
  delay(3000); //Check that all relays are inactive at Reset
  
  // Serial.begin(9600);

  int printRelay = 1;  // for printing the relay number
  for (int thisPin = 0; thisPin < pinCount; thisPin++) {
    // Serial.print("Relay_# [Pin] STATUS");
    // Serial.print(printRelay);
    // Serial.print(" [");
    // Serial.print(relayPins[thisPin]);
    // Serial.print("] ");
    digitalWrite(relayPins[thisPin], RELAY_ON);
    // Serial.println("ON for 30 seconds");
    delay(thirtySeconds);

    // Serial.print("Relay_# [Pin] STATUS");
    // Serial.print(printRelay);
    // Serial.print(" [");
    // Serial.print(relayPins[thisPin]);
    // Serial.print("] ");
    digitalWrite(relayPins[thisPin], RELAY_OFF);
    // Serial.println("OFF");

    // Serial.println("Settle for 1 second");
    delay(oneSecond);

    printRelay++;
  }
}

void loop()
{
  int printRelay = 1;
  for (int thisPin = 0; thisPin < pinCount; thisPin++) {
    // Serial.print("Relay_# [Pin] STATUS");
    // Serial.print(printRelay);
    // Serial.print(" [");
    // Serial.print(relayPins[thisPin]);
    // Serial.print("] ");
    digitalWrite(relayPins[thisPin], RELAY_ON);
    // Serial.println("ON for 30 seconds");
    delay(oneHour);

    // Serial.print("Relay_# [Pin] STATUS");
    // Serial.print(printRelay);
    // Serial.print(" [");
    // Serial.print(relayPins[thisPin]);
    // Serial.print("] ");
    digitalWrite(relayPins[thisPin], RELAY_OFF);
    // Serial.println("OFF");

    // Serial.println("Settle for 1 second");
    delay(oneSecond);

    printRelay++;
  }
}
