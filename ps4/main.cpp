#include "ED.hpp"

int main()
{
  std::string string1 = "cgt";
  std::string string2 = "cat";
  ED Distance(string1, string2);

  Distance.optDistance();
  
  return 1;

}
