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
    
    // convert string to a Number type
    void fromString(std::string num);
    
    // convert from scientific notation to the Number type.
    // note that I am too lazy to actually code stuff, so this only supports
    // positive scientific notation number. for example, 1e2 = 1*10^2 = 100.
    void fromSciNotation(std::string num);
  public:
    std::vector<unsigned char> digits;
    Number(): digits(1,0){}
    Number(std::string num);
		Number(int num);

    /* Conversion */
    std::string toString();
    long long unsigned int toInt();

    /* Arithmetic. */
    Number operator+(Number b)      const;       // a+b
    Number operator-(Number b)      const;       // a-b
    Number operator*(Number b)      const;       // a*b
    Number operator/(Number divisor) const;      // a/b

    /* Comparison operators */
    bool operator==(Number b);
    inline bool operator!=(Number &l){ return !(*this==l); }
    
    /* Relation operators */
    bool operator>=(Number b);
    inline bool operator>(Number b){ return (*this>=b); }

    bool operator<=(Number b);
    inline bool operator<(Number b){ return (*this<=b); }

    /* Other */
    Number operator%(Number b) const; // a%b
};

#endif
