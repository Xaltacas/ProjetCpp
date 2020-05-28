#ifndef GAMESTATE_HPP
#define GAMESTATE_HPP

#define MAX_ENTITY 150


struct Gamestate{
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
      }

      double time;
      int dt;

      int sizeX;
      int sizeY;


      int maxEntity;
      int entityCount;
      bool collisionMatrix[MAX_ENTITY][MAX_ENTITY];
      bool deleteList[MAX_ENTITY];
      int entityType[MAX_ENTITY];
};

#endif
