#include "tetration.hpp"

Number tetrate(Number a, Number n){
  Number one("1");
  
  // Base case. If n=0, return 1
  if(n.toInt() == 0){
    Number empty("1");
    return empty;
  }

  // Else, return pow(tetrate(a, n-1))
  return pow(a, tetrate(a, n-one));
}