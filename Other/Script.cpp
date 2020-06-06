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
            }
      }
}

void Script::event1(){
      this -> instanciateList.push_back(new Mechant(new Forme(200,-100,"Formes/Models/J2.txt"),new Trajectoire(0,50,200,0,5,0)));
      this -> instanciateList.push_back(new Mechant(new Forme(200,-200,"Formes/Models/J2.txt"),new Trajectoire(0,50,200,0,5,0)));
      this -> instanciateList.push_back(new Mechant(new Forme(200,-300,"Formes/Models/J2.txt"),new Trajectoire(0,50,200,0,5,0)));
}

void Script::event2(){
      this -> instanciateList.push_back(new Mechant(new Forme(400,-100,"Formes/Models/J2.txt"),new Trajectoire(0,50,200,0,5,0)));
      this -> instanciateList.push_back(new Mechant(new Forme(400,-200,"Formes/Models/J2.txt"),new Trajectoire(0,50,200,0,5,0)));
      this -> instanciateList.push_back(new Mechant(new Forme(400,-300,"Formes/Models/J2.txt"),new Trajectoire(0,50,200,0,5,0)));
}

void Script::event3(){
      this -> instanciateList.push_back(new Mechant(new Forme(100,-100,"Formes/Models/J2.txt"),new Trajectoire(0,50,200,0,5,0)));
      this -> instanciateList.push_back(new Mechant(new Forme(300,-100,"Formes/Models/J2.txt"),new Trajectoire(0,50,200,0,5,0)));
      this -> instanciateList.push_back(new Mechant(new Forme(500,-100,"Formes/Models/J2.txt"),new Trajectoire(0,50,200,0,5,0)));
}

void Script::event4(){
      this -> instanciateList.push_back(new Mechant(new Forme(300,-100,"Formes/Models/J2.txt"),new Trajectoire(0,50,200,0,5,0)));
      this -> instanciateList.push_back(new Mechant(new Forme(300,-200,"Formes/Models/J2.txt"),new Trajectoire(0,50,200,0,5,0)));
      this -> instanciateList.push_back(new Mechant(new Forme(300,-300,"Formes/Models/J2.txt"),new Trajectoire(0,50,200,0,5,0)));
}

void Script::event5(){
      this -> instanciateList.push_back(new Mechant(new Forme(300,-100,"Formes/Models/J2.txt"),new Trajectoire(0,50,200,0,5,0)));
      this -> instanciateList.push_back(new Mechant(new Forme(300,-200,"Formes/Models/J2.txt"),new Trajectoire(0,50,200,0,5,0)));
      this -> instanciateList.push_back(new Mechant(new Forme(300,-300,"Formes/Models/J2.txt"),new Trajectoire(0,50,200,0,5,0)));
}

void Script::event6(){
      this -> instanciateList.push_back(new Mechant(new Forme(300,-100,"Formes/Models/J2.txt"),new Trajectoire(0,50,200,0,5,0)));
      this -> instanciateList.push_back(new Mechant(new Forme(300,-200,"Formes/Models/J2.txt"),new Trajectoire(0,50,200,0,5,0)));
      this -> instanciateList.push_back(new Mechant(new Forme(300,-300,"Formes/Models/J2.txt"),new Trajectoire(0,50,200,0,5,0)));
}

void Script::event7(){
      this -> instanciateList.push_back(new Mechant(new Forme(300,-100,"Formes/Models/J2.txt"),new Trajectoire(0,50,200,0,5,0)));
      this -> instanciateList.push_back(new Mechant(new Forme(300,-200,"Formes/Models/J2.txt"),new Trajectoire(0,50,200,0,5,0)));
      this -> instanciateList.push_back(new Mechant(new Forme(300,-300,"Formes/Models/J2.txt"),new Trajectoire(0,50,200,0,5,0)));
}

void Script::event8(){
      this -> instanciateList.push_back(new Mechant(new Forme(300,-100,"Formes/Models/J2.txt"),new Trajectoire(0,50,200,0,5,0)));
      this -> instanciateList.push_back(new Mechant(new Forme(300,-200,"Formes/Models/J2.txt"),new Trajectoire(0,50,200,0,5,0)));
      this -> instanciateList.push_back(new Mechant(new Forme(300,-300,"Formes/Models/J2.txt"),new Trajectoire(0,50,200,0,5,0)));
}

void Script::event9(){
      this -> instanciateList.push_back(new Mechant(new Forme(300,-100,"Formes/Models/J2.txt"),new Trajectoire(0,50,200,0,5,0)));
      this -> instanciateList.push_back(new Mechant(new Forme(300,-200,"Formes/Models/J2.txt"),new Trajectoire(0,50,200,0,5,0)));
      this -> instanciateList.push_back(new Mechant(new Forme(300,-300,"Formes/Models/J2.txt"),new Trajectoire(0,50,200,0,5,0)));
}
