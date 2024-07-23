#ifndef __NUMBER_H__
#define __NUMBER_H__

#include <iostream>
#include <vector>
#include <string>

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
    Number(std::string num);

    /* Conversion */
    std::string toString();
};

#endif