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

void Eye::displayPattern(const char p[HEIGHT][WIDTH])
{
  for (int i = 0; i < HEIGHT; i++)
  {
    for (int j = 0; j < WIDTH; j++)
    {
      if (p[i][j] == '*')
        this->eye->drawPixel(j, i, OFF);
      else if (p[i][j] == 'O')
        this->eye->drawPixel(j, i, ORANGE);
      else if (p[i][j] == 'B')
        this->eye->drawPixel(j, i, BLUE);
      else if (p[i][j] == 'R')
        this->eye->drawPixel(j, i, RED);
    }
  }
}

void Eye::normalEye()
{
  this->resetEye();

  const char disp[HEIGHT][WIDTH] = {
    {'*', 'O', 'O', 'O', '*'},
    {'O', 'O', 'O', 'O', 'O'},
    {'O', 'O', 'O', 'O', 'O'},
    {'O', 'O', 'O', 'O', 'O'},
    {'O', 'O', 'O', 'O', 'O'},
    {'O', 'O', 'O', 'O', 'O'},
    {'O', 'O', 'O', 'O', 'O'},
    {'*', 'O', 'O', 'O', '*'}
  };

  this->displayPattern(disp);
  
  this->eyeState = STATE_NORMAL;
  this->eye->show();
}

void Eye::happyEye()
{
  this->resetEye();

  const char disp[HEIGHT][WIDTH] = {
    {'*', '*', '*', '*', '*'},
    {'*', 'O', 'O', 'O', '*'},
    {'O', '*', '*', '*', 'O'},
    {'*', '*', '*', '*', '*'},
    {'*', '*', '*', '*', '*'},
    {'*', '*', '*', '*', '*'},
    {'*', '*', '*', '*', '*'},
    {'*', '*', '*', '*', '*'}
  };

  this->displayPattern(disp);

  this->eyeState = STATE_HAPPY;
  this->eye->show();
}

void Eye::sadEye()
{
  this->resetEye();
  
  if (this->eyeType == LEFT_EYE)
  {
    const char disp[HEIGHT][WIDTH] = {
      {'O', '*', '*', '*', '*'},
      {'O', 'O', '*', '*', '*'},
      {'O', 'O', 'O', '*', '*'},
      {'O', 'O', 'O', 'O', '*'},
      {'O', 'O', 'O', 'O', 'O'},
      {'O', 'O', 'O', 'O', 'O'},
      {'O', 'O', 'O', 'O', 'O'},
      {'*', 'O', 'O', 'O', '*'},
    };
    
    this->displayPattern(disp);
  }
  else if (this->eyeType == RIGHT_EYE)
  {
    const char disp[HEIGHT][WIDTH] = {
      {'*', '*', '*', '*', 'O'},
      {'*', '*', '*', 'O', 'O'},
      {'*', '*', 'O', 'O', 'O'},
      {'*', 'O', 'O', 'O', 'O'},
      {'O', 'O', 'O', 'O', 'O'},
      {'O', 'O', 'O', 'O', 'O'},
      {'O', 'O', 'O', 'O', 'O'},
      {'*', 'O', 'O', 'O', '*'}
    };
    
    this->displayPattern(disp);
  }

  this->eyeState = STATE_SAD;
  this->eye->show();
}

void Eye::verySadEye()
{
  this->resetEye();
  
  if (this->eyeType == LEFT_EYE)
  {
    const char disp[HEIGHT][WIDTH] = {
      {'O', '*', '*', '*', '*'},
      {'O', 'O', '*', '*', '*'},
      {'O', 'O', 'O', '*', '*'},
      {'O', 'O', 'O', 'O', '*'},
      {'O', 'O', 'O', 'O', 'O'},
      {'O', 'O', 'O', 'O', 'O'},
      {'B', 'B', 'B', 'B', 'B'},
      {'*', 'B', 'B', 'B', '*'}
    };
    
    this->displayPattern(disp);
  }
  else if (this->eyeType == RIGHT_EYE)
  {
    const char disp[HEIGHT][WIDTH] = {
      {'*', '*', '*', '*', 'O'},
      {'*', '*', '*', 'O', 'O'},
      {'*', '*', 'O', 'O', 'O'},
      {'*', 'O', 'O', 'O', 'O'},
      {'O', 'O', 'O', 'O', 'O'},
      {'O', 'O', 'O', 'O', 'O'},
      {'B', 'B', 'B', 'B', 'B'},
      {'*', 'B', 'B', 'B', '*'}
    };
    
    this->displayPattern(disp);
  }

  this->eyeState = STATE_SAD;
  this->eye->show();
}

