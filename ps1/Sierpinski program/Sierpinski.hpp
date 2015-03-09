#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>

class Sierpinski : public sf::Drawable {class Sierpinski : public sf::Drawable {
public:
  Sierpinski(void);
  Sierpinski(sf::Vector2f point1, sf::Vector2f point2, sf::Vector2f point3, int depth);// route 1
  Sierpinski (int sidelength, int depth); //route 2
  
  ~Sierpinski(void);

  //accessors

  //mutators

private:
  void virtual draw(sf::RenderTarget& target, sf::RenderStates states) const;

  sf::Vector2f _top, _left, _right, _p1, _p2, _p3;
  int _depth;
  Sierpinski *_child0, *_child1, *_child2;
};

