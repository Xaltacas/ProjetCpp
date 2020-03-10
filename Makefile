CC = g++
WFLAGS = -Wall
SFMLFLAGS_LINK = -L/nfs/home/sasl/eleves/rob/3800630/lib/SFML-2.5.1/lib/ -lsfml-graphics -lsfml-window -lsfml-system
SFMLFLAGS_OBJ = -I/nfs/home/sasl/eleves/rob/3800630/lib/SFML-2.5.1/include/
ALL.O = hacode.o trajectoire.o mechant.o joueurPhysique.o cercle.o rectangle.o jeu.o menu.o

#main
hacode: $(ALL.O)
	$(CC) -o $@ $(ALL.O) $(WFLAGS) $(SFMLFLAGS_LINK)

hacode.o: main.cpp
	$(CC) -c $< $(WFLAGS) $(SFMLFLAGS_OBJ)

#Trajectoires
affine.o: Affine.cpp Affine.hpp Trajectoire.hpp
	$(CC) -c $< $(WFLAGS)

#Mechants
mechant.o: Mechant.cpp Mechant.hpp
	$(CC) -c $< $(WFLAGS)

#Joueurs
joueurPhysique.o: JoueurPhysique.cpp Joueurs.hpp
	$(CC) -c $< $(WFLAGS)

#Formes
cercle.o: Cercle.cpp Cercle.hpp Forme.hpp
	$(CC) -c $< $(WFLAGS)

rectangle.o: Rectangle.cpp Rectangle.hpp Forme.hpp
	$(CC) -c $< $(WFLAGS)

#Etats
jeu.o: Jeu.cpp Jeu.hpp Etats.hpp
	$(CC) -c $< $(WFLAGS) $(SFMLFLAGS_OBJ)

menu.o: Menu.cpp Menu.hpp Etats.hpp
	$(CC) -c $< $(WFLAGS) $(SFMLFLAGS_OBJ)
	

clean:
	rm *.o
