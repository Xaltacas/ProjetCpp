#ifndef GAMESTATE_HPP
#define GAMESTATE_HPP

#define MAX_ENTITY 150 // le nombre d'entité a été limité pour pouvoir créer statiquement les matrice de collsion et eviter des réalocation mémoir à chaque cycle

/*
structure utilisée pour représenter l'etat du jeu à un instant t
*/
struct Gamestate{

      //etat initial du gamestate
      Gamestate(){
            time = 0;
            dt = 0;
            sizeX = 600;
            sizeY = 900;
            maxEntity = MAX_ENTITY;
            entityCount = 0;
            for(int i = 0; i < MAX_ENTITY; i++){
                  deleteList[i] = false;
                  entityType[i] = 0;
                  for(int j =0; j < MAX_ENTITY; j++)
                        collisionMatrix[i][j] = false;
            }
            currEntity = 0;
            score = 0;
            alivePlayer = 0;
      }

      double time;      //temps depuis le lancement du jeu
      int dt;           //intervalle de temps depuis la dernière update

      //dimentions de la fenètre de jeu
      int sizeX;
      int sizeY;


      int maxEntity;                                  // limite d'entités
      int entityCount;                                // nombre actuel d'entités
      bool collisionMatrix[MAX_ENTITY][MAX_ENTITY];   // matrice des collisions
      bool deleteList[MAX_ENTITY];                    // liste des entites a supprimer
      int entityType[MAX_ENTITY];                     // type des entites actuelles

      int currEntity;                                 // entité en cours d'update
      int score;                                      // score des joueurs

      int alivePlayer;                                // nombre de joueurs en vie
      int pvJ1;                                       // pv du joueur 1

};

#endif
