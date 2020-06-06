#include "Script.hpp"

void Script::update(struct Gamestate *gstate){
      if(gstate -> time > this -> lastTime + 10){
            this -> lastTime = gstate -> time;
            this -> points += gstate -> time;

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
                        this->event11();
                        break;
                  case 13:
                        this->event11();
                        break;
            }
      }
}

void Script::event1(){
      this -> instanciateList.push_back(new Mechant(new Forme(200,-100,"Formes/Models/M1.txt"),new Trajectoire(0,50,200,0,5,0)));
      this -> instanciateList.push_back(new Mechant(new Forme(200,-200,"Formes/Models/M1.txt"),new Trajectoire(0,50,200,0,5,0)));
      this -> instanciateList.push_back(new Mechant(new Forme(200,-300,"Formes/Models/M1.txt"),new Trajectoire(0,50,200,0,5,0)));
}

void Script::event2(){
      this -> instanciateList.push_back(new Mechant(new Forme(400,-100,"Formes/Models/M1.txt"),new Trajectoire(0,50,200,0,5,0)));
      this -> instanciateList.push_back(new Mechant(new Forme(400,-200,"Formes/Models/M1.txt"),new Trajectoire(0,50,200,0,5,0)));
      this -> instanciateList.push_back(new Mechant(new Forme(400,-300,"Formes/Models/M1.txt"),new Trajectoire(0,50,200,0,5,0)));
}

void Script::event3(){
      this -> instanciateList.push_back(new Mechant(new Forme(100,-100,"Formes/Models/M1.txt"),new Trajectoire(0,50,200,0,5,0)));
      this -> instanciateList.push_back(new Mechant(new Forme(300,-100,"Formes/Models/M1.txt"),new Trajectoire(0,50,200,0,5,0)));
      this -> instanciateList.push_back(new Mechant(new Forme(500,-100,"Formes/Models/M1.txt"),new Trajectoire(0,50,200,0,5,0)));
}

void Script::event4(){
      this -> instanciateList.push_back(new Mechant(new Forme(300,-100,"Formes/Models/M1.txt"),new Trajectoire(0,50,200,0,5,0)));
      this -> instanciateList.push_back(new Mechant(new Forme(300,-200,"Formes/Models/M1.txt"),new Trajectoire(0,50,200,0,5,0)));
      this -> instanciateList.push_back(new Mechant(new Forme(300,-300,"Formes/Models/M1.txt"),new Trajectoire(0,50,200,0,5,0)));
}

void Script::event5(){
      this -> instanciateList.push_back(new Mechant(new Forme(300,-100,"Formes/Models/M1.txt"),new Trajectoire(0,50,200,0,5,0)));
      this -> instanciateList.push_back(new Mechant(new Forme(300,-200,"Formes/Models/M1.txt"),new Trajectoire(0,50,200,0,5,0)));
      this -> instanciateList.push_back(new Mechant(new Forme(300,-300,"Formes/Models/M1.txt"),new Trajectoire(0,50,200,0,5,0)));
}

void Script::event6(){
      this -> instanciateList.push_back(new Mechant(new Forme(300,-100,"Formes/Models/M1.txt"),new Trajectoire(0,50,200,0,5,0)));
      this -> instanciateList.push_back(new Mechant(new Forme(300,-200,"Formes/Models/M1.txt"),new Trajectoire(0,50,200,0,5,0)));
      this -> instanciateList.push_back(new Mechant(new Forme(300,-300,"Formes/Models/M1.txt"),new Trajectoire(0,50,200,0,5,0)));
}

void Script::event7(){
      this -> instanciateList.push_back(new Mechant(new Forme(300,-100,"Formes/Models/M1.txt"),new Trajectoire(0,50,200,0,5,0)));
      this -> instanciateList.push_back(new Mechant(new Forme(300,-200,"Formes/Models/M1.txt"),new Trajectoire(0,50,200,0,5,0)));
      this -> instanciateList.push_back(new Mechant(new Forme(300,-300,"Formes/Models/M1.txt"),new Trajectoire(0,50,200,0,5,0)));
}

void Script::event8(){
      this -> instanciateList.push_back(new Mechant(new Forme(300,-100,"Formes/Models/M1.txt"),new Trajectoire(0,50,200,0,5,0)));
      this -> instanciateList.push_back(new Mechant(new Forme(300,-200,"Formes/Models/M1.txt"),new Trajectoire(0,50,200,0,5,0)));
      this -> instanciateList.push_back(new Mechant(new Forme(300,-300,"Formes/Models/M1.txt"),new Trajectoire(0,50,200,0,5,0)));
}

void Script::event9(){
      this -> instanciateList.push_back(new Mechant(new Forme(300,-100,"Formes/Models/M1.txt"),new Trajectoire(0,50,200,0,5,0)));
      this -> instanciateList.push_back(new Mechant(new Forme(300,-200,"Formes/Models/M1.txt"),new Trajectoire(0,50,200,0,5,0)));
      this -> instanciateList.push_back(new Mechant(new Forme(300,-300,"Formes/Models/M1.txt"),new Trajectoire(0,50,200,0,5,0)));
}
void Script::event10(){
      this -> instanciateList.push_back(new Mechant(new Forme(-66,-100,"Formes/Models/M2.txt"),new Trajectoire(200,300,0,0,0,0)));
      this -> instanciateList.push_back(new Mechant(new Forme(-99,-150,"Formes/Models/M2.txt"),new Trajectoire(200,300,0,0,0,0)));
      this -> instanciateList.push_back(new Mechant(new Forme(-132,-200,"Formes/Models/M2.txt"),new Trajectoire(200,300,0,0,0,0)));
}
void Script::event11(){
      this -> instanciateList.push_back(new Mechant(new Forme(666,-100,"Formes/Models/M2.txt"),new Trajectoire(-200,300,0,0,0,0)));
      this -> instanciateList.push_back(new Mechant(new Forme(699,-150,"Formes/Models/M2.txt"),new Trajectoire(-200,300,0,0,0,0)));
      this -> instanciateList.push_back(new Mechant(new Forme(732,-200,"Formes/Models/M2.txt"),new Trajectoire(-200,300,0,0,0,0)));
}
void Script::event12(){
      this -> instanciateList.push_back(new Mechant(new Forme(0,-100,"Formes/Models/M2.txt"),new Trajectoire(0,300,600,0,1/3,0)));
      this -> instanciateList.push_back(new Mechant(new Forme(0,-150,"Formes/Models/M2.txt"),new Trajectoire(0,300,600,0,1/3,0)));
      this -> instanciateList.push_back(new Mechant(new Forme(0,-200,"Formes/Models/M2.txt"),new Trajectoire(0,300,600,0,1/3,0)));
}
void Script::event13(){
      this -> instanciateList.push_back(new Mechant(new Forme(600,-100,"Formes/Models/M2.txt"),new Trajectoire(0,300,-600,0,1/3,0)));
      this -> instanciateList.push_back(new Mechant(new Forme(600,-150,"Formes/Models/M2.txt"),new Trajectoire(0,300,-600,0,1/3,0)));
      this -> instanciateList.push_back(new Mechant(new Forme(600,-200,"Formes/Models/M2.txt"),new Trajectoire(0,300,-600,0,1/3,0)));
}
