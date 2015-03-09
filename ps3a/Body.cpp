//Body.cpp
#include "Body.hpp"

body::body(int s)
{screen_size = s;}

/*
body::body(double x, double y, double mass, double x_velocity, double
           y_velocity, sf::Texture planet, int screen_size)
{
  _x_pos = coordinate_convert(x, screen_size);
  _y_pos = coordinate_convert(y, screen_size);
  _mass = mass;
  _x_velocity = x_velocity;
  _y_velocity = y_velocity;
  _planet_image = planet;

  }*/

int body::coordinate_convert(double coordinate, int screen_size)
{
  int new_coordinate;
  new_coordinate = (screen_size/2) + coordinate*1e-9;
  return new_coordinate;
}

void body::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
  sf::Sprite  sprite;
  sprite.setTexture(_planet_image);
  sprite.setPosition(_x_pos, _y_pos);
  target.draw(sprite, states);
}

std::istream& operator>>(std::istream &input, body &magical_wizard)
{
  double x, y;
  input >> x;
  input >> y;
  
  magical_wizard._x_pos = magical_wizard.coordinate_convert(x, magical_wizard.screen_size);
  magical_wizard._y_pos = magical_wizard.coordinate_convert(y, magical_wizard.screen_size);

  input >> magical_wizard._x_velocity;
  input >> magical_wizard._y_velocity;
  input >> magical_wizard._mass;
  input >> magical_wizard.file_name;

  if (!magical_wizard._planet_image.loadFromFile(magical_wizard.file_name))
    std::cout << magical_wizard.file_name <<" could not be loaded- you're a wizard harry!" << std::endl;

  /*
  std::cout << "x is "<< magical_wizard._x_pos << '\n'
            << "y is "<< magical_wizard._y_pos << '\n'
            << "x v is "<< magical_wizard._x_velocity << '\n'
            << "y v is "<< magical_wizard._y_velocity << '\n'
            << "mass is "<< magical_wizard._mass << '\n'
            << "name is "<< magical_wizard.file_name << std::endl;
  */
  return input;
  }
