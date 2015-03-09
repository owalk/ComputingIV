#include "Recursion.hpp"

int main(int argc, char* argv[])
{
  if (argc < 3)
    {
      std::cout
      <<
      "fractal"
      "[recursion-depth]"
      "[side-length]"
      << std::endl;
      return -1;
    }
  int depth = atoi(argv[1]);
  int side = atoi(argv[2]);
  Recursion r(side, depth);
  sf::RenderWindow
    window(sf::VideoMode(2*side,
  side*2),
    "Fractal");
  window.setFramerateLimit(1);
  while (window.isOpen())
    {
      sf::Event event;
      while (window.pollEvent(event))
        {
          if(event.type == sf::Event::Closed)
            window.close();
        }
      window.clear();
      window.draw(r);
      window.display();
    }
  return 0;
}
