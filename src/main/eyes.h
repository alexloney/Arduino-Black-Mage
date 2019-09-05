#ifndef __EYES_H__
#define __EYES_H__

#include <Adafruit_GFX.h>
#include <Adafruit_NeoMatrix.h>
#include <Adafruit_NeoPixel.h>

#define WIDTH 5
#define HEIGHT 8

#define LEFT_EYE 0
#define RIGHT_EYE 1

#define OFF this->eye->Color(0, 0, 0)
#define ORANGE this->eye->Color(255, 165, 0)
#define BLUE this->eye->Color(15, 139, 255)
#define RED this->eye->Color(255, 23, 23)

#define STATE_NORMAL 0
#define STATE_HAPPY 1
#define STATE_SAD 2
#define STATE_LAUGHING 3
#define STATE_ANGRY 4
#define STATE_VERYANGRY 5
#define STATE_SLEEPY 6
#define STATE_DEAD 7
#define STATE_HALF 8
#define STATE_HALF2 9
#define STATE_CLOSED 10

class Eye
{
  public:
    Eye(int type, int pin);
    ~Eye();

    int getState();

    void resetEye();
    void normalEye();
    void happyEye();
    void sadEye();
    void closedEye();
    void halfEye();
    void halfEye2();
    void laughingEye();
    void angryEye();
    void veryAngryEye();
    void sleepyEye();
    void deadEye();
    
  private:
    int eyeType;
    Adafruit_NeoMatrix *eye;
    int eyeState;
};


#endif
