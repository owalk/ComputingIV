#include "Sierpinski.hpp"
/*     
        _top  
          .
         / \
        /   \ 
       /     \
      /       \
  p1 /.------ .\ p3
    /  \     /  \
   /    \   /    \
  /      \ /      \
 *--------*--------*
_left    p2    _right

*/
Sierpinski::Sierpinski (void)//should not be called
{
  _top = sf::Vector2f(1,1);
  _left = sf::Vector2f(1,1);
  _right = sf::Vector2f(1,1);  
  _depth = -1;
  return;
}

Sierpinski::Sierpinski (int sidelength, int depth) //starts the tree
{
  _depth = depth;
  int newDepth = _depth -1;
  
  float hieght = 0.5 * sqrt(3.) * (float)sidelength;
  _top =sf::Vector2f(sidelength / 2, 0);
  _left = sf::Vector2f(0, hieght);
  _right = sf::Vector2f(sidelength-1, hieght);
  _p1 = sf::Vector2f(((_top.x+_left.x)/2), ((_top.y+_left.y)/2));
  _p2 = sf::Vector2f(((_right.x+_left.x)/2), ((_right.y+_left.y)/2));
  _p3 = sf::Vector2f(((_top.x+_right.x)/2), ((_top.y+_right.y)/2));

 
  if (_depth > 0){
    _child0 = new Sierpinski(_top, _p1, _p3, newDepth);
    _child1 = new Sierpinski(_p1, _left, _p2, newDepth);
    _child2 = new Sierpinski(_p3, _p2, _right, newDepth);
  } else {
    _child0 = NULL;
    _child1 = NULL;
    _child2 = NULL;
  }
    
  return;
}
Sierpinski::Sierpinski (sf::Vector2f point1, sf::Vector2f point2, sf::Vector2f
                        point3, int depth) //makes the tree "branches"
{
  int newDepth = depth -1;
  _top = point1;
  _left = point2;
  _right = point3;

  _p1 = sf::Vector2f(((_top.x+_left.x)/2), ((_top.y+_left.y)/2));
  _p2 = sf::Vector2f(((_right.x+_left.x)/2), ((_right.y+_left.y)/2));
  _p3 = sf::Vector2f(((_top.x+_right.x)/2), ((_top.y+_right.y)/2));

if (depth > 0){
    _child0 = new Sierpinski(_top, _p1, _p3, newDepth);
    _child1 = new Sierpinski(_p1, _left, _p2, newDepth);
    _child2 = new Sierpinski(_p3, _p2, _right, newDepth);
  } else {
    _child0 = NULL;
    _child1 = NULL;
    _child2 = NULL;
  }
  
  if(_depth == 0)
     return;
}

Sierpinski::~Sierpinski (void)
{
  if(_child0 != NULL)
    {
      delete (_child0);
      delete (_child1);
      delete (_child2);
    }
  return;
}

void Sierpinski::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
  sf::ConvexShape triangle;
  triangle.setPointCount(3);
  triangle.setPoint(0, _p1);
  triangle.setPoint(1, _p2);
  triangle.setPoint(2, _p3);
  triangle.setFillColor(sf::Color::Red);
  target.draw(triangle, states);

  if (_child0 != NULL){
    _child0->draw(target, states);
    _child1->draw(target, states);
    _child2->draw(target, states);
    }
  }

