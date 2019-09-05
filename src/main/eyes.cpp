#include "eyes.h"

Eye::Eye(int type, int pin)
{
  this->eye = new Adafruit_NeoMatrix(
    WIDTH, // Width of matrix
    HEIGHT, // Height of matrix
    pin, // Pin number of matrix
    NEO_MATRIX_TOP     + NEO_MATRIX_RIGHT +
    NEO_MATRIX_COLUMNS + NEO_MATRIX_PROGRESSIVE,
    NEO_GRB            + NEO_KHZ800);

  this->eye->begin();
  this->eye->setBrightness(30);
  
  this->eyeType = type;
}

Eye::~Eye()
{
  delete eye;
}

int Eye::getState()
{
  return this->eyeState;
}

void Eye::resetEye()
{
  // Turn off all pixels
  for (int i = 0; i < WIDTH; ++i)
    for (int j = 0; j < HEIGHT; ++j)
      this->eye->drawPixel(i, j, OFF);
}

void Eye::normalEye()
{
  this->resetEye();
  
  this->eye->drawPixel(1, 0, ORANGE);
  this->eye->drawPixel(2, 0, ORANGE);
  this->eye->drawPixel(3, 0, ORANGE);
  
  this->eye->drawPixel(0, 1, ORANGE);
  this->eye->drawPixel(1, 1, ORANGE);
  this->eye->drawPixel(2, 1, ORANGE);
  this->eye->drawPixel(3, 1, ORANGE);
  this->eye->drawPixel(4, 1, ORANGE);
  
  this->eye->drawPixel(0, 2, ORANGE);
  this->eye->drawPixel(1, 2, ORANGE);
  this->eye->drawPixel(2, 2, ORANGE);
  this->eye->drawPixel(3, 2, ORANGE);
  this->eye->drawPixel(4, 2, ORANGE);
  
  this->eye->drawPixel(0, 3, ORANGE);
  this->eye->drawPixel(1, 3, ORANGE);
  this->eye->drawPixel(2, 3, ORANGE);
  this->eye->drawPixel(3, 3, ORANGE);
  this->eye->drawPixel(4, 3, ORANGE);
  
  this->eye->drawPixel(0, 4, ORANGE);
  this->eye->drawPixel(1, 4, ORANGE);
  this->eye->drawPixel(2, 4, ORANGE);
  this->eye->drawPixel(3, 4, ORANGE);
  this->eye->drawPixel(4, 4, ORANGE);
  
  this->eye->drawPixel(0, 5, ORANGE);
  this->eye->drawPixel(1, 5, ORANGE);
  this->eye->drawPixel(2, 5, ORANGE);
  this->eye->drawPixel(3, 5, ORANGE);
  this->eye->drawPixel(4, 5, ORANGE);
  
  this->eye->drawPixel(0, 6, ORANGE);
  this->eye->drawPixel(1, 6, ORANGE);
  this->eye->drawPixel(2, 6, ORANGE);
  this->eye->drawPixel(3, 6, ORANGE);
  this->eye->drawPixel(4, 6, ORANGE);
  
  this->eye->drawPixel(1, 7, ORANGE);
  this->eye->drawPixel(2, 7, ORANGE);
  this->eye->drawPixel(3, 7, ORANGE);

  this->eyeState = STATE_NORMAL;
  this->eye->show();
}

void Eye::happyEye()
{
  this->resetEye();

  this->eye->drawPixel(1, 1, ORANGE);
  this->eye->drawPixel(2, 1, ORANGE);
  this->eye->drawPixel(3, 1, ORANGE);

  this->eye->drawPixel(0, 2, ORANGE);
  this->eye->drawPixel(4, 2, ORANGE);

  this->eyeState = STATE_HAPPY;
  this->eye->show();
}

void Eye::sadEye()
{
  this->resetEye();
  
  if (this->eyeType == LEFT_EYE)
  {
    this->eye->drawPixel(0, 0, ORANGE);
    
    this->eye->drawPixel(0, 1, ORANGE);
    this->eye->drawPixel(1, 1, ORANGE);
    
    this->eye->drawPixel(0, 2, ORANGE);
    this->eye->drawPixel(1, 2, ORANGE);
    this->eye->drawPixel(2, 2, ORANGE);
    
    this->eye->drawPixel(0, 3, ORANGE);
    this->eye->drawPixel(1, 3, ORANGE);
    this->eye->drawPixel(2, 3, ORANGE);
    this->eye->drawPixel(3, 3, ORANGE);
    
    this->eye->drawPixel(0, 4, ORANGE);
    this->eye->drawPixel(1, 4, ORANGE);
    this->eye->drawPixel(2, 4, ORANGE);
    this->eye->drawPixel(3, 4, ORANGE);
    this->eye->drawPixel(4, 4, ORANGE);
    
    this->eye->drawPixel(0, 5, ORANGE);
    this->eye->drawPixel(1, 5, ORANGE);
    this->eye->drawPixel(2, 5, ORANGE);
    this->eye->drawPixel(3, 5, ORANGE);
    this->eye->drawPixel(4, 5, ORANGE);
    
    this->eye->drawPixel(0, 6, BLUE);
    this->eye->drawPixel(1, 6, BLUE);
    this->eye->drawPixel(2, 6, BLUE);
    this->eye->drawPixel(3, 6, BLUE);
    this->eye->drawPixel(4, 6, BLUE);
    
    this->eye->drawPixel(1, 7, BLUE);
    this->eye->drawPixel(2, 7, BLUE);
    this->eye->drawPixel(3, 7, BLUE);
  }
  else if (this->eyeType == RIGHT_EYE)
  {
    this->eye->drawPixel(4, 0, ORANGE);
    
    this->eye->drawPixel(3, 1, ORANGE);
    this->eye->drawPixel(4, 1, ORANGE);
    
    this->eye->drawPixel(2, 2, ORANGE);
    this->eye->drawPixel(3, 2, ORANGE);
    this->eye->drawPixel(4, 2, ORANGE);
    
    this->eye->drawPixel(1, 3, ORANGE);
    this->eye->drawPixel(2, 3, ORANGE);
    this->eye->drawPixel(3, 3, ORANGE);
    this->eye->drawPixel(4, 3, ORANGE);
    
    this->eye->drawPixel(0, 4, ORANGE);
    this->eye->drawPixel(1, 4, ORANGE);
    this->eye->drawPixel(2, 4, ORANGE);
    this->eye->drawPixel(3, 4, ORANGE);
    this->eye->drawPixel(4, 4, ORANGE);
    
    this->eye->drawPixel(0, 5, ORANGE);
    this->eye->drawPixel(1, 5, ORANGE);
    this->eye->drawPixel(2, 5, ORANGE);
    this->eye->drawPixel(3, 5, ORANGE);
    this->eye->drawPixel(4, 5, ORANGE);
    
    this->eye->drawPixel(0, 6, BLUE);
    this->eye->drawPixel(1, 6, BLUE);
    this->eye->drawPixel(2, 6, BLUE);
    this->eye->drawPixel(3, 6, BLUE);
    this->eye->drawPixel(4, 6, BLUE);
    
    this->eye->drawPixel(1, 7, BLUE);
    this->eye->drawPixel(2, 7, BLUE);
    this->eye->drawPixel(3, 7, BLUE);
  }

  this->eyeState = STATE_SAD;
  this->eye->show();
}

void Eye::closedEye()
{
  this->resetEye();

  this->eye->drawPixel(0, 3, ORANGE);
  this->eye->drawPixel(1, 3, ORANGE);
  this->eye->drawPixel(2, 3, ORANGE);
  this->eye->drawPixel(3, 3, ORANGE);
  this->eye->drawPixel(4, 3, ORANGE);

  this->eyeState = STATE_CLOSED;
  this->eye->show();
}

void Eye::halfEye()
{
  this->resetEye();

  this->eye->drawPixel(1, 0, ORANGE);
  this->eye->drawPixel(2, 0, ORANGE);
  this->eye->drawPixel(3, 0, ORANGE);
  
  this->eye->drawPixel(0, 1, ORANGE);
  this->eye->drawPixel(1, 1, ORANGE);
  this->eye->drawPixel(2, 1, ORANGE);
  this->eye->drawPixel(3, 1, ORANGE);
  this->eye->drawPixel(4, 1, ORANGE);
  
  this->eye->drawPixel(0, 2, ORANGE);
  this->eye->drawPixel(1, 2, ORANGE);
  this->eye->drawPixel(2, 2, ORANGE);
  this->eye->drawPixel(3, 2, ORANGE);
  this->eye->drawPixel(4, 2, ORANGE);
  
  this->eye->drawPixel(0, 3, ORANGE);
  this->eye->drawPixel(1, 3, ORANGE);
  this->eye->drawPixel(2, 3, ORANGE);
  this->eye->drawPixel(3, 3, ORANGE);
  this->eye->drawPixel(4, 3, ORANGE);

  this->eyeState = STATE_HALF;
  this->eye->show();
}

void Eye::halfEye2()
{
  this->resetEye();

  if (eye == LEFT_EYE)
  {
    this->eye->drawPixel(0, 0, ORANGE);
    this->eye->drawPixel(1, 0, ORANGE);
    this->eye->drawPixel(2, 0, ORANGE);
    this->eye->drawPixel(3, 0, ORANGE);
    
    this->eye->drawPixel(0, 1, ORANGE);
    this->eye->drawPixel(1, 1, ORANGE);
    this->eye->drawPixel(2, 1, ORANGE);
    this->eye->drawPixel(3, 1, ORANGE);
    this->eye->drawPixel(4, 1, ORANGE);
    
    this->eye->drawPixel(0, 2, ORANGE);
    this->eye->drawPixel(1, 2, ORANGE);
    this->eye->drawPixel(2, 2, ORANGE);
    this->eye->drawPixel(3, 2, ORANGE);
    this->eye->drawPixel(4, 2, ORANGE);
  }
  else if (eye == RIGHT_EYE)
  {
    this->eye->drawPixel(1, 0, ORANGE);
    this->eye->drawPixel(2, 0, ORANGE);
    this->eye->drawPixel(3, 0, ORANGE);
    this->eye->drawPixel(4, 0, ORANGE);
    
    this->eye->drawPixel(0, 1, ORANGE);
    this->eye->drawPixel(1, 1, ORANGE);
    this->eye->drawPixel(2, 1, ORANGE);
    this->eye->drawPixel(3, 1, ORANGE);
    this->eye->drawPixel(4, 1, ORANGE);
    
    this->eye->drawPixel(0, 2, ORANGE);
    this->eye->drawPixel(1, 2, ORANGE);
    this->eye->drawPixel(2, 2, ORANGE);
    this->eye->drawPixel(3, 2, ORANGE);
    this->eye->drawPixel(4, 2, ORANGE);
  }

  this->eyeState = STATE_HALF2;
  this->eye->show();
}

void Eye::laughingEye()
{
  this->resetEye();

  if (this->eyeType == LEFT_EYE)
  {
    this->eye->drawPixel(3, 0, ORANGE);
    this->eye->drawPixel(2, 1, ORANGE);
    this->eye->drawPixel(1, 2, ORANGE);
    this->eye->drawPixel(0, 3, ORANGE);
    this->eye->drawPixel(1, 4, ORANGE);
    this->eye->drawPixel(2, 5, ORANGE);
    this->eye->drawPixel(3, 6, ORANGE);
  }
  else if (this->eyeType == RIGHT_EYE)
  {
    this->eye->drawPixel(1, 0, ORANGE);
    this->eye->drawPixel(2, 1, ORANGE);
    this->eye->drawPixel(3, 2, ORANGE);
    this->eye->drawPixel(4, 3, ORANGE);
    this->eye->drawPixel(3, 4, ORANGE);
    this->eye->drawPixel(2, 5, ORANGE);
    this->eye->drawPixel(1, 6, ORANGE);
  }
  
  this->eyeState = STATE_LAUGHING;
  this->eye->show();
}