void Eye::closedEye()
{
  this->resetEye();
  
  const char disp[HEIGHT][WIDTH] = {
    {'*', '*', '*', '*', '*'},
    {'*', '*', '*', '*', '*'},
    {'*', '*', '*', '*', '*'},
    {'O', 'O', 'O', 'O', 'O'},
    {'*', '*', '*', '*', '*'},
    {'*', '*', '*', '*', '*'},
    {'*', '*', '*', '*', '*'},
    {'*', '*', '*', '*', '*'}
  };
  
  this->displayPattern(disp);

  this->eyeState = STATE_CLOSED;
  this->eye->show();
}

void Eye::fullHappyEye()
{
  this->resetEye();
  
  const char disp[HEIGHT][WIDTH] = {
    {'*', 'O', 'O', 'O', '*'},
    {'O', 'O', 'O', 'O', 'O'},
    {'O', 'O', 'O', 'O', 'O'},
    {'O', 'O', 'O', 'O', 'O'},
    {'*', '*', '*', '*', '*'},
    {'*', '*', '*', '*', '*'},
    {'*', '*', '*', '*', '*'},
    {'*', '*', '*', '*', '*'}
  };
  
  this->displayPattern(disp);

  this->eyeState = STATE_FULL_HAPPY;
  this->eye->show();
}

void Eye::laughingEye()
{
  this->resetEye();

  if (this->eyeType == LEFT_EYE)
  {
    const char disp[HEIGHT][WIDTH] = {
      {'*', '*', '*', 'O', '*'},
      {'*', '*', 'O', '*', '*'},
      {'*', 'O', '*', '*', '*'},
      {'O', '*', '*', '*', '*'},
      {'*', 'O', '*', '*', '*'},
      {'*', '*', 'O', '*', '*'},
      {'*', '*', '*', 'O', '*'},
      {'*', '*', '*', '*', 'O'}
    };
  
    this->displayPattern(disp);
  }
  else if (this->eyeType == RIGHT_EYE)
  {
    const char disp[HEIGHT][WIDTH] = {
      {'*', 'O', '*', '*', '*'},
      {'*', '*', 'O', '*', '*'},
      {'*', '*', '*', 'O', '*'},
      {'*', '*', '*', '*', 'O'},
      {'*', '*', '*', 'O', '*'},
      {'*', '*', 'O', '*', '*'},
      {'*', 'O', '*', '*', '*'},
      {'O', '*', '*', '*', '*'}
    };
  
    this->displayPattern(disp);
  }
  
  this->eyeState = STATE_LAUGHING;
  this->eye->show();
}

void Eye::angryEye()
{
  this->resetEye();

  if (this->eyeType == LEFT_EYE)
  {
    const char disp[HEIGHT][WIDTH] = {
      {'*', '*', '*', '*', 'O'},
      {'*', '*', '*', 'O', 'O'},
      {'*', '*', 'O', 'O', 'O'},
      {'*', 'O', 'O', 'O', 'O'},
      {'O', 'O', 'O', 'O', 'O'},
      {'O', 'O', 'O', 'O', 'O'},
      {'O', 'O', 'O', 'O', 'O'},
      {'*', 'O', 'O', 'O', '*'}
    };
  
    this->displayPattern(disp);
  }
  else if (this->eyeType == RIGHT_EYE)
  {
    const char disp[HEIGHT][WIDTH] = {
      {'O', '*', '*', '*', '*'},
      {'O', 'O', '*', '*', '*'},
      {'O', 'O', 'O', '*', '*'},
      {'O', 'O', 'O', 'O', '*'},
      {'O', 'O', 'O', 'O', 'O'},
      {'O', 'O', 'O', 'O', 'O'},
      {'O', 'O', 'O', 'O', 'O'},
      {'*', 'O', 'O', 'O', '*'}
    };
  
    this->displayPattern(disp);
  }
  
  this->eyeState = STATE_ANGRY;
  this->eye->show();
}

void Eye::veryAngryEye()
{
  this->resetEye();

  if (this->eyeType == LEFT_EYE)
  {
    const char disp[HEIGHT][WIDTH] = {
      {'*', '*', '*', '*', 'R'},
      {'*', '*', '*', 'R', 'R'},
      {'*', '*', 'R', 'R', 'R'},
      {'*', 'R', 'R', 'R', 'R'},
      {'R', 'R', 'R', 'R', 'R'},
      {'R', 'R', 'R', 'R', 'R'},
      {'R', 'R', 'R', 'R', 'R'},
      {'*', 'R', 'R', 'R', '*'}
    };
  
    this->displayPattern(disp);
  }
  else if (this->eyeType == RIGHT_EYE)
  {
    const char disp[HEIGHT][WIDTH] = {
      {'R', '*', '*', '*', '*'},
      {'R', 'R', '*', '*', '*'},
      {'R', 'R', 'R', '*', '*'},
      {'R', 'R', 'R', 'R', '*'},
      {'R', 'R', 'R', 'R', 'R'},
      {'R', 'R', 'R', 'R', 'R'},
      {'R', 'R', 'R', 'R', 'R'},
      {'*', 'R', 'R', 'R', '*'}
    };
  
    this->displayPattern(disp);
  }

  
  this->eyeState = STATE_VERYANGRY;
  this->eye->show();
}

