CC = g++
WFLAGS = -Wall
SFMLFLAGS_LINK = -L/nfs/home/sasl/eleves/rob/3800630/lib/SFML-2.5.1/lib/ -lsfml-graphics -lsfml-window -lsfml-system
SFMLFLAGS_OBJ = -I/nfs/home/sasl/eleves/rob/3800630/lib/SFML-2.5.1/include/
ALL.O = main.o affine.o mechant1.o joueurPhysique.o cercle.o rectangle.o jeu.o menu.o

#main
hacode: $(ALL.O)
	$(CC) -o $@ $(ALL.O) $(WFLAGS) $(SFMLFLAGS_LINK)

main.o: main.cpp
	$(CC) -c $< $(WFLAGS) $(SFMLFLAGS_OBJ)

#Trajectoires/
affine.o: Trajectoires/Affine.cpp Trajectoires/Affine.hpp Trajectoires/Trajectoire.hpp
	$(CC) -c $< $(WFLAGS)

#Mechants/
mechant1.o: Mechants/Mechant1.cpp Mechants/Mechant1.hpp Mechants/Mechant.hpp
	$(CC) -c $< $(WFLAGS)

#Joueurs/
joueurPhysique.o: Joueurs/JoueurPhysique.cpp Joueurs/JoueurPhysique.hpp Joueurs/Joueur.hpp
	$(CC) -c $< $(WFLAGS)

#Formes/
cercle.o: Formes/Cercle.cpp Formes/Cercle.hpp Formes/Forme.hpp
	$(CC) -c $< $(WFLAGS)

rectangle.o: Formes/Rectangle.cpp Formes/Rectangle.hpp Formes/Forme.hpp
	$(CC) -c $< $(WFLAGS)

#Etats/
jeu.o: Etats/Jeu.cpp Etats/Jeu.hpp Etats/Etat.hpp
	$(CC) -c $< $(WFLAGS) $(SFMLFLAGS_OBJ)

menu.o: Etats/Menu.cpp Etats/Menu.hpp Etats/Etat.hpp
	$(CC) -c $< $(WFLAGS) $(SFMLFLAGS_OBJ)


clean:
	rm *.o
