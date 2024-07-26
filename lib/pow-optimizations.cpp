#include "pow-optimizations.hpp"

std::vector<Number> powersof2 = {
  1,2,4,8,16,32,64,128,512,1024,2048,
  4096,8192,16384,32768,65536 /* etc... */
};

bool isPow2(Number p){
  for(size_t i = 0; i < powersof2.size(); i++){
    if(powersof2[i] == p) return true;
  }
  return false;
}

Number smallest_pow_2(Number p){
  Number res(1);
  for(size_t i = 0; i < powersof2.size(); i++){
    if(powersof2[i] < p) res = powersof2[i-1];
  }

  return res;
}

Number get_biggest_divisor(Number n){
  Number res(1);
  for(Number i(n/2); i >= Number(1); i = i - 1){
    if((n % i == 0) && i > res) res = i;
  }
  return res;
}

bool isPrime(Number power){
  if(get_biggest_divisor(power).toString() == "1") return true;
  return false;
}