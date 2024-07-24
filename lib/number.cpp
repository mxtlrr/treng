#include "number.hpp"

Number::Number(const std::string num){
  if(num.find("e") != std::string::npos) {
    fromSciNotation(num);
  } else {
    fromString(num);
  }
}

Number::Number(int num){
	fromString(std::to_string(num)); // Stupid but also works
}

void Number::fromString(const std::string num){
  // Clear vector in case something weird happened
  digits.clear();

  for(int i = num.size()-1; i >= 0; i--){
    if(isdigit(num[i])){ // Digit? push to vector.
      digits.push_back(num[i] - '0');
    }
  }
}

void Number::fromSciNotation(std::string num){
  int loc = num.find('e');
  
  std::string base = num.substr(0, loc);
  int          exp = std::stoi(num.substr(loc+1));

  fromString(base);

  if(exp>0){
    // Add zeros for positive exponent.
    for(int i=0;i<exp;i++)
      digits.insert(digits.begin(), 0);
  }

}

std::string Number::toString() {
  std::string result;
  for (auto it = digits.rbegin(); it != digits.rend(); ++it) {
    // *it has the current digit. We then use std::to_string to
    // convert it to a string, and add it to a string.
    result += std::to_string(*it);
  }
  return result.empty() ? "0" : result;
}


long long unsigned int Number::toInt(){
  return std::stoull(this->toString());
}
