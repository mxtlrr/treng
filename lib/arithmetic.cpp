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

Number Number::operator-(Number b) const{
  Number res;
  res.digits.clear();

  int borrow = 0;
  size_t maxsize = digits.size();

  for (size_t i = 0; i < maxsize; ++i) {
    int diff = digits[i] - borrow;
    if (i < b.digits.size()) diff -= b.digits[i];

    if(diff<0){
      diff+=10; borrow=1;
    } else borrow=0;

    res.digits.push_back(diff);
  }

  // Remove leading zeros
  while (res.digits.size() > 1 && res.digits.back() == 0)
    res.digits.pop_back();
  return res;
}

Number Number::operator*(Number b) const {
  Number res = *this;
  for(Number counter(1); counter != b; counter = counter + Number(1))
    res = res + *this;
  return res;
}

Number Number::operator/(Number b) const {
  Number a = *this;
  Number quotient;
  Number current;

  // Let's go through everything.
  for (int i = a.digits.size() - 1; i >= 0; --i) {
    // Okay, current digit time.
    current.digits.insert(current.digits.begin(), a.digits[i]);

    // If there's more than one digit, then we wanna remove the
    // trailing 0s
    while (current.digits.size() > 1 && current.digits.back() == 0)
      current.digits.pop_back();

    // How many times can b fit into current? Everytime it can,
    // counter goes up by 1.
    int counter = 0;
    for(;current >= b; counter++) current = current - b;

    // Insert it back in.
    quotient.digits.insert(quotient.digits.begin(), counter);
  }

  // Do the same thing
  while (quotient.digits.size() > 1 && quotient.digits.back() == 0)
    quotient.digits.pop_back();

  return quotient;
}


#include "arithmetic.hpp"

Number pow(Number a, Number b){
  Number res = a;
  for(Number k(1); k != b; k = k + Number(1)){
    res = res*a;
  }
  return res;
}
