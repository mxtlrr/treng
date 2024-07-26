#include "number.hpp"


Number Number::operator+(Number b) const {
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

Number Number::operator*(Number b) const {
  // (#3)
  // Instead, we can use a Number type for a coutner.
  Number counter(1);
  Number one(1);

  Number num = *this;
  Number res = num;
  while(counter != b){
    res = res + num;
    counter = counter + one;
  }

  return res;
}


/* Comparison operators */
bool Number::operator==(Number b){
  std::vector<uc> digits_a = this->digits;
  std::vector<uc> digits_b = b.digits;

  if(digits_a.size() != digits_b.size()) return false;
  
  // Check if every digit in digits_a corresponds to the same
  // digit in digits_b
  std::vector<uc> correct_digits;
  for(size_t n = 0; n != digits_a.size(); n++){
    if(digits_a[n] == digits_b[n]){
      correct_digits.push_back(1);
    }
  }

  // If correct_digits.size() = digits_[a/b].size(), then
  // we have the correct value.
  if(correct_digits.size() == digits_a.size()) return true;
  return false;
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


std::vector<Number> powersof2_num = {
  Number(2), Number(4), Number(8), Number(16), Number(32), Number(64),
  Number(128), Number(256), Number(512), Number(1024), Number(2048), Number(4096),
  Number(8192) /* etc */
};

bool isPow2_num(Number power){
  for(size_t i = 0; i < powersof2_num.size(); i++){
    if(powersof2_num[i] == power) return true;
  }
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
    // This specific line causes an arithmetic exception. 
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
    // Number is prime. Just handle like usual.
    // TODO: fix a warning here.
    while(counter != power){
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