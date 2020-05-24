

#ifndef DPRINT_HPP
#define DPRINT_HPP

#include <iostream>

void dPrint(char* message){
      #ifdef DEBUG
      std::cout << message << std::endl;
      #endif
}

#endif
