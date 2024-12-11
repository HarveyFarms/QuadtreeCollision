#ifndef CIRCLE_H
#define CIRCLE_H

#include "vec2d.h"

class Circle {
  public:
    Circle(int a, int b)
      : x(a), y(b) {
        bool moving = false;
        int longitude = rand() % 2;
        switch (longitude) {
          case 0:
            direction.set_x(-SPEED);
            moving = true;
            break;
          case 1:
            direction.set_x(SPEED);
            moving = true;
            break;
        }
        int latitude = rand() % 2;
        switch (latitude) {
          case 0:
            direction.set_y(-SPEED);
            break;
          case 1:
            direction.set_y(SPEED);
            break;
        }
      }
    void draw()
    {
      if (x < 0 || x >= W) x = rand() % W;
      if (y < 0 || y >= H) y = rand() % H;
      s_->put_circle(x, y, r, color);
    }
    void update() {
      x += direction.get_x();
      y += direction.get_y();

      if (x + r > W) {
        x = W - r;
        direction.set_x(-direction.get_x()); 
      }
      else if (x - r < 0) {
        x = r; 
        direction.set_x(-direction.get_x()); 
      }
      if (y + r > H) {
        y = H - r; 
        direction.set_y(-direction.get_y()); 
      }
      else if (y - r < 0) {
        y = r; 
        direction.set_y(-direction.get_y()); 
      }
    }
    bool collision(Circle & c) {
      double dx = x - c.x;
      double dy = y - c.y;
      double combined_radius = r + r;
      return (dx * dx + dy * dy <= combined_radius * combined_radius);
    }
    void handle_collision(Circle & c) {
      if (!collision(c)) return;

      double dx = c.x - x;
      double dy = c.y - y;
      double distance = sqrt(dx * dx + dy * dy);

      double nx = dx / distance;
      double ny = dy / distance;

      direction.set_x(-direction.get_x());
      direction.set_y(-direction.get_y());
      c.direction.set_x(-c.direction.get_x());
      c.direction.set_y(-c.direction.get_y());

      double overlap = (r + c.r - distance) / 2.0;
      x -= overlap * nx;
      y -= overlap * ny;
      c.x += overlap * nx;
      c.y += overlap * ny;
    }
    int x;
    int y;
    vec2d direction;
    static int r;
    static Color color;
    static Surface * s_;
    static void set_surface(Surface * s)
    {
      s_ = s;
    }
};
#endif
