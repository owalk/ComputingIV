#include "LFSR.hpp"

LFSR::LFSR()
{return;}

LFSR::LFSR(std::string seed, int tapPos)
{
  _seed = seed;
  _tap = tapPos;
}

int LFSR::step()
{
  int result = (_seed[0] ^ (int)_seed[_tap]);
 
  for (unsigned i= 0; i < _seed.length()-1; i++)
    _seed[i] = _seed[i+1];     
  
  char r;
  
  if(result == 0)
    r = '0';
  if(result == 1)
    r = '1';
  
  _seed[_seed.length()-1] = r;
  // std::cout << _seed << std::endl;; //uncomment this to see the seeds.
  return result;

}

int LFSR::generate(int k)
{
  int var = 0;
  for(int i=0; i<k; i++)
      var = (2*var) +  step();
   
  return var;
}

std::ostream& operator<< (std::ostream &out, LFSR &lfsr)
{
  out << lfsr._seed;  
  return out;
}
