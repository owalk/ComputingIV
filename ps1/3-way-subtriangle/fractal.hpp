#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>

class fractal : public sf::Drawable {
public:
  fractal(void);
  fractal(sf::Vector2f point1, sf::Vector2f point2, sf::Vector2f point3, int depth);// route 1
  fractal (int sidelength, int depth); //route 2
  
  ~fractal(void);

  //accessors

  //mutators

private:
  void virtual draw(sf::RenderTarget& target, sf::RenderStates states) const;

  sf::Vector2f _top, _left, _right, _p1;
  int _depth;
  fractal *_child0, *_child1, *_child2;
};

/*     
        _top  
          .
         / \
        /   \ 
       /     \
      /  _p1  \
     /   .     \
    /           \
   /             \
  /               \
 *-----------------*
_left          _right

*/
