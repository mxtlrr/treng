#ifndef __NUMBER_H__
#define __NUMBER_H__

#include <iostream>
#include <vector>
#include <string>

typedef unsigned char uc;

class Number {
  private:
    /* Every digit is stored as an unsigned character (255) in a vector.
     * They're stored in reverse, i.e. "1000" would be stored as "0001"
     * **This is to make arithmetic easier.***/
    std::vector<unsigned char> digits;
    
    // convert string to a Number type
    void fromString(std::string num);
    
    // convert from scientific notation to the Number type.
    // note that I am too lazy to actually code stuff, so this only supports
    // positive scientific notation number. for example, 1e2 = 1*10^2 = 100.
    void fromSciNotation(std::string num);
  public:
    Number(): digits(1,0){}
    Number(std::string num);
		Number(int num);

    /* Conversion */
    std::string toString();
    long long unsigned int toInt();

    /* Arithmetic. */
    Number operator+(Number b) const;            // a+b
    Number operator*(Number b) const;            // a*b
    
    // This is so so stupid! Do NOT DO THIS
    // FIX!!!
    inline Number operator-(Number b){
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

    /* Comparison operators */
    bool operator==(Number b);
    inline bool operator!=(Number &l){ return !(*this==l); }
};

#endif
