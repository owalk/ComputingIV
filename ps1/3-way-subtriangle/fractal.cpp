#include "fractal.hpp"
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

fractal::fractal (void)//should not be called
{
  _top = sf::Vector2f(1,1);
  _left = sf::Vector2f(1,1);
  _right = sf::Vector2f(1,1);  
  _depth = -1;
  return;
}

fractal::fractal (int sidelength, int depth) //starts the tree
{
  _depth = depth;
  int newDepth = _depth -1;
  
  float hieght = 0.5 * sqrt(3.) * (float)sidelength;
  _top =sf::Vector2f(sidelength / 2, 0);
  _left = sf::Vector2f(0, hieght);
  _right = sf::Vector2f(sidelength-1, hieght);
  _p1 = sf::Vector2f(((_top.x + _left.x + _right.x)/3), ((_top.y + _left.y + _right.y)/3));
  

  
  if (_depth > 0){
    _child0 = new fractal(_top, _p1, _right, newDepth);
    _child1 = new fractal(_top, _p1, _left, newDepth);
    _child2 = new fractal(_left, _p1, _right, newDepth);
  } else {
    _child0 = NULL;
    _child1 = NULL;
    _child2 = NULL;
  }
  
  return;
}
fractal::fractal (sf::Vector2f point1, sf::Vector2f point2, sf::Vector2f
                        point3, int depth) //makes the tree "branches"
{
  int newDepth = depth -1;
  _top = point1;
  _left = point2;
  _right = point3;

  _p1 = sf::Vector2f(((_top.x + _left.x + _right.x)/3), ((_top.y + _left.y + _right.y)/3));


if (depth > 0){
    _child0 = new fractal(_top, _p1, _right, newDepth);
    _child1 = new fractal(_top, _p1, _left, newDepth);
    _child2 = new fractal(_left, _p1, _right, newDepth);
  } else {
    _child0 = NULL;
    _child1 = NULL;
    _child2 = NULL;
  }
  
  if(_depth == 0)
     return;
}

fractal::~fractal (void)
{
  if(_child0 != NULL)
    {
      delete (_child0);
      delete (_child1);
      delete (_child2);
    }
  return;
}

void fractal::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
  sf::ConvexShape triangle;
  triangle.setPointCount(3);
  triangle.setPoint(0, _top);
  triangle.setPoint(1, _left);
  triangle.setPoint(2, _right);
  triangle.setOutlineThickness(3);
  triangle.setOutlineColor(sf::Color::Red);
  target.draw(triangle, states);

  if (_child0 != NULL){
    _child0->draw(target, states);
    _child1->draw(target, states);
    _child2->draw(target, states);
    }
  }


