#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "LFSR.hpp"

int main(int argc, char* argv[])
{

  LFSR l("01100011100011001001100110101010", 6);
  std::string input_file;
  std::string output_file;

  if(argc < 3)
    {
      std::cout << "programs expected more  arguments." << std::endl
                << "ps2b [input_file] [output_file]" << std::endl;
      return -1;
    }
  input_file = argv[1];
  output_file = argv[2];

  sf::Image image;
  sf::Image image2;
  if (!image.loadFromFile(input_file))
    return -1;
  
  sf::Texture texture;
  texture.loadFromImage(image);

  sf::Vector2u size =image.getSize();
  
  // p is a pixel
  sf::Color p;


  for (unsigned x=0; x< size.x; x++) {
    for (unsigned y= 0; y< size.y; y++) {
      p = image.getPixel(x, y);
      p.r = p.r ^ l.generate(8);
      p.g = p.g ^ l.generate(8);
      p.b = p.b ^ l.generate(8);
      image.setPixel(x, y, p);
    }
  }

  if (!image.saveToFile(output_file))
    return -1;
  
  sf::RenderWindow window(sf::VideoMode(2*size.x, size.y), "By Oliver Walker");

  

  sf::Texture texture2;
  texture2.loadFromImage(image);

  sf::Sprite sprite;
  sprite.setTexture(texture);
  
  sf::Sprite sprite2;
  sprite2.setTexture(texture2);
  sprite2.setPosition(sf::Vector2f(size.x, 0));

  while (window.isOpen())
    {
      sf::Event event;
      while (window.pollEvent(event))
	{
	  if (event.type == sf::Event::Closed)
	    window.close();
	}

      window.clear(sf::Color::White);
      window.draw(sprite);
      window.draw(sprite2);
      window.display();
    }

  return 0;
}
