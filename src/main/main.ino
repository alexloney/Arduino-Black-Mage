#include <Adafruit_Keypad.h>

#include "eyes.h"

#define LEFT_EYE_PIN 6
#define RIGHT_EYE_PIN 7

const byte NUMPAD_ROWS = 1;
const byte NUMPAD_COLS = 4;
char keys[NUMPAD_ROWS][NUMPAD_COLS] = {
  {'1', '2', '3', '4'}
};
bool keysPressed[NUMPAD_COLS] = {0, 0, 0, 0};
byte rowPins[NUMPAD_ROWS] = {9};
byte colPins[NUMPAD_COLS] = {10, 11, 12, 13};

unsigned long lastEyeChange;
int currentEyeState = STATE_NORMAL;
char currentKey = '-';

Adafruit_Keypad customKeypad = Adafruit_Keypad(makeKeymap(keys), rowPins, colPins, NUMPAD_ROWS, NUMPAD_COLS);

Eye *leftEye;
Eye *rightEye;

// the setup routine runs once when you press reset:
void setup() {

  // If serial output is needed for debugging, uncomment the below line.
  // Serial.begin(9600);

  // Create instances of the eye objects for use later
  leftEye = new Eye(LEFT_EYE, LEFT_EYE_PIN);
  rightEye = new Eye(RIGHT_EYE, RIGHT_EYE_PIN);

  customKeypad.begin();

  // Mark the current time as the last time the eyes were blinked
  lastEyeChange = millis();
}
 
// the loop routine runs over and over again forever:
void loop() {

  // Get the current time for use with eye blink
  unsigned long currentTime = millis();

  // Get the keypad signals
  customKeypad.tick();
  while(customKeypad.available()){
    keypadEvent e = customKeypad.read();

    // I originally had a bit more logic here to keep an array of the key states
    // but after testing, the keypad can only have a single button pressed at any given time.
    // Thus I only need to keep track of a single character.
    if (e.bit.EVENT == KEY_JUST_PRESSED)
      currentKey = (char)e.bit.KEY;
    else
      currentKey = '-';

    // Serial.print((char)e.bit.KEY);
    // if(e.bit.EVENT == KEY_JUST_PRESSED) Serial.println(" pressed");
    // else if(e.bit.EVENT == KEY_JUST_RELEASED) Serial.println(" released");
  }

  // Check for the last changed time, if it has been over 4 seconds, check the state of the left eye
  // (only the left eye, because both eyes have the same state). If the state is normal, we'll cause
  // the eye to blink. Either way, reset the timer.
  if (currentTime - lastEyeChange > 4000)
  {
    if (leftEye->getState() == STATE_NORMAL)
    {
      leftEye->closedEye();
      rightEye->closedEye();
      delay(150);
      leftEye->normalEye();
      rightEye->normalEye();
    }
    lastEyeChange = millis();
  }
  else
  {
    // Check the key state and change the eye state depending on the key state. If no key state is 
    // selected, revert back to the default state.
    if (currentKey == '1')
    {
      leftEye->happyEye();
      rightEye->happyEye();
    }
    else if (currentKey == '2')
    {
      leftEye->laughingEye();
      rightEye->laughingEye();
    }
    else if (currentKey == '3')
    {
      leftEye->sadEye();
      rightEye->sadEye();
    }
    else if (currentKey == '4')
    {
      leftEye->deadEye();
      rightEye->deadEye();
    }
    else
    {
      leftEye->normalEye();
      rightEye->normalEye();
    }
  }
}
