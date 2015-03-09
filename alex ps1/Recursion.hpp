#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>

using namespace std;

class Recursion: public sf::Drawable
{
public:

  //Constructors
  Recursion(int rad, int Dp);
  Recursion(int rad, int Dp, sf::Vector2f ctr);

  //Accessors

  //Mutators

private:

  sf::Vector2f _center, c0, c1, c2, c3;
  int _radius;
  int _depth;

  sf::CircleShape circle;

  void virtual draw(sf::RenderTarget& target, sf::RenderStates states)const;
};
