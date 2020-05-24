#include <iostream>

void dPrint(char* message){
      #ifdef DEBUG
      std::cout << message << std::endl;
      #endif
}
