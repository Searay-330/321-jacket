/*
 * Switch test program
 */

int leftSwitchPin = 5;
int rightSwitchPin = 6;
int sensorValue = 0;

int voltage = 165;

int blinks = 7;

int leftLED = 11;
int rightLED = 10;

void setup()                    // run once, when the sketch starts
{
  Serial.begin(9600);           // set up Serial library at 9600 bps
  pinMode(leftSwitchPin, INPUT_PULLUP);    // sets the digital pin as input to read switch
  pinMode(rightSwitchPin, INPUT_PULLUP);    // sets the digital pin as input to read switch
  analogWrite(leftLED, 0);
  analogWrite(rightLED, 0);
  
}


void loop()                     // run over and over again
{
 
  sensorValue = digitalRead(leftSwitchPin);
  Serial.print("left switch pin value = ");
  Serial.println(sensorValue);
  if (sensorValue == 0){
      // If button pushed, turn LED on
      for(int i = 0; i < blinks; ++i){
        analogWrite(leftLED,voltage);
        delay(500);
        analogWrite(leftLED,0);
        delay(500);
      }
      
   }
   analogWrite(leftLED, 0);
   sensorValue = digitalRead(rightSwitchPin);
   Serial.print("right switch pin value = ");
   Serial.println(sensorValue);
  if (sensorValue == 0){
      // If button pushed, turn LED on
      for(int i = 0; i < blinks; ++i){
        analogWrite(rightLED,voltage);
        delay(500);
        analogWrite(rightLED,0);
        delay(500);
      }
      
   }
   analogWrite(rightLED, 0);
}
