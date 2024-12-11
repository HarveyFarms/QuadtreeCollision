#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <fstream>
#include <ctime>
#include <cmath>
#include <cstdlib>
#include <sstream>

#include "Includes.h"
#include "Object.h"
#include "Constants.h"
#include "Circle.h"
#include "compgeom.h"
#include "Surface.h"
#include "Event.h"

class Game
{
public:
  Game();
  ~Game();
  void run();
private:
  // methods to run the game
  void get_input();
  void update();
  void draw();

  int amnt;

  // extra methods
  bool user_quits() 
  { return (event.poll() && event.type() == QUIT); }

  // CIRCLES
  std::vector< Circle > v;

  // main objects for SDL
  Surface * surface;
  Event event;
  KeyPressed kp;
  Keyboard keyboard;
};
#endif
