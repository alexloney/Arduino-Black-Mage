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
#define STATE_FULL_HAPPY 11
#define STATE_SKEPTICAL 12
#define STATE_SUSPICIOUS 13
#define STATE_REALLY 14
#define STATE_SURPRISE 15
#define STATE_NO_EYE 16

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
    void verySadEye();
    void closedEye();
    void laughingEye();
    void angryEye();
    void veryAngryEye();
    void sleepyEye();
    void deadEye();
    void heartEye();
    void skepticalEye();
    void suspiciousEye();
    void reallyEye();
    void fullHappyEye();
    void surpriseEye();
    void noEye();

    void displayPattern(const char p[HEIGHT][WIDTH]);
    
  private:
    int eyeType;
    Adafruit_NeoMatrix *eye;
    int eyeState;
};


#endif
