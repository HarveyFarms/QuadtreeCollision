/* File: vec2d.h
Author: Ryan Harvey
Date: 2024-02-13

  Description
This is the header file of the vec2d class.

Each vec2d object models a 2-dimensional vector with double coordinates. 
The methods and operators supported are described below. In the following,
u, v, and w are vec2d objects while c, d are doubles.

vec2d u(x,y) - Constructor. This sets the x and y values of u to values of 
                 parameters x and y respectively. The default values are 0,0 
                 respectively.

std::cout << u - Prints vector u. The format is "<x, y>" where x and y are the 
                 x and y values of u.

std::cin >> u  - Input for u.

u.get_x()      - Returns the x_ value of vec2d object u.
u.get_y()      - Returns the y_ value of vec2d object u.

u.set_x(x0)    - Sets the x_ value of u to the value of x0.
u.set_y(y0)    - Sets the y_ value of u to the value of y0.
u[i]         - Returns the x_ value or a reference to the x_ value of u
                 if i is 0; otherwise the y_ value or reference to the y_
                 value is returned

u == v         - Returns true iff the respective x_, y_ values of u and v are the same.

u != v         - The boolean opposite of (u == v)
u = v          - Copies the x, y values of v to u.

+u             - Returns a copy of u.
u += v         - Increments the x_ and y_ values of u by the x and y values of v respectively.
                 A reference to u is returned so that you can also execute (u += v) += w

u + v          - Returns the vector sum of u and v.

-u             - Returns the negative of u, i.e., the vec2d object returned has x_, y_ values 
                 which are the negative of the x_, y_ values of u.

u -= v         - Decrements the x_ and y_ values of u by the x_ and y_ values of v. A reference 
                 to u is returned so that you can also execute (u -= v) -= w).

u - v          - Returns the vector difference of u and v.

u *= c         - Multiplies the x_, y_ values of u by double c and set the x_, y_ values to these 
                 new values (respectively). A reference to u is returned so that you can also 
                 execute (u *= c) *= d.

u * c          - Returns the vector scalar product of vector u by the double c, i.e. a vec2d object 
                 is returned where the x_, y_ values of this new vec2d object are the x_, y_ values 
                 of u multiplied by c.

c * u          - Similar to u * c.

u /= c         - Divides the x, y values of u by double c and set the x_, y_ values to these new values 
                 (respectively). A reference to u is returned so that you can also execute (u /= c) /= d.

u / c          - Returns the vector scalar product of vector u by the double (1/c).

len(u)         - Returns the length of vector u as a double. This is the square root of x_*x_+y_*y_ where 
                 x_, y_ are the values in u. Note that this is a non-member function.
u.len()        - Same as len(u) except that this is a method

dotprod(u, v)  - Returns the dot product of vectors u and v as a double. 
norm(u)        - Returns the normalized vector of u, i.e. this function returns u / len(u), a vector of length 
                 1 going in the same direction of u. */
#ifndef VEC2H_H
#define VEC2H_H

#include <iostream>
#include <cmath>

class vec2d
{
public:
  vec2d(double x = 0, double y = 0) : x_(x), y_(y) {}

  bool operator==(const vec2d & v) const;
  bool operator!=(const vec2d & v) const;

  double get_x() const;
  double get_y() const;

  void set_x(double d);
  void set_y(double d);

  double operator[](int i) const;
  double & operator[](int i);

  vec2d operator+() const;
  vec2d & operator+=(const vec2d & v);
  vec2d operator+(const vec2d & v) const;

  vec2d operator-();
  vec2d & operator-=(const vec2d & v);
  vec2d operator-(const vec2d & v) const;

  vec2d & operator*=(double v);
  vec2d operator*(double v) const;

  vec2d & operator/=(double v);
  vec2d operator/(double v) const;

  friend std::ostream & operator<<(std::ostream & cout, const vec2d & v);

  double len() const;
private:
  double x_, y_;
};
std::istream & operator>>(std::istream & cin, vec2d & v);
vec2d operator*(double, const vec2d & v);
double len(const vec2d & v);
double dotprod(const vec2d & v, const vec2d & u);
vec2d norm(const vec2d & v);
#endif
