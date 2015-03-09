#include "Body.hpp"
int main(int argc, char* argv[])
{

  // double universe_size = 2.50e11; not currently using. may want to scale off
  // of this later on for adjusting screen size.

  if(argc < 3)
    {
      std::cout << "NBody [total time] [time per step]" << std::endl;
    }
  //int totalTime;
  int stepTime;

  // totalTime = atoi(argv[1]);
  stepTime = atoi(argv[2]);
  
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

  universe all(stepTime);

  all.setBody(&sun);
  all.setBody(&earth);
  all.setBody(&mars);
  all.setBody(&mercury);
  all.setBody(&venus);
  
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
      for(unsigned i = 0; i < all.getNumBodies(); i++ )
        window.draw( all.getBody(i) );
      //window.draw(mars);
      //window.draw(earth);
      //window.draw(sun);
      //window.draw(venus);
      //window.draw(mercury);
      window.display();
      all.movement();
    }
  return 0;
}
