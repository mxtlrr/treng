#include "number.hpp"


Number Number::operator+(const Number& b) const {
  Number res;
  res.digits.clear();

  int carry = 0;
  size_t maxsize = std::max(digits.size(), b.digits.size());

  for (size_t i = 0; i < maxsize || carry; ++i) {
    int sum = carry;
    if (i < digits.size()) sum += digits[i];
    if (i < b.digits.size()) sum += b.digits[i];
    res.digits.push_back(sum % 10);
    carry = sum / 10;
  }
  return res;
}

Number Number::operator*(Number& b) const {
  
  long long unsigned int counter = 1;
  Number num = *this;
  Number res = num;
  while(counter != b.toInt()){
    res = res + num;
    counter++;
  }

  return res;
}


#include "arithmetic.hpp"


std::vector<long> powersof2 = {
  2, 4, 8, 16, 32, 64,
  128, 256, 512, 1024, 2048, 4096,
  8192 /* etc */
};

bool isPow2(long power){
  for(size_t i = 0; i < powersof2.size(); i++)
    if(powersof2[i] == power) return true;
  return false;
}


Number pow(Number a, Number b){
  long long unsigned int counter = 1;

  long power = b.toInt();
  
  // Check if we're dealing with something like
  // 2^4096.
  Number res = a;
  if(isPow2(power)){
    // We are!
    // Then, let's get the smallest one that does NOT equal power.
    long result = 0;
    for(size_t i = 0; i < powersof2.size(); i++){
      if(powersof2[i] <= power && powersof2[i] != power)
        result = powersof2[i];
    }

    // Check how many iterations to do
    long iterations = (long)(power/result);

    // Do the multiplication
    long j = 1;
    Number tmp = res;

    for(long i = 0; i < iterations; i++){
      while(j != result){
        tmp = tmp * a;
        j++;
      }
      j = 0; // Reset counter
    }

    return tmp;
  }
  // Not a power of two. Find the biggest possible divisor
  // of power.
  long biggest_divisor = 1;
  for(long i = power/2; i >= 1; i--){
    if((power % i == 0) && i > biggest_divisor)
      biggest_divisor = i;
  }

  if(biggest_divisor == 1){
    // Number is prime. Just handle like usual
    while(counter != b.toInt()){
      res = res * a;
      counter+=1;
    }
    return res;
  }

  long iterations = (long)(power/biggest_divisor);
  Number tmp = res;

  long j = 1;
  for(long i = 0; i < iterations; i++){
    while(j != biggest_divisor){
      tmp = tmp * a;
      j++;
    }
    j = 0; // Reset counter
  }

  return tmp;
}