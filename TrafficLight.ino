/* Blink without Delay
 
 Turns on and off a light emitting diode(LED) connected to a digital  
 pin, without using the delay() function.  This means that other code
 can run at the same time without being interrupted by the LED code.
 
 The circuit:
 * LED attached from pin 13 to ground.
 * Note: on most Arduinos, there is already an LED on the board
 that's attached to pin 13, so no hardware is needed for this example.
 
 
 created 2005
 by David A. Mellis
 modified 8 Feb 2010
 by Paul Stoffregen
 
 This example code is in the public domain.

 
 http://www.arduino.cc/en/Tutorial/BlinkWithoutDelay
 */

// constants won't change. Used here to 
// set pin numbers:
const int redPin =  10;      // the number of the LED pin
const int yellowPin = 11;
const int greenPin = 12;

// Variables will change:
int redState = LOW;             // ledState used to set the LED
int yellowState = LOW;
int greenState = LOW;
int micPin = A0;
int micValue = 0;
long previousMillis = 0;        // will store last time LED was updated

// the follow variables is a long because the time, measured in miliseconds,
// will quickly become a bigger number than can be stored in an int.
long interval = 1000;           // interval at which to blink (milliseconds)
int tracker = 1;

void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  // set the digital pin as output:
  pinMode(redPin, OUTPUT);      
  pinMode(yellowPin, OUTPUT);      
  pinMode(greenPin, OUTPUT);      
  Serial.println("Hello World!");
}

void loop()
{
  // here is where you'd put code that needs to be running all the time.

  // check to see if it's time to blink the LED; that is, if the 
  // difference between the current time and last time you blinked 
  // the LED is bigger than the interval at which you want to 
  // blink the LED.
  unsigned long currentMillis = millis();
/*  micValue = analogRead(micPin);
  Serial.println(micValue);
 
  if(micValue > 725){
     Serial.println("LOUD NOISES");
  } 
 */
  if(currentMillis - previousMillis > interval) {
    // save the last time you blinked the LED 
    previousMillis = currentMillis;   

    
    // if the LED is off turn it on and vice-versa:
    if (tracker == 1) {
      greenState = LOW;
      yellowState = LOW;
      redState = HIGH;      
      tracker += 1;
    }
    else if (tracker == 2){
      greenState = LOW;
      yellowState = HIGH;
      redState = LOW;
      tracker += 1;
    }
    else if (tracker == 3){
      greenState = HIGH;
      yellowState = LOW;
      redState = LOW;
      tracker = 1;
    }

    // set the LED with the ledState of the variable:
    digitalWrite(redPin, redState);
    digitalWrite(yellowPin, yellowState);
    digitalWrite(greenPin, greenState);    
  }
}

