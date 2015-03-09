#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

class ED{
public:
  ED(std::string a, std::string b);
  static unsigned penalty(char a, char b);
  static unsigned min(unsigned a, unsigned b, unsigned c);
  int optDistance(); //populates matrix based on two strings. returns optimal
                     //distance
  std::string alignment();
  friend std::istream& operator>>(std::istream &input, ED &object);
 

  // ED(std::string A, std::string B);
  //int compare(char a, char b);
private:
  std::vector < std::vector < unsigned > > DNA;
  std::string _a, _b;
  //int optimalDistance, nextSpot
};
