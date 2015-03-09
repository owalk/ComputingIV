
#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(600, 600), "SFML works!  And I did stuff!!");
    sf::CircleShape shape(80, 3);
    shape.setFillColor(sf::Color::Green);
    shape.setPosition(8000, 600);
    sf::Clock clock;
    sf::Time time;
    sf::Time t1 = sf::seconds(2);
    sf::Time t2 = sf::seconds(4);
    sf::Texture texture;

    if(!texture.loadFromFile("sprite.png"))
      {
	//error
	return -1;
      }
    sf::Sprite sprite;
    sprite.setTexture(texture);

    while (window.isOpen())
    {
      
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
	
	time = clock.getElapsedTime();

	if(time < t1){
	  shape.setPosition(300, 50);
	}

	if(time > t1){
	  shape.setPosition(400, 400);
	}
	
	if(time > t2)
	  clock.restart();

	switch(event.type)
	  {
	  case sf::Event::KeyPressed:
	    if(event.key.code == sf::Keyboard::Right)
	      shape.rotate(-10);
	    if(event.key.code == sf::Keyboard::Left)
	      shape.rotate(10);
	     if(event.key.code == sf::Keyboard::Down)
	       shape.move(5, 5);
	    if(event.key.code == sf::Keyboard::Up)
	       shape.move(-5, -5);
	    break;
	  }

        window.clear();
	window.draw(sprite);
        window.draw(shape);
        window.display();
    }

    return 0;
}
