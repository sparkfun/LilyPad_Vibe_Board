/*
  LilyPad Vibe Board: Button Feedback
  Written by: Ho Yun "Bobby" Chan
  @ SparkFun Electronics
  Date: 1/14/2019
  https://www.sparkfun.com/products/11008

  The main code checks for a button press. If there is a button press,
  the Arduino turns on the LilyPad Vibe Board for haptic feedback.
  For a visual cue, the LED will turn on too. If not, the LED and
  motor will remain off.
*/

const int motorPin = 10;     // motor connected to PWM pin 10
const int button1Pin = A4;  // pushbutton 1 pin
const int ledPin =  13;     // LED pin

int button1State;  //check state of button press

void setup() {
  //Serial.begin(9600); //setup serial monitor, uncomment Serial.print()'s to debug
  //Serial.println("Begin LilyPad Vibe Motor Tests");

  pinMode(button1Pin, INPUT_PULLUP);//set internal pull up for button
  pinMode(ledPin, OUTPUT); //visual feedback


  //Quick Test 1: Check If LED and Motor Can Turn On
  
  //Serial.println("Turn LilyPad Vibe Motor And LED ON");
  //digitalWrite(ledPin, HIGH);  // turn the LED on
  analogWrite(motorPin, 255);  //turn motor
  delay(300);
  
  //Serial.println("Turn LilyPad Vibe Motor And LED OFF");
  //digitalWrite(ledPin, LOW);  // turn the LED off
  analogWrite(motorPin, 0);   //turn motor off
  delay(300);

  //Quick Test 2: Check Intensity of Motor (turns on at about 130)
  // fade in from min to max in increments of 5 points:
  for (int fadeValue = 0 ; fadeValue <= 255; fadeValue += 5) {
    // sets the value (range from 0 to 255):
    analogWrite(motorPin, fadeValue);
    //Serial.print("LilyPad Vibe Motor Intensity = ");
    //Serial.println(fadeValue);
    
    // wait for 100 milliseconds to observe motor
    delay(100);
  }
  // fade out from max to min in increments of 5 points:
  for (int fadeValue = 255 ; fadeValue >= 0; fadeValue -= 5) {
    // sets the value (range from 0 to 255):
    analogWrite(motorPin, fadeValue);
    //Serial.print("LilyPad Vibe Motor Intensity = ");
    //Serial.println(fadeValue);
    
    // wait for 100 milliseconds to observe motor
    delay(100);
  }

}

void loop() {
  // Here we'll read the current pushbutton states into
  // a variable:

  // Remember that if the button is being pressed, it will be
  // connected to GND. If the button is not being pressed,
  // the pullup resistor will connect it to Vcc.

  // So the state will be LOW when it is being pressed,
  // and HIGH when it is not being pressed.

  // Now we'll use those states to control the LED.
  // Here's what we want to do:

  button1State = digitalRead(button1Pin);

  if (button1State == LOW)  // if we're pushing button 1
  {
    //Serial.println("Button has been pressed, turn LilyPad Vibe Motor And LED ON");
    digitalWrite(ledPin, HIGH);  // turn the LED on
    analogWrite(motorPin, 255);  //turn motor on
    delay(300);                  //slight delay for feedback
  }
  else
  {
    digitalWrite(ledPin, LOW);  // turn the LED
    analogWrite(motorPin, 0);   //turn motor off
    delay(300);
  }
}
