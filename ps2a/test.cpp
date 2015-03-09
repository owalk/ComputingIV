#include "LFSR.hpp"

//Link to Boost
#define BOOST_TEST_DYN_LINK

//Define our Module name (prints at testing)
#define BOOST_TEST_MODULE main

#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(generateFiveBitsTapAtThree) {
  LFSR l("010101", 4);
  BOOST_REQUIRE(l.generate(8) == 248);
}

BOOST_AUTO_TEST_CASE(fourBitsTapAtTwo) {
  LFSR l("1101", 2);
  BOOST_REQUIRE(l.step() == 1);
  BOOST_REQUIRE(l.step() == 0);
  BOOST_REQUIRE(l.step() == 1);
}

BOOST_AUTO_TEST_CASE(fiveBitsTapAtTwo) {

  LFSR l("00111", 2); 
  std::stringstream buf;
  buf << l;
  BOOST_REQUIRE(buf.str().compare("00111") == 0);
  
  BOOST_REQUIRE(l.step() == 1);
  BOOST_REQUIRE(l.step() == 1);
  BOOST_REQUIRE(l.step() == 0);
  BOOST_REQUIRE(l.step() == 0);
  BOOST_REQUIRE(l.step() == 0);
  BOOST_REQUIRE(l.step() == 1);
  BOOST_REQUIRE(l.step() == 1);
  BOOST_REQUIRE(l.step() == 0);

  LFSR l2("00111", 2);
  BOOST_REQUIRE(l2.generate(8) == 198);
}

BOOST_AUTO_TEST_CASE(thirteenBitsTapAtSix) {
  
  LFSR l3("1110000111001", 6);
  BOOST_REQUIRE(l3.step() == 1);
  BOOST_REQUIRE(l3.step() == 0);
  BOOST_REQUIRE(l3.step() == 0);
}

BOOST_AUTO_TEST_CASE(thirtytwoBitsTapAtFour) 
{

  LFSR l("11000011100100011100000101001111",4);
  BOOST_REQUIRE(l.step() == 1);
  BOOST_REQUIRE(l.step() == 1);
  BOOST_REQUIRE(l.step() == 1);
  BOOST_REQUIRE(l.step() == 1);
  BOOST_REQUIRE(l.step() == 1);
  BOOST_REQUIRE(l.step() == 0);

}

