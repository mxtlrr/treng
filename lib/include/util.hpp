#ifndef __UTIL_H__
#define __UTIL_H__

#include <number.hpp>
#include <arithmetic.hpp>

#define MIN_DIGITS 9

/* Some utilities for managing output / debugging */


// Convert n.digits (where n is a Number) to scientific notation,
// iff n.digits > 10. Else, it'll just output toString(n.digits).
std::string numToSciNotation(Number n);

#endif