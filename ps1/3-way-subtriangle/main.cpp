#include "fractal.hpp"

int main(int argc, char* argv[])
{
  if (argc < 3)
    {
      std::cout
      <<
      "serpinski"
      "[recursion-depth]"
      "[side-length]"
      << std::endl;
      return -1;
    }
  int depth = atoi(argv[1]);
  int side = atoi(argv[2]);
  fractal f(side, depth);
  sf::RenderWindow
    window(sf::VideoMode(side,
    (int)(0.5*sqrt(3.)*(float)side)),
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
      window.draw(f);
      window.display();
    }
  return 0;
}
