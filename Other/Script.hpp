#ifndef SCRIPT_HPP
#define SCRIPT_HPP

#include "../Entites/Entite.hpp"
#include "Gamestate.hpp"

class Script{

public:
      std::vector<Entite*> instanciateList;

      void update(struct Gamestate *gstate);

};


#endif
