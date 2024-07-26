/* A more consice way of defining operators for the Number class.
 * If it relates to basic arithmetic, +, -, *, /, then it goes in
 * arithmetic.cpp, else, it goes here. */

#include <number.hpp>

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


/* Relational operators */
bool Number::operator>=(Number b){
  Number a = *this;

  // Base cases
  if(digits.size() > b.digits.size())      return true;  // a is greater than b.
  else if(digits.size() < b.digits.size()) return false; // a is less than b.

  // Check each value of the digits, they should be the same.
  for(size_t i = a.digits.size()-1;i >= 0; --i){
    // Is anyone digit greater than the other?
    if(digits[i] > b.digits[i]) return true; // Yes! a is bigger than b.
    if(digits[i] < b.digits[i]) return false; // No. a is smaller than b.
  }

  // Still here? Numbers are equal.
  return true;
}

bool Number::operator<=(Number b){
  return !(*this>=b);
}


/* Other operators, i.e. ++, --, etc. */