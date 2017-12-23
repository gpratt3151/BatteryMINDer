/*
 * Based on delay sketch & http://arduino-info.wikispaces.com/ArduinoPower#4-8
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
#define Relay_1  2  // Arduino Digital I/O pin number
#define Relay_2  12
#define Relay_3  8
#define Relay_4  7

void setup()
{
  //-------( Initialize Pins so relays are inactive at reset )----
  digitalWrite(Relay_1, RELAY_OFF);
  digitalWrite(Relay_2, RELAY_OFF);
  digitalWrite(Relay_3, RELAY_OFF);
  digitalWrite(Relay_4, RELAY_OFF);

  //---( THEN set pins as outputs )---- 
  pinMode(Relay_1, OUTPUT);
  pinMode(Relay_2, OUTPUT);
  pinMode(Relay_3, OUTPUT);
  pinMode(Relay_4, OUTPUT);
  delay(4000); //Check that all relays are inactive at Reset
  
  Serial.begin(9600);

  Serial.println("Set Relay #1 On");
  digitalWrite(Relay_1, RELAY_ON);
  Serial.println("On for 10 seconds");
  delay(tenSeconds);
  Serial.println("Set Relay #1 Off");
  digitalWrite(Relay_1, RELAY_OFF);
  Serial.println("Delay 1 second");
  delay(oneSecond);
  
  Serial.println("Set Relay #2 On");
  digitalWrite(Relay_2, RELAY_ON);
  Serial.println("On for 10 seconds");
  delay(tenSeconds);
  Serial.println("Set Relay #2 Off");
  digitalWrite(Relay_2, RELAY_OFF);
  Serial.println("Delay 1 second");
  delay(oneSecond);

  Serial.println("Set Relay #3 On");
  digitalWrite(Relay_3, RELAY_ON);
  Serial.println("On for 10 seconds");
  delay(tenSeconds);
  Serial.println("Set Relay #3 Off");
  digitalWrite(Relay_3, RELAY_OFF);
  Serial.println("Delay 1 second");
  delay(oneSecond);

  Serial.println("Set Relay #4 On");
  digitalWrite(Relay_4, RELAY_ON);
  Serial.println("On for 10 seconds");
  delay(tenSeconds);
  Serial.println("Set Relay #4 Off");
  digitalWrite(Relay_4, RELAY_OFF);
  Serial.println("Delay 1 second");
  delay(oneSecond); 
}

void loop()
{
  Serial.println("Set Relay #1 On");
  digitalWrite(Relay_1, RELAY_ON);
  Serial.println("On for 1 Hour");
  delay(oneHour);
  Serial.println("Set Relay #1 Off");
  digitalWrite(Relay_1, RELAY_OFF);
  Serial.println("Delay 1 second");
  delay(oneSecond);
  
  Serial.println("Set Relay #2 On");
  digitalWrite(Relay_2, RELAY_ON);
  Serial.println("On for 1 Hour");
  delay(oneHour);
  Serial.println("Set Relay #2 Off");
  digitalWrite(Relay_2, RELAY_OFF);
  Serial.println("Delay 1 second");
  delay(oneSecond);

  Serial.println("Set Relay #3 On");
  digitalWrite(Relay_3, RELAY_ON);
  Serial.println("On for 1 Hour");
  delay(oneHour);
  Serial.println("Set Relay #3 Off");
  digitalWrite(Relay_3, RELAY_OFF);
  Serial.println("Delay 1 second");
  delay(oneSecond);

  Serial.println("Set Relay #4 On");
  digitalWrite(Relay_4, RELAY_ON);
  Serial.println("On for 1 Hour");
  delay(oneHour);
  Serial.println("Set Relay #4 Off");
  digitalWrite(Relay_4, RELAY_OFF);
  Serial.println("Delay 1 second");
  delay(oneSecond);
}
