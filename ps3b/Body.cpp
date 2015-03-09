//Body.cpp
#include "Body.hpp"

body::body(int s)
{screen_size = s;}

int body::coordinate_convert(double coordinate, int screen_size)
{
  int new_coordinate;
  new_coordinate = (screen_size/2) + coordinate*1e-9;
  return new_coordinate;
}

void body::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
  sf::Sprite  sprite;
  
  sprite.setTexture(_planet_image);
  sprite.setPosition(x_pixle, y_pixle);
  target.draw(sprite, states);
}

std::istream& operator>>(std::istream &input, body &object)
{
  double x, y;
  input >> x;
  input >> y;
  object._x_pos = x;
  object._y_pos = y;
  object.x_pixle = object.coordinate_convert(x, object.screen_size);
  object.y_pixle = object.coordinate_convert(y, object.screen_size);
  input >> object._x_velocity;
  input >> object._y_velocity;
  input >> object._mass;
  input >> object.file_name;

  if (!object._planet_image.loadFromFile(object.file_name))
    std::cout << object.file_name <<" could not be loaded!" << std::endl;

  return input;
}

double body::get_xvel()
{return _x_velocity;}
double body::get_yvel()
{return _y_velocity;}
double body::get_xpos()
{return _x_pos;}
double body::get_ypos()
{return _y_pos;}
double body::getMass()
{return _mass;}
void body::set_xvel(double thing)
{_x_velocity = thing;
  return;}
void body::set_yvel(double thing)
{_y_velocity = thing;
  return;}
void body::set_xpos(double thing)
{_x_pos = thing;
  return;}

void body::set_ypos(double thing)
{_y_pos = thing;
  return;}


void universe::setBody(body* B) {
  std::cin >> *B;
  bodies.push_back(B);
  return;
}

void universe::movement(){
  
  const double GFORCE = 6.67384e-11;
  std::vector<double> xforce, yforce;
  std::vector<double> x, y;
  double temp, deltaX, deltaY, xacc, yacc, xvel, yvel, xpos, ypos, radius;
  
  for(unsigned k = 0; k < bodies.size(); k++){
    xforce.push_back(0);
    yforce.push_back(0);
    x.push_back(0);
    y.push_back(0);    
  }
  
  for(unsigned i = 0; i < bodies.size(); i++){
    for(unsigned j = 0; j < bodies.size(); j++){
      if(i != j){
        deltaX = bodies[j]->get_xpos() - bodies[i]->get_xpos();
        deltaY = bodies[j]->get_ypos() - bodies[i]->get_ypos();

        radius = sqrt(pow(deltaX, 2) + pow(deltaY, 2));

        temp = ((GFORCE*bodies[i]->getMass()*bodies[j]->getMass())/pow(radius, 2));

        xforce[i] += temp * (deltaX/radius);
        yforce[i] += temp * (deltaY/radius);
      }
    }
  }
   
  for(unsigned i = 0; i < bodies.size(); i++) {
    xacc = xforce[i]/bodies[i]->getMass();
    yacc = yforce[i]/bodies[i]->getMass();
    
    xvel = bodies[i]->get_xvel() + (xacc * (double)_time);
    yvel = bodies[i]->get_yvel() + (yacc * (double)_time);
    bodies[i]->set_xvel(xvel);
    bodies[i]->set_yvel(yvel);
    
    xpos = (bodies[i]->get_xpos() + (bodies[i]->get_xvel() * (double)_time));
    ypos = (bodies[i]->get_ypos() + (bodies[i]->get_yvel() * (double)_time));
    x[i] = xpos;
    // std::cout << xpos << std::endl;
    y[i] = ypos;
    // std::cout << ypos << std::endl;
  }
  
  for(unsigned l = 0; l < bodies.size(); l++){
    bodies[l]->set_xpos(x[l]);
    bodies[l]->set_ypos(y[l]);
    bodies[l]->setpixelx(bodies[l]->coordinate_convert(bodies[l]->get_xpos(), bodies[l]->get_screen_size()));
    bodies[l]->setpixely(bodies[l]->coordinate_convert(bodies[l]->get_ypos(), bodies[l]->get_screen_size()));
   
  }
  
  return;
}


universe::universe(int my_time)
{
  _time = my_time;
  return;
}

unsigned universe::getNumBodies ()
{
  return bodies.size();
}

body universe::getBody(unsigned i)
{
  return *(bodies[i]);
}

int body::get_screen_size()
{
  return screen_size;
}
void body::setpixelx(double newPixle)
{
  x_pixle = newPixle;
  return;
}
void body::setpixely(double newPixle)
{
  y_pixle = newPixle;
  return;
}
