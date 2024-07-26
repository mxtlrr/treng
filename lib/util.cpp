#include "util.hpp"

std::string numToSciNotation(Number n){
  std::vector<uc> d = n.digits;
  if(d.size() <= MIN_DIGITS+1) return n.toString();

  // Get the base of the number.
  // I.e. 4000000000 => 4 * 10^9
  Number base(d.size()-1);
  
  // Then get both:
  // 1. The first number
  // 2. The first 5 numbers after the first number
  Number firstNum(n.toString().substr(0,1));
  Number details(n.toString().substr(1,6));

  std::string z = firstNum.toString() + "." + details.toString()
                  + " * 10^" + base.toString();
  return z;
}