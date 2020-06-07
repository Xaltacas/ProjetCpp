#include "Script.hpp"

void Script::update(struct Gamestate *gstate){
      if(gstate -> time > this -> lastTime + this -> eventDelay){
            this -> lastTime = gstate -> time;
            this -> points += gstate -> time * 0.7;

            int e = rand() % this -> nbEvent ;

            while ((this -> eventCost[e] > this -> points) &&  e !=0){
                  e = rand() % e;
            }

            switch (e) {
                  case 0:
                        break;
                  case 1:
                        this->event1();
                        break;
                  case 2:
                        this->event2();
                        break;
                  case 3:
                        this->event3();
                        break;
                  case 4:
                        this->event4();
                        break;
                  case 5:
                        this->event5();
                        break;
                  case 6:
                        this->event6();
                        break;
                  case 7:
                        this->event7();
                        break;
                  case 8:
                        this->event8();
                        break;
                  case 9:
                        this->event9();
                        break;
                  case 10:
                        this->event10();
                        break;
                  case 11:
                        this->event11();
                        break;
                  case 12:
                        this->event12();
                        break;

            }
      }
}

void Script::event1(){
      this -> instanciateList.push_back(new Mechant1(200,-100));
      this -> instanciateList.push_back(new Mechant1(200,-200));
      this -> instanciateList.push_back(new Mechant1(200,-300));
}

void Script::event2(){
      this -> instanciateList.push_back(new Mechant1(400,-100));
      this -> instanciateList.push_back(new Mechant1(400,-200));
      this -> instanciateList.push_back(new Mechant1(400,-300));
}

void Script::event3(){
      this -> instanciateList.push_back(new Mechant1(100,-100));
      this -> instanciateList.push_back(new Mechant1(300,-100));
      this -> instanciateList.push_back(new Mechant1(500,-100));
}

void Script::event4(){
      this -> instanciateList.push_back(new Mechant2_1(-66,-100));
      this -> instanciateList.push_back(new Mechant2_1(-99,-150));
      this -> instanciateList.push_back(new Mechant2_1(-132,-200));

}

void Script::event5(){
      this -> instanciateList.push_back(new Mechant2_2(666,-100));
      this -> instanciateList.push_back(new Mechant2_2(699,-150));
      this -> instanciateList.push_back(new Mechant2_2(732,-200));

}

void Script::event6(){
      this -> instanciateList.push_back(new Mechant1(100,-100));
      this -> instanciateList.push_back(new Mechant1(200,-100));
      this -> instanciateList.push_back(new Mechant1(300,-100));
      this -> instanciateList.push_back(new Mechant1(400,-100));
      this -> instanciateList.push_back(new Mechant1(500,-100));
}

void Script::event7(){
      this -> instanciateList.push_back(new Mechant2_1(-66,-100));
      this -> instanciateList.push_back(new Mechant2_1(-99,-150));
      this -> instanciateList.push_back(new Mechant2_1(-132,-200));
      this -> instanciateList.push_back(new Mechant2_1(-132,-100));
      this -> instanciateList.push_back(new Mechant2_1(-165,-150));
      this -> instanciateList.push_back(new Mechant2_1(-198,-200));
}

void Script::event8(){
      this -> instanciateList.push_back(new Mechant2_2(666,-100));
      this -> instanciateList.push_back(new Mechant2_2(699,-150));
      this -> instanciateList.push_back(new Mechant2_2(732,-200));
      this -> instanciateList.push_back(new Mechant2_2(699,-100));
      this -> instanciateList.push_back(new Mechant2_2(732,-150));
      this -> instanciateList.push_back(new Mechant2_2(765,-200));
}

void Script::event9(){
      this -> instanciateList.push_back(new Mechant3(100,-100));
      this -> instanciateList.push_back(new Mechant3(300,-100));
      this -> instanciateList.push_back(new Mechant3(500,-100));
}

void Script::event10(){
      this -> instanciateList.push_back(new Mechant4(300,-100));
}

void Script::event11(){
      this -> instanciateList.push_back(new Mechant3(100,-250));
      this -> instanciateList.push_back(new Mechant3(300,-50));
      this -> instanciateList.push_back(new Mechant3(500,-250));
      this -> instanciateList.push_back(new Mechant3(300,-450));
}

void Script::event12(){
      if(this -> eventDelay > 1){
            this -> eventDelay--;
      }
      else{
            this -> event8();
            this -> event7();
            this -> event10();
      }
}
