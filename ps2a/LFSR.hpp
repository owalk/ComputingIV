#include <iostream>
#include <string>
#include <sstream>
class LFSR
{
public:
  LFSR();
  LFSR(std::string seed, int tapPos);
  int step();
  int generate(int k);

  friend std::ostream& operator<< (std::ostream &out, LFSR &lfsr);

private:
  std::string _seed;
  int _tap;
};
