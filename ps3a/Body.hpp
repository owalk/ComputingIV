/*
  Body.hpp
*/
#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <vector>

class body: public sf::Drawable {
public:
  body(int s);
  body(double x, double y, double mass, double x_velocity, double y_velocity,
       sf::Texture planet, int screen_size);
  int coordinate_convert(double coordinate, int screen_size);
private:
  std::string file_name;
  void virtual draw(sf::RenderTarget& target, sf::RenderStates states) const;
  int screen_size;
  double  _x_pos, _y_pos, _mass, _x_velocity, _y_velocity;
  sf::Texture _planet_image;
  friend std::istream& operator>>(std::istream &input, body &magical_wizard);
};
