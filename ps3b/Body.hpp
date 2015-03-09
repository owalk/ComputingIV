/*
    Body.hpp
*/
#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <numeric>


class body: public sf::Drawable {
public:
  body(int s);
  body(double x, double y, double mass, double x_velocity, double y_velocity,
       sf::Texture planet, int screen_size);
  int coordinate_convert(double coordinate, int screen_size);
  double get_xvel();
  double get_yvel();
  double get_xpos();
  double get_ypos();
  double getMass();
  void set_xvel(double thing);
  void set_yvel(double thing);
  void set_xpos(double thing);
  void set_ypos(double thing);
  int get_screen_size();
  void setpixelx(double newPixle);
  void setpixely(double newPixle);
private:
  std::string file_name;
  void virtual draw(sf::RenderTarget& target, sf::RenderStates states) const;
  int screen_size;
  double  _x_pos, _y_pos, _mass, _x_velocity, _y_velocity, _x_force, _y_force;
  sf::Texture _planet_image;
  friend std::istream& operator>>(std::istream &input, body &object);
  double x_pixle;
  double y_pixle;
};

class universe {
public:
  universe(int myy_time);
  void movement();
  void setBody(body* B);
  unsigned getNumBodies();
  body getBody(unsigned i);
private:
  int _time;
  std::vector<body *> bodies;
  double _radius;
  double _acceleration;
};

