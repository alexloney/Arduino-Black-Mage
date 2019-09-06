#include "eyes.h"

#include <string.h>
#include <Arduino.h>
#include <SPI.h>
#include "Adafruit_BLE.h"
#include "Adafruit_BluefruitLE_SPI.h"
#include "Adafruit_BluefruitLE_UART.h"

#include "BluefruitConfig.h"

#if SOFTWARE_SERIAL_AVAILABLE
  #include <SoftwareSerial.h>
#endif

#define FACTORYRESET_ENABLE         0
#define MINIMUM_FIRMWARE_VERSION    "0.6.6"
#define MODE_LED_BEHAVIOUR          "MODE"

#define LEFT_EYE_PIN 9
#define RIGHT_EYE_PIN 10

#define BUTTON_UP 5
#define BUTTON_DOWN 6
#define BUTTON_LEFT 7
#define BUTTON_RIGHT 8
#define BUTTON_1 1
#define BUTTON_2 2
#define BUTTON_3 3
#define BUTTON_4 4

unsigned long nextBlink = 0;
int currentEyeState = STATE_NORMAL;

Eye *leftEye;
Eye *rightEye;

Adafruit_BluefruitLE_UART ble(BLUEFRUIT_HWSERIAL_NAME, BLUEFRUIT_UART_MODE_PIN);

void error(const __FlashStringHelper*err) {
  Serial.println(err);
  while (1);
}

// function prototypes over in packetparser.cpp
uint8_t readPacket(Adafruit_BLE *ble, uint16_t timeout);
float parsefloat(uint8_t *buffer);
void printHex(const uint8_t * data, const uint32_t numBytes);

// the packet buffer
extern uint8_t packetbuffer[];

void setup() {
  randomSeed(analogRead(0));
  
  // while (!Serial);  // required for Flora & Micro
  delay(500);
  
  Serial.begin(115200);
  
  /* Initialise the module */
  Serial.print(F("Initialising the Bluefruit LE module: "));

  if ( !ble.begin(VERBOSE_MODE) )
  {
    error(F("Couldn't find Bluefruit, make sure it's in CoMmanD mode & check wiring?"));
  }
  Serial.println( F("OK!") );
  
  if ( FACTORYRESET_ENABLE )
  {
    /* Perform a factory reset to make sure everything is in a known state */
    Serial.println(F("Performing a factory reset: "));
    if ( ! ble.factoryReset() ){
      error(F("Couldn't factory reset"));
    }
  }

  /* Disable command echo from Bluefruit */
  ble.echo(false);

  Serial.println("Requesting Bluefruit info:");
  /* Print Bluefruit information */
  ble.info();

  Serial.println(F("Please use Adafruit Bluefruit LE app to connect in Controller mode"));
  Serial.println(F("Then activate/use the sensors, color picker, game controller, etc!"));
  Serial.println();

  ble.verbose(false);  // debug info is a little annoying after this point!

  /* Wait for connection */
  while (! ble.isConnected()) {
      delay(500);
  }

  Serial.println(F("******************************"));

  // LED Activity command is only supported from 0.6.6
  if ( ble.isVersionAtLeast(MINIMUM_FIRMWARE_VERSION) )
  {
    // Change Mode LED Activity
    Serial.println(F("Change LED activity to " MODE_LED_BEHAVIOUR));
    ble.sendCommandCheckOK("AT+HWModeLED=" MODE_LED_BEHAVIOUR);
  }

  // Set Bluefruit to DATA mode
  Serial.println( F("Switching to DATA mode!") );
  ble.setMode(BLUEFRUIT_MODE_DATA);

  Serial.println(F("******************************"));
  
  leftEye = new Eye(LEFT_EYE, LEFT_EYE_PIN);
  rightEye = new Eye(RIGHT_EYE, RIGHT_EYE_PIN);

  nextBlink = millis() + random(1000 * 90, 1000 * 120);
}

bool buttons[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};

void loop() {
  unsigned long currentTime = millis();
  uint8_t len = readPacket(&ble, BLE_READPACKET_TIMEOUT);

  if (packetbuffer[1] == 'B') {
    uint8_t buttnum = packetbuffer[2] - '0';
    bool pressed = packetbuffer[3] - '0';

    if (buttnum == BUTTON_RIGHT || 
        buttnum == BUTTON_LEFT ||
        buttnum == BUTTON_DOWN ||
        buttnum == BUTTON_UP)
    {
      buttons[BUTTON_UP] = 0;
      buttons[BUTTON_RIGHT] = 0;
      buttons[BUTTON_DOWN] = 0;
      buttons[BUTTON_LEFT] = 0;
    }
    
    if (pressed) {
      buttons[buttnum] = 1;
    }
    else {
      buttons[buttnum] = 0;
    }

    Serial.println(buttnum);
  }
  
  if (currentTime > nextBlink)
  {
    if (leftEye->getState() == STATE_NORMAL)
    {
      leftEye->closedEye();
      rightEye->closedEye();
      delay(150);
      leftEye->normalEye();
      rightEye->normalEye();
    }
    
    nextBlink = millis() + random(1000 * 90, 1000 * 120);
  }
  
  if (buttons[BUTTON_UP])
  {
    if (buttons[BUTTON_1])
    {
      leftEye->skepticalEye();
      rightEye->normalEye();
    }
    else if (buttons[BUTTON_2])
    {
      leftEye->suspiciousEye();
      rightEye->suspiciousEye();
    }
    else if (buttons[BUTTON_3])
    {
      leftEye->angryEye();
      rightEye->angryEye();
    }
    else if (buttons[BUTTON_4])
    {
      leftEye->veryAngryEye();
      rightEye->veryAngryEye();
    }
  }
  else if (buttons[BUTTON_RIGHT])
  {
    if (buttons[BUTTON_1])
    {
      leftEye->sadEye();
      rightEye->sadEye();
    }
    else if (buttons[BUTTON_2])
    {
      leftEye->verySadEye();
      rightEye->verySadEye();
    }
    else if (buttons[BUTTON_3])
    {
      leftEye->reallyEye();
      rightEye->reallyEye();
    }
    else if (buttons[BUTTON_4])
    {
      leftEye->closedEye();
      rightEye->closedEye();
    }
  }
  else if (buttons[BUTTON_LEFT])
  {
    if (buttons[BUTTON_1])
    {
      leftEye->happyEye();
      rightEye->happyEye();
    }
    else if (buttons[BUTTON_2])
    {
      leftEye->fullHappyEye();
      rightEye->fullHappyEye();
    }
    else if (buttons[BUTTON_3])
    {
      leftEye->happyEye();
      rightEye->normalEye();
    }
    else if (buttons[BUTTON_4])
    {
      leftEye->heartEye();
      rightEye->heartEye();
    }
  }
  else if (buttons[BUTTON_DOWN])
  {
    if (buttons[BUTTON_1])
    {
      leftEye->surpriseEye();
      rightEye->surpriseEye();
    }
    else if (buttons[BUTTON_2])
    {
      leftEye->laughingEye();
      rightEye->laughingEye();
    }
    else if (buttons[BUTTON_3])
    {
      leftEye->deadEye();
      rightEye->deadEye();
    }
    else if (buttons[BUTTON_4])
    {
      leftEye->noEye();
      rightEye->noEye();
    }
  }
  else
  {
    leftEye->normalEye();
    rightEye->normalEye();
  }
}
