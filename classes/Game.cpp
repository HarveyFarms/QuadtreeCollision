#include "Game.h"

Surface * Object::s_(NULL);

Game::Game() :
  surface(new Surface(W, H)),
  kp(get_keypressed()),
  keyboard(event)
{
  srand((unsigned int) time(nullptr));
  Object::set_surface(surface);
}
Game::~Game() 
{ 
  if (surface != nullptr) delete surface; 
}


void Game::run()
{
  int start, end, dt, RATE = s60FPS;
  while (GAME_IS_RUNNING && !user_quits())
  {
    start = getTicks();

    get_input();

    update();

    draw();

    end = getTicks();
    dt = RATE - end + start;
    if (dt > 0) delay(dt);
  }

  delay(50);
}

void Game::get_input()
{
}
void Game::update()
{
}
void Game::draw()
{
  surface->lock();
  surface->fill(BLACK);

  surface->unlock();
  surface->flip();
}
void Game::reset_all()
{
}
