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
  Number res = *this;
  for(Number counter(1); counter != b; counter = counter + Number(1))
    res = res + *this;
  return res;
}

#include "arithmetic.hpp"

Number pow(Number a, Number b){
  Number res = a;
  for(Number k(1); k != b; k = k + Number(1)){
    res = res*a;
  }
  return res;
}
