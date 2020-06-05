CC = g++
WFLAGS = -Wall
#SFMLFLAGS_LINK = -L/nfs/home/sasl/eleves/rob/3800630/lib/SFML-2.5.1/lib/ -lsfml-graphics -lsfml-window -lsfml-system
SFMLFLAGS_LINK = -lsfml-graphics -lsfml-window -lsfml-system
#SFMLFLAGS_OBJ = -I/nfs/home/sasl/eleves/rob/3800630/lib/SFML-2.5.1/include/
SFMLFLAGS_OBJ =
ALL.O = main.o Mechant.o Trajectoire.o JoueurPhysique.o JoueurIA.o Forme.o Brique.o Jeu.o Menu.o Script.o
ALL.H = Trajectoires/Trajectoire.hpp Entites/Entite.hpp Entites/Mechants/Mechant.hpp Entites/Joueurs/JoueurPhysique.hpp Entites/Joueurs/Joueur.hpp Formes/Brique.hpp Formes/Forme.hpp Etats/Jeu.hpp Etats/Menu.hpp Etats/Etat.hpp Other/Script.hpp Other/Gamestate.hpp

#main
hacode: $(ALL.O) $(ALL.H)
	$(CC) -o $@ $(ALL.O) $(WFLAGS) $(SFMLFLAGS_LINK)

main.o: main.cpp $(ALL.H)
	$(CC) -c $< $(WFLAGS) $(SFMLFLAGS_OBJ)

#Trajectoires/
Trajectoire.o: Trajectoires/Trajectoire.cpp Trajectoires/Trajectoire.hpp
	$(CC) -c $< $(WFLAGS)

#Mechants/
Mechant.o: Entites/Mechants/Mechant.cpp  Entites/Mechants/Mechant.hpp Entites/Entite.hpp Trajectoires/Trajectoire.hpp Entites/Projectiles/Projectile.hpp
	$(CC) -c $< $(WFLAGS)

#Joueurs/
JoueurPhysique.o: Entites/Joueurs/JoueurPhysique.cpp Entites/Joueurs/JoueurPhysique.hpp Entites/Joueurs/Joueur.hpp Entites/Entite.hpp Entites/Projectiles/Projectile.hpp
	$(CC) -c $< $(WFLAGS)

JoueurIA.o: Entites/Joueurs/JoueurIA.cpp Entites/Joueurs/JoueurIA.hpp Entites/Joueurs/Joueur.hpp Entites/Entite.hpp Trajectoires/Trajectoire.hpp Entites/Projectiles/Projectile.hpp
	$(CC) -c $< $(WFLAGS)


#Formes/
Forme.o: Formes/Forme.cpp Formes/Forme.hpp Formes/Brique.hpp
	$(CC) -c $< $(WFLAGS)

Brique.o: Formes/Brique.cpp Formes/Brique.hpp
	$(CC) -c $< $(WFLAGS)


#Etats/
Jeu.o: Etats/Jeu.cpp Etats/Jeu.hpp Etats/Etat.hpp Other/Gamestate.hpp Other/Script.hpp Entites/Joueurs/JoueurIA.hpp Formes/Rectangle.hpp Formes/Cercle.hpp
	$(CC) -c $< $(WFLAGS) $(SFMLFLAGS_OBJ)

Menu.o: Etats/Menu.cpp Etats/Menu.hpp Etats/Etat.hpp
	$(CC) -c $< $(WFLAGS) $(SFMLFLAGS_OBJ)

#Other/
Script.o: Other/Script.cpp Other/Script.hpp Other/Gamestate.hpp Entites/Entite.hpp
	$(CC) -c $< $(WFLAGS) $(SFMLFLAGS_OBJ)


clean:
	rm *.o
