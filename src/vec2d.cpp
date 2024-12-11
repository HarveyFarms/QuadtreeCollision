#include "vec2d.h"

bool vec2d::operator==(const vec2d & v) const 
{
  return (x_ == v.x_ && y_ == v.y_); 
}


bool vec2d::operator!=(const vec2d & v) const 
{
  return (!(*this == v)); 
}


double vec2d::get_x() const 
{
  return x_; 
}


double vec2d::get_y() const 
{
  return y_; 
}


void vec2d::set_x(double d) 
{
  x_ = d; 
}


void vec2d::set_y(double d) 
{
  y_ = d; 
}


double vec2d::operator[](int i) const 
{
  return (i == 0 ? x_ : y_); 
}


double & vec2d::operator[](int i) 
{
  return (i == 0 ? x_ : y_); 
}


vec2d vec2d::operator+() const 
{
  return *this; 
}


vec2d & vec2d::operator+=(const vec2d & v) 
{
  x_ += v.x_; y_ += v.y_; return *this; 
}


vec2d vec2d::operator+(const vec2d & v) const 
{
  vec2d p(*this); p += v; return p; 
}


vec2d & vec2d::operator-=(const vec2d & v) 
{
  x_ -= v.x_; y_ -= v.y_; return *this; 
}


vec2d vec2d::operator-() 
{
  x_ = -x_; y_ = -y_; return *this; 
}


vec2d vec2d::operator-(const vec2d & v) const 
{
  vec2d p(*this); p -= v; return p; 
}


vec2d & vec2d::operator*=(double v) 
{
  x_ *= v; y_ *= v; return *this; 
}


vec2d vec2d::operator*(double v) const 
{
  vec2d p(*this); p *= v; return p; 
}


vec2d & vec2d::operator/=(double v) 
{
  x_ /= v; y_ /= v; return *this; 
}


vec2d vec2d::operator/(double v) const 
{
  vec2d p(*this); p /= v; return p; 
}


double vec2d::len() const 
{
  return sqrt(x_ * x_ + y_ * y_); 
}


std::ostream & operator<<(std::ostream & cout, const vec2d & v) 
{
  cout << '<' << v.x_ << ',' << ' ' << v.y_ << '>'; return cout; 
}


std::istream & operator>>(std::istream & cin, vec2d & v) 
{
  double x, y; std::cin >> x >> y; v.set_x(x); v.set_y(y); return cin; 
}


vec2d operator*(double d, const vec2d & v) 
{
  vec2d t(d * v.get_x(), d * v.get_y()); return t; 
}


double len(const vec2d & v) 
{
  return v.len(); 
}


double dotprod(const vec2d & v, const vec2d & u) 
{
  return v.get_x() * u.get_x() + v.get_y() * u.get_y(); 
}


vec2d norm(const vec2d & v) 
{
  vec2d u(v); u /= u.len(); return u; 
}