void Eye::sleepyEye()
{
  this->resetEye();
  
  const char disp[HEIGHT][WIDTH] = {
    {'*', '*', '*', '*', '*'},
    {'*', '*', '*', '*', '*'},
    {'*', '*', '*', '*', '*'},
    {'*', '*', '*', '*', '*'},
    {'O', 'O', 'O', 'O', 'O'},
    {'O', 'O', 'O', 'O', 'O'},
    {'O', 'O', 'O', 'O', 'O'},
    {'*', 'O', 'O', 'O', '*'}
  };

  this->displayPattern(disp);

  this->eyeState = STATE_SLEEPY;
  this->eye->show();
}

void Eye::deadEye()
{
  this->resetEye();
    const char disp[HEIGHT][WIDTH] = {
    {'*', '*', '*', '*', '*'},
    {'O', '*', '*', '*', 'O'},
    {'*', 'O', '*', 'O', '*'},
    {'*', '*', 'O', '*', '*'},
    {'*', 'O', '*', 'O', '*'},
    {'O', '*', '*', '*', 'O'},
    {'*', '*', '*', '*', '*'},
    {'*', '*', '*', '*', '*'}
  };

  this->displayPattern(disp);
  
  this->eyeState = STATE_DEAD;
  this->eye->show();
}

void Eye::heartEye()
{
  this->resetEye();
    const char disp[HEIGHT][WIDTH] = {
    {'*', '*', '*', '*', '*'},
    {'*', 'R', '*', 'R', '*'},
    {'R', 'R', 'R', 'R', 'R'},
    {'R', 'R', 'R', 'R', 'R'},
    {'R', 'R', 'R', 'R', 'R'},
    {'*', 'R', 'R', 'R', '*'},
    {'*', '*', 'R', '*', '*'},
    {'*', '*', '*', '*', '*'}
  };

  this->displayPattern(disp);
  
  this->eyeState = STATE_DEAD;
  this->eye->show();
}

void Eye::skepticalEye()
{
  this->resetEye();
  const char disp[HEIGHT][WIDTH] = {
    {'*', '*', '*', '*', '*'},
    {'*', '*', '*', '*', '*'},
    {'*', '*', '*', '*', '*'},
    {'O', 'O', 'O', 'O', 'O'},
    {'O', 'O', 'O', 'O', 'O'},
    {'O', 'O', 'O', 'O', 'O'},
    {'O', 'O', 'O', 'O', 'O'},
    {'*', 'O', 'O', 'O', '*'}
  };

  this->displayPattern(disp);
  
  this->eyeState = STATE_SKEPTICAL;
  this->eye->show();
}

void Eye::suspiciousEye()
{
  this->resetEye();
  const char disp[HEIGHT][WIDTH] = {
    {'*', '*', '*', '*', '*'},
    {'*', '*', '*', '*', '*'},
    {'*', '*', '*', '*', '*'},
    {'O', 'O', 'O', 'O', 'O'},
    {'O', 'O', 'O', 'O', 'O'},
    {'O', 'O', 'O', 'O', 'O'},
    {'*', '*', '*', '*', '*'},
    {'*', '*', '*', '*', '*'}
  };

  this->displayPattern(disp);
  
  this->eyeState = STATE_SUSPICIOUS;
  this->eye->show();
}

void Eye::reallyEye()
{
  this->resetEye();
  const char disp[HEIGHT][WIDTH] = {
    {'*', '*', '*', '*', '*'},
    {'*', '*', '*', '*', '*'},
    {'*', '*', '*', '*', '*'},
    {'O', 'O', 'O', 'O', 'O'},
    {'O', 'O', 'O', 'O', 'O'},
    {'O', 'O', 'O', 'O', 'O'},
    {'O', 'O', 'O', 'O', 'O'},
    {'*', 'O', 'O', 'O', '*'}
  };

  this->displayPattern(disp);
  
  this->eyeState = STATE_REALLY;
  this->eye->show();
}

void Eye::surpriseEye()
{
  this->resetEye();
  const char disp[HEIGHT][WIDTH] = {
    {'*', 'O', 'O', 'O', '*'},
    {'O', 'O', '*', 'O', 'O'},
    {'O', '*', '*', '*', 'O'},
    {'O', '*', '*', '*', 'O'},
    {'O', '*', '*', '*', 'O'},
    {'O', '*', '*', '*', 'O'},
    {'O', 'O', '*', 'O', 'O'},
    {'*', 'O', 'O', 'O', '*'}
  };

  this->displayPattern(disp);
  
  this->eyeState = STATE_SURPRISE;
  this->eye->show();
}

void Eye::noEye()
{
  this->resetEye();
  this->eyeState = STATE_NO_EYE;
  this->eye->show();
}