void Eye::angryEye()
{
  this->resetEye();

  if (this->eyeType == LEFT_EYE)
  {
    this->eye->drawPixel(4, 0, ORANGE);
    
    this->eye->drawPixel(3, 1, ORANGE);
    this->eye->drawPixel(4, 1, ORANGE);
    
    this->eye->drawPixel(2, 2, ORANGE);
    this->eye->drawPixel(3, 2, ORANGE);
    this->eye->drawPixel(4, 2, ORANGE);
    
    this->eye->drawPixel(1, 3, ORANGE);
    this->eye->drawPixel(2, 3, ORANGE);
    this->eye->drawPixel(3, 3, ORANGE);
    this->eye->drawPixel(4, 3, ORANGE);
    
    this->eye->drawPixel(0, 4, ORANGE);
    this->eye->drawPixel(1, 4, ORANGE);
    this->eye->drawPixel(2, 4, ORANGE);
    this->eye->drawPixel(3, 4, ORANGE);
    this->eye->drawPixel(4, 4, ORANGE);
    
    this->eye->drawPixel(0, 5, ORANGE);
    this->eye->drawPixel(1, 5, ORANGE);
    this->eye->drawPixel(2, 5, ORANGE);
    this->eye->drawPixel(3, 5, ORANGE);
    this->eye->drawPixel(4, 5, ORANGE);
    
    this->eye->drawPixel(0, 6, ORANGE);
    this->eye->drawPixel(1, 6, ORANGE);
    this->eye->drawPixel(2, 6, ORANGE);
    this->eye->drawPixel(3, 6, ORANGE);
    this->eye->drawPixel(4, 6, ORANGE);
    
    this->eye->drawPixel(1, 7, ORANGE);
    this->eye->drawPixel(2, 7, ORANGE);
    this->eye->drawPixel(3, 7, ORANGE);
  }
  else if (this->eyeType == RIGHT_EYE)
  {
    this->eye->drawPixel(0, 0, ORANGE);
    
    this->eye->drawPixel(0, 1, ORANGE);
    this->eye->drawPixel(1, 1, ORANGE);
    
    this->eye->drawPixel(0, 2, ORANGE);
    this->eye->drawPixel(1, 2, ORANGE);
    this->eye->drawPixel(2, 2, ORANGE);
    
    this->eye->drawPixel(0, 3, ORANGE);
    this->eye->drawPixel(1, 3, ORANGE);
    this->eye->drawPixel(2, 3, ORANGE);
    this->eye->drawPixel(3, 3, ORANGE);
    
    this->eye->drawPixel(0, 4, ORANGE);
    this->eye->drawPixel(1, 4, ORANGE);
    this->eye->drawPixel(2, 4, ORANGE);
    this->eye->drawPixel(3, 4, ORANGE);
    this->eye->drawPixel(4, 4, ORANGE);
    
    this->eye->drawPixel(0, 5, ORANGE);
    this->eye->drawPixel(1, 5, ORANGE);
    this->eye->drawPixel(2, 5, ORANGE);
    this->eye->drawPixel(3, 5, ORANGE);
    this->eye->drawPixel(4, 5, ORANGE);
    
    this->eye->drawPixel(0, 6, ORANGE);
    this->eye->drawPixel(1, 6, ORANGE);
    this->eye->drawPixel(2, 6, ORANGE);
    this->eye->drawPixel(3, 6, ORANGE);
    this->eye->drawPixel(4, 6, ORANGE);
    
    this->eye->drawPixel(1, 7, ORANGE);
    this->eye->drawPixel(2, 7, ORANGE);
    this->eye->drawPixel(3, 7, ORANGE);
  }
  
  this->eyeState = STATE_ANGRY;
  this->eye->show();
}

