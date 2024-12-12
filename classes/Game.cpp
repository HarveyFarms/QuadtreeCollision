#include "Game.h"

Color random_color() {
  switch (rand() % 7) {
    case 0:
      return RED;
      break;
    case 1:
      return WHITE;
      break;
    case 2:
      return GREEN;
      break;
    case 3:
      return YELLOW;
      break;
    case 4:
      return CYAN;
      break;
    case 5:
      return ORANGE;
      break;
    case 6:
      return LITEPURP;
      break;
  }
  return RED;
}

Surface * Object::s_(NULL);
Surface * Circle::s_(NULL);
Surface * Quad::s_(NULL);
int Circle::r(RADIUS);

Game::Game() :
  surface(new Surface(W, H)),
  kp(get_keypressed()),
  keyboard(event),
  root(new Quad(1, W-1, 1, H-1)),
  quad_mode(true),
  pressed(false)
{
  srand((unsigned int) time(nullptr));
  Object::set_surface(surface);
  Circle::set_surface(surface);
  Quad::set_surface(surface);
  for (int i = 0; i < AMNT_CIRCLES; ++i) {
    Circle * a = new Circle(rand() % W, rand() % H, random_color());
    v.push_back(a);
    root->v.push_back(v[i]);
  }
}
Game::~Game() 
{ 
  if (surface != nullptr) delete surface; 
  if (root != nullptr) {
    root->delete_children();
    delete root; 
  } 
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
    root->delete_children();
    delete root;
    root = new Quad(1, W-1, 1, H-1);
    for (int i = 0; i < AMNT_CIRCLES; ++i) {
      root->v.push_back(v[i]);
    }
    root->build();
    root->update();
  }
  else {
    for (std::vector< Circle * >::iterator i = v.begin(); i != v.end(); ++i) {
      for (std::vector< Circle * >::iterator j = std::next(i); j != v.end(); ++j) {
        (*i)->handle_collision(**j);
      }
    }
  }
  for (auto & i : v) {
    i->update();
  }
}
void Game::draw()
{
  surface->lock();
  surface->fill(BLACK);

  if (quad_mode) {
    std::stack< Quad * > stack;
    stack.push(root);
    while (!stack.empty()) {
      Quad * t = stack.top(); stack.pop();
      if (t == nullptr)
        continue;
      t->draw();
      stack.push(t->children[0]);
      stack.push(t->children[1]);
      stack.push(t->children[2]);
      stack.push(t->children[3]);
    }
  }
  for (auto & i : v) {
    i->draw();
  }

  surface->unlock();
  surface->flip();
}
