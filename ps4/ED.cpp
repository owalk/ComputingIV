#include "ED.hpp"

ED::ED(std::string a, std::string b): _a(a), _b(b)
{}

unsigned ED::penalty(char a, char b)
{
  if(a != b)
    return 1;

  return 0;
}

unsigned ED::min(unsigned a, unsigned b, unsigned c)
{
  unsigned result = a;

  if (b < result)
    result = b;
  if (c < result)
    result = c;
  
  return result;
}

int ED::optDistance()
{
  int route1, route2, route3;

  for (unsigned i = 0; i <= _a.length(); i++) {
    std::vector<unsigned> row; // Create an empty row
    for (unsigned j = 0; j <= _b.length(); j++) {
      if(j == 0)
        row.push_back(2 * i);
      if(i == 0)
        row.push_back(2 * j + 2);
      else
        row.push_back(0);
    }
    DNA.push_back(row); // Add the row to the main vector
}
  
  for (unsigned i= 1; i <= _a.length(); i++){
    for (unsigned j= 1; j <= _b.length(); j++){
      
      route1 = DNA[i-1][j] + 2; //looks at row above
      route2 = DNA[i][j-1] + 2; //looks at column to the left

      route3 = penalty(_a[i-1] , _b[j-1]) + DNA[i-1][j-1];    
      
      DNA[i][j] = min(route1, route2, route3);
      
    }
  }
  
  
   for (unsigned i= 0; i <= _a.length(); i++){

    for (unsigned j= 0; j <= _b.length(); j++){
      std::cout << " " << DNA[i][j] << " ";
    }
    std::cout << std::endl;
   }
 
  
   return 800;
}

