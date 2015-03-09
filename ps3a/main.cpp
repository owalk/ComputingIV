#include "Body.hpp"
int main(int argc, char* argv[])
{

  // double universe_size = 2.50e11; not currently using. may want to scale off
  // of this later on for adjusting screen size.

  int window_size = 500;
  
  body sun(window_size);
  body earth(window_size);
  body mars(window_size);
  body mercury(window_size);
  body venus(window_size);
  
  std::vector<body*> planets;

  sf::Sprite background;
  sf::Texture t;
    
  if (!t.loadFromFile("starfield.jpg"))
    return 1;

  background.setTexture(t);

  
  planets.push_back(&sun);
  planets.push_back(&earth);
  planets.push_back(&mars);
  planets.push_back(&mercury);
  planets.push_back(&venus);
                         
  std::ifstream file ("./planets.txt");

  if(file.is_open()){
    for (unsigned i = 0; i < planets.size(); i++)
      file >> *planets.at(i);
    file.close();
    }
  
  sf::RenderWindow window(sf::VideoMode(window_size, window_size),
                          "The solar system! By Oliver Walker");
  
  while (window.isOpen())    {
     sf::Event event;
      while (window.pollEvent(event))
        {
          if(event.type == sf::Event::Closed)
            window.close();
        }
      window.clear();
      window.draw(background);
      window.draw(mars);
      window.draw(earth);
      window.draw(sun);
      window.draw(venus);
      window.draw(mercury);
      window.display();
    }
  return 0;
}
