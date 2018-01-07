/*
 * Based on delay sketch & http://arduino-info.wikispaces.com/ArduinoPower#4-8
 * Based on "Arrays" from Arduino IDE
 *
 * The Adafruit Trinket doesn't support serial communications so you must
 * comment out all references to serial communications.
 */

/*-----( Declare Constants )-----*/
const long oneSecond = 1000;  // a second is a thousand milliseconds
const long tenSeconds = oneSecond * 10;
const long thirtySeconds = oneSecond * 30;
const long oneMinute = oneSecond * 60;
const long oneHour   = oneMinute * 60;
const long oneDay    = oneHour * 24;

#define RELAY_ON 0
#define RELAY_OFF 1

#define Pulse_Counter 1  // Modify for chip. Uno = 13 / Trinket = 1

/*-----( Declare Variables )-----*/
/* 
 * Pinout for Adafruit Trinket (based on ATiny85)
 *  GPIO #0 - Digital READ/WRITE
 *  GPIO #1 - Digital READ/WRITE Connected to onboard LED
 *  GPIO #2 - Digital READ/WRITE
 *  GPIO #3 - Digital READ/WRITE
 *  GPIO #4 - Digital READ/WRITE
 * 
*/
// an array of pin number to which relays are attached
int relayPins[] = {
  // 2, 12, 8, 7  // Uncomment for Arduino UNO
  0, 2, 3, 4      // Uncomment for Adafruit Trinket
};    
int pinCount = 4;  // the number of pins (i.e. the length of the array)

/*-----( Setup - Runs once )-----*/
void setup()
{
  // Configure the pulse counter
  pinMode(Pulse_Counter, OUTPUT);
  digitalWrite(Pulse_Counter, LOW);

  // The array elements are numbered from 0 to (pinCount - 1).
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

  // Run through each relay 1 time so you know things are working
  // properly. Pause between each one to let things settle. The
  // BatteryMINDer will attempt to charge first thing so we give
  // it 30 seconds to see if it's going to go into "desulphation"
  // mode otherwise the battery needs charging.

  int printRelay = 1;  // for printing the relay number
  for (int thisPin = 0; thisPin < pinCount; thisPin++) {
    countPulse();
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

void countPulse () {
  digitalWrite(Pulse_Counter, HIGH);
  delay(100);
  digitalWrite(Pulse_Counter, LOW);
}
