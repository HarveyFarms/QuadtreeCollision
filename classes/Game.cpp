#include "Game.h"


Surface * Object::s_(NULL);
Surface * Circle::s_(NULL);
int Circle::r(RADIUS);
Color Circle::color(RED);

Game::Game() :
  surface(new Surface(W, H)),
  kp(get_keypressed()),
  keyboard(event),
  quad_mode(false),
  pressed(false)
{
  srand((unsigned int) time(nullptr));
  Object::set_surface(surface);
  Circle::set_surface(surface);
  for (int i = 0; i < AMNT_CIRCLES; ++i) {
    v.push_back(Circle(rand() % W, rand() % H));
  }
}
Game::~Game() 
{ 
  if (surface != nullptr) delete surface; 
}


void Game::run()
{
  int start, end, dt, RATE = FPS;
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

void Game::get_input() {
  if (kp[SPACE] && !pressed) {
    quad_mode = !quad_mode;
    pressed = true;
  }
  else if (!kp[SPACE])
      pressed = false;
}
void Game::update()
{
  if (quad_mode) {
  }
  else {
    for (std::vector< Circle >::iterator i = v.begin(); i != v.end(); ++i) {
      for (std::vector< Circle >::iterator j = std::next(i); j != v.end(); ++j) {
        if (i != j)
          i->handle_collision(*j);
      }
    }
  }
  for (auto & i : v) {
    i.update();
  }
}
void Game::draw()
{
  surface->lock();
  surface->fill(BLACK);

  for (auto & i : v) {
    i.draw();
  }

  surface->unlock();
  surface->flip();
}
