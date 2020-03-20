CC = g++
WFLAGS = -Wall
#SFMLFLAGS_LINK = -L/nfs/home/sasl/eleves/rob/3800630/lib/SFML-2.5.1/lib/ -lsfml-graphics -lsfml-window -lsfml-system
SFMLFLAGS_LINK = -lsfml-graphics -lsfml-window -lsfml-system
#SFMLFLAGS_OBJ = -I/nfs/home/sasl/eleves/rob/3800630/lib/SFML-2.5.1/include/
SFMLFLAGS_OBJ =
ALL.O = main.o Affine.o Mechant1.o JoueurPhysique.o Forme.o Brique.o Jeu.o Menu.o
ALL.H = Trajectoires/Affine.hpp Trajectoires/Trajectoire.hpp Mechants/Mechant1.hpp Mechants/Mechant.hpp Joueurs/JoueurPhysique.hpp Joueurs/Joueur.hpp Formes/Brique.hpp Formes/Forme.hpp Etats/Jeu.hpp  Etats/Menu.hpp Etats/Etat.hpp

#main
hacode: $(ALL.O) $(ALL.H)
	$(CC) -o $@ $(ALL.O) $(WFLAGS) $(SFMLFLAGS_LINK)

main.o: main.cpp $(ALL.H)
	$(CC) -c $< $(WFLAGS) $(SFMLFLAGS_OBJ)

#Trajectoires/
Affine.o: Trajectoires/Affine.cpp Trajectoires/Affine.hpp Trajectoires/Trajectoire.hpp
	$(CC) -c $< $(WFLAGS)

#Mechants/
Mechant1.o: Mechants/Mechant1.cpp Mechants/Mechant1.hpp Mechants/Mechant.hpp
	$(CC) -c $< $(WFLAGS)

#Joueurs/
JoueurPhysique.o: Joueurs/JoueurPhysique.cpp Joueurs/JoueurPhysique.hpp Joueurs/Joueur.hpp
	$(CC) -c $< $(WFLAGS)

#Formes/
Forme.o: Formes/Forme.cpp Formes/Forme.hpp Formes/Brique.hpp
	$(CC) -c $< $(WFLAGS)

Brique.o: Formes/Brique.cpp Formes/Brique.hpp
	$(CC) -c $< $(WFLAGS)

#Etats/
Jeu.o: Etats/Jeu.cpp Etats/Jeu.hpp Etats/Etat.hpp
	$(CC) -c $< $(WFLAGS) $(SFMLFLAGS_OBJ)

Menu.o: Etats/Menu.cpp Etats/Menu.hpp Etats/Etat.hpp
	$(CC) -c $< $(WFLAGS) $(SFMLFLAGS_OBJ)


clean:
	rm *.o