void Eye::veryAngryEye()
{
  this->resetEye();

  if (this->eyeType == LEFT_EYE)
  {
    this->eye->drawPixel(4, 0, RED);
    
    this->eye->drawPixel(3, 1, RED);
    this->eye->drawPixel(4, 1, RED);
    
    this->eye->drawPixel(2, 2, RED);
    this->eye->drawPixel(3, 2, RED);
    this->eye->drawPixel(4, 2, RED);
    
    this->eye->drawPixel(1, 3, RED);
    this->eye->drawPixel(2, 3, RED);
    this->eye->drawPixel(3, 3, RED);
    this->eye->drawPixel(4, 3, RED);
    
    this->eye->drawPixel(0, 4, RED);
    this->eye->drawPixel(1, 4, RED);
    this->eye->drawPixel(2, 4, RED);
    this->eye->drawPixel(3, 4, RED);
    this->eye->drawPixel(4, 4, RED);
    
    this->eye->drawPixel(0, 5, RED);
    this->eye->drawPixel(1, 5, RED);
    this->eye->drawPixel(2, 5, RED);
    this->eye->drawPixel(3, 5, RED);
    this->eye->drawPixel(4, 5, RED);
    
    this->eye->drawPixel(0, 6, RED);
    this->eye->drawPixel(1, 6, RED);
    this->eye->drawPixel(2, 6, RED);
    this->eye->drawPixel(3, 6, RED);
    this->eye->drawPixel(4, 6, RED);
    
    this->eye->drawPixel(1, 7, RED);
    this->eye->drawPixel(2, 7, RED);
    this->eye->drawPixel(3, 7, RED);
  }
  else if (this->eyeType == RIGHT_EYE)
  {
    this->eye->drawPixel(0, 0, RED);
    
    this->eye->drawPixel(0, 1, RED);
    this->eye->drawPixel(1, 1, RED);
    
    this->eye->drawPixel(0, 2, RED);
    this->eye->drawPixel(1, 2, RED);
    this->eye->drawPixel(2, 2, RED);
    
    this->eye->drawPixel(0, 3, RED);
    this->eye->drawPixel(1, 3, RED);
    this->eye->drawPixel(2, 3, RED);
    this->eye->drawPixel(3, 3, RED);
    
    this->eye->drawPixel(0, 4, RED);
    this->eye->drawPixel(1, 4, RED);
    this->eye->drawPixel(2, 4, RED);
    this->eye->drawPixel(3, 4, RED);
    this->eye->drawPixel(4, 4, RED);
    
    this->eye->drawPixel(0, 5, RED);
    this->eye->drawPixel(1, 5, RED);
    this->eye->drawPixel(2, 5, RED);
    this->eye->drawPixel(3, 5, RED);
    this->eye->drawPixel(4, 5, RED);
    
    this->eye->drawPixel(0, 6, RED);
    this->eye->drawPixel(1, 6, RED);
    this->eye->drawPixel(2, 6, RED);
    this->eye->drawPixel(3, 6, RED);
    this->eye->drawPixel(4, 6, RED);
    
    this->eye->drawPixel(1, 7, RED);
    this->eye->drawPixel(2, 7, RED);
    this->eye->drawPixel(3, 7, RED);
  }

  
  this->eyeState = STATE_VERYANGRY;
  this->eye->show();
}

void Eye::sleepyEye()
{
  this->resetEye();
  
  this->eye->drawPixel(0, 4, ORANGE);
  this->eye->drawPixel(1, 4, ORANGE);
  this->eye->drawPixel(2, 4, ORANGE);
  this->eye->drawPixel(3, 4, ORANGE);
  this->eye->drawPixel(4, 4, ORANGE);
  
  this->eye->drawPixel(0, 5, ORANGE);
  this->eye->drawPixel(1, 5, ORANGE);
  this->eye->drawPixel(2, 5, ORANGE);
  this->eye->drawPixel(3, 5, ORANGE);
  this->eye->drawPixel(4, 5, ORANGE);
  
  this->eye->drawPixel(0, 6, ORANGE);
  this->eye->drawPixel(1, 6, ORANGE);
  this->eye->drawPixel(2, 6, ORANGE);
  this->eye->drawPixel(3, 6, ORANGE);
  this->eye->drawPixel(4, 6, ORANGE);
  
  this->eye->drawPixel(1, 7, ORANGE);
  this->eye->drawPixel(2, 7, ORANGE);
  this->eye->drawPixel(3, 7, ORANGE);

  this->eyeState = STATE_SLEEPY;
  this->eye->show();
}

void Eye::deadEye()
{
  this->resetEye();
  
  this->eye->drawPixel(0, 1, ORANGE);
  this->eye->drawPixel(4, 1, ORANGE);

  this->eye->drawPixel(1, 2, ORANGE);
  this->eye->drawPixel(3, 2, ORANGE);

  this->eye->drawPixel(2, 3, ORANGE);
  
  this->eye->drawPixel(1, 4, ORANGE);
  this->eye->drawPixel(3, 4, ORANGE);

  this->eye->drawPixel(0, 5, ORANGE);
  this->eye->drawPixel(4, 5, ORANGE);

  this->eyeState = STATE_DEAD;
  this->eye->show();
}
