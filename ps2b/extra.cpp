#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "LFSR.hpp"

std::string convert(std::string s);
char changer(char c);

int main(int argc, char* argv[])
{

  
  std::string input_file;
  std::string output_file;
  std::string password;
  std::string binary_password;
  
  if(argc < 4)
    {
      std::cout << "programs expected more  arguments." << std::endl
                << "ps2b [input_file] [output_file] [password]" << std::endl;
      return -1;
    }
  
  input_file = argv[1];
  output_file = argv[2];
  password = argv[3];

  binary_password = convert(password);

  LFSR l(binary_password, password.length());
  
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

std::string convert(std::string s)
{
  std::string new_s = "0101010001010101110101010111110000111111000011000111111011111000111011010101110001010100011110101010";
 
   for (unsigned i = 0; i < s.length(); i++)
     {
       new_s[i] = changer(s[i]);
     }
   
   return new_s;
}

char changer(char c)
{
  char new_c;

  switch (c)
    {
    case 'a':
    case 'A':
    case 'b':
    case 'B':
    case 'c':
    case 'C':
    case 'd':
    case 'D':
    case 'e':
    case'f':
    case'g':
    case'h':
    case'i':
    case'j':
    case'k':
    case'l':
    case'm':
    case'n':
    case'o':
    case'p':
    case'q':
    case'r':
    case 's':
    case't':
    case'u':
    case'v':
      new_c = '1';
      break;
      
    case'w':
    case'x':
    case'y':
    case'z':
    case'F':
    case'G':
    case'H':
    case'I':
    case'J':
    case'K':
    case'L':
    case'M':
    case'N':
    case'O':
    case'P':
    case'Q':
    case'R':
    case'S':
    case'T':
    case'U':
    case'V':
    case'W':
    case'X':
    case'Y':
    case'Z':
      new_c = '0';
    }
  
  return new_c;
}
