#include <iostream>

#include "tetration.hpp"

#include <number.hpp>
#include <arithmetic.hpp>

int main(void){
  Number a("2");
  Number b("3");

  bool running = true;
  while(running){
    std::string z;
    std::cout << "> ";
    std::cin >> z;

    // Check if function 'f(' is found
    if(z.find("f(") != std::string::npos){
      int first_paren  = z.find('(');
      int comma        = z.find(',');
      int second_paren = z.find(')');

      Number a(z.substr(first_paren+1, comma-1));
      Number n(z.substr(comma+1, second_paren-1));

      
      std::cout << "a=" <<a.toString()<< " | n=" <<n.toString()<< "\n";

      Number tr = tetrate(a,n);
      std::cout << "Result: " << tr.toString() << std::endl;
    }

    // If we get quit, then exit.
    if(z.find("quit") != std::string::npos) running = false;
  }
  // std::cout << tetrate(a,b).toString() << "\n";
  return 0;
}