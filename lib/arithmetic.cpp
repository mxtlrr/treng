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
  
  int counter = 1;
  Number num = *this;
  Number res = num;
  while(counter != std::stoi(b.toString())){
    res = res + num;
    counter++;
  }

  return res;
}

#include "arithmetic.hpp"

Number pow(Number a, Number b){
  int counter = 1;
  Number res = a;
  while(counter != b.toInt()){
    res = res * a;
    counter+=1;
  }

  return res;
}