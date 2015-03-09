#include "Recursion.hpp"

using namespace std;

Recursion::Recursion(int rad, int Dp)
{
  _radius = rad;
  _depth = Dp;

  circle.setRadius(_radius);
  circle.setOrigin(_radius, _radius);
  circle.setPosition(_radius, _radius);
  circle.setOutlineThickness(-5.);
  circle.setOutlineColor(sf::Color::Green);
  circle.setFillColor(sf::Color::Black);
}

Recursion::Recursion(int rad, int Dp, sf::Vector2f ctr)
{
  _radius = rad;
  _depth = Dp;

  circle.setRadius(_radius);
  circle.setOrigin(_radius, _radius);
  circle.setPosition(ctr.x, ctr.y);
  circle.setOutlineThickness(-5.);
  circle.setOutlineColor(sf::Color::Green);
  circle.setFillColor(sf::Color::Black);
}
/*             x
         . -- ~~~ -- .
     .-~               ~-.
    /                     \
   /    .c3          .c0   \
  |                 radius  |
 y|            .------------|
  |         center          |
   \                       /
    \   .c2         .c1   /
     `-.               .-'
         ~- . ___ . -~
      
*/

void Recursion::draw(sf::RenderTarget& target, sf::RenderStates states)const
{
  target.draw(circle, states);

   if(_depth-1 != 0)
    {
      
      Recursion* child0 = new Recursion((_radius/2), _depth-1, sf::Vector2f(_radius + (_radius/2), _radius - (_radius/2)));
      Recursion* child1 = new Recursion((_radius/2), _depth-1, sf::Vector2f(_radius + (_radius/2), _radius + (_radius/2)));
      Recursion* child2 = new Recursion((_radius/2), _depth-1, sf::Vector2f(_radius - (_radius/2), _radius + (_radius/2)));
      Recursion* child3 = new Recursion((_radius/2), _depth-1, sf::Vector2f(_radius - (_radius/2), _radius - (_radius/2)));
      

      /*
      Recursion* child0 = new Recursion((_radius/2), _depth-1, sf::Vector2f(_radius - (_radius/2), _radius + (_radius/2)));
      Recursion* child1 = new Recursion((_radius/2), _depth-1, sf::Vector2f(_radius - (_radius/2), _radius - (_radius/2)));
      Recursion* child2 = new Recursion((_radius/2), _depth-1, sf::Vector2f(_radius + (_radius/2), _radius + (_radius/2)));
      Recursion* child3 = new Recursion((_radius/2), _depth-1, sf::Vector2f(_radius + (_radius/2), _radius - (_radius/2)));
      */
   
      child0->draw(target, states);
      child1->draw(target, states);
      child2->draw(target, states);
      child3->draw(target, states);
    }

  return;
}
