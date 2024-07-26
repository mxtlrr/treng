#ifndef __POW_OPTIMIZATIONS_H__
#define __POW_OPTIMIZATIONS_H__

#include <number.hpp>
#include <arithmetic.hpp>

#include <iostream>
#include <vector>


typedef unsigned long long int ull;

// A list of all powers of two.
// I'll need to expand this...
extern std::vector<Number> powersof2;

// Is some power p a power of two?
bool isPow2(Number p);

// Assumes isPow2 is true. Gets the smallest
// divisor d of some power such that d<p.
Number smallest_pow_2(Number p);

Number get_biggest_divisor(Number n);

// Gets the state on whether or not a number is prime or not.
bool isPrime(Number power);



#endif