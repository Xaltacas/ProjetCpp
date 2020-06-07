CC = g++
WFLAGS = -Wall -g
#SFMLFLAGS_LINK = -L/nfs/home/sasl/eleves/rob/3800630/lib/SFML-2.5.1/lib/ -lsfml-graphics -lsfml-window -lsfml-system
SFMLFLAGS_LINK = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
#SFMLFLAGS_OBJ = -I/nfs/home/sasl/eleves/rob/3800630/lib/SFML-2.5.1/include/
SFMLFLAGS_OBJ =
ALL.O = main.o Mechants.o Trajectoire.o JoueurClavier.o JoueurIA.o Forme.o Brique.o Jeu.o Script.o Projectile.o
ALL.H = Trajectoires/Trajectoire.hpp Entites/Entite.hpp Entites/Mechants/Mechant.hpp Entites/Mechants/Mechants.hpp Entites/Projectiles/Projectile.hpp Entites/Joueurs/JoueurClavier.hpp Entites/Joueurs/Joueur.hpp Formes/Brique.hpp Formes/Forme.hpp Etats/Jeu.hpp Other/Script.hpp Other/Gamestate.hpp

#main
hacode: $(ALL.O) $(ALL.H)
	$(CC) -o $@ $(ALL.O) $(WFLAGS) $(SFMLFLAGS_LINK)

main.o: main.cpp $(ALL.H)
	$(CC) -c $< $(WFLAGS) $(SFMLFLAGS_OBJ)

#Trajectoires/
Trajectoire.o: Trajectoires/Trajectoire.cpp Trajectoires/Trajectoire.hpp
	$(CC) -c $< $(WFLAGS)

#Mechants/
Mechants.o: Entites/Mechants/Mechants.cpp Entites/Mechants/Mechants.hpp Entites/Mechants/Mechant.hpp Entites/Entite.hpp Trajectoires/Trajectoire.hpp Entites/Projectiles/Projectile.hpp
	$(CC) -c $< $(WFLAGS)

#Joueurs/
JoueurClavier.o: Entites/Joueurs/JoueurClavier.cpp Entites/Joueurs/JoueurClavier.hpp Entites/Joueurs/Joueur.hpp Entites/Entite.hpp Entites/Projectiles/Projectile.hpp Trajectoires/Trajectoire.hpp
	$(CC) -c $< $(WFLAGS)

JoueurIA.o: Entites/Joueurs/JoueurIA.cpp Entites/Joueurs/JoueurIA.hpp Entites/Joueurs/Joueur.hpp Entites/Entite.hpp Trajectoires/Trajectoire.hpp Entites/Projectiles/Projectile.hpp
	$(CC) -c $< $(WFLAGS)

#Projectiles/
Projectile.o: Entites/Projectiles/Projectile.cpp Entites/Projectiles/Projectile.hpp Entites/Entite.hpp Trajectoires/Trajectoire.hpp
	$(CC) -c $< $(WFLAGS)


#Formes/
Forme.o: Formes/Forme.cpp Formes/Forme.hpp Formes/Brique.hpp
	$(CC) -c $< $(WFLAGS)

Brique.o: Formes/Brique.cpp Formes/Brique.hpp
	$(CC) -c $< $(WFLAGS)


#Etats/
Jeu.o: Etats/Jeu.cpp Etats/Jeu.hpp Other/Gamestate.hpp Other/Script.hpp Entites/Joueurs/JoueurIA.hpp Formes/Rectangle.hpp Formes/Cercle.hpp
	$(CC) -c $< $(WFLAGS) $(SFMLFLAGS_OBJ)


#Other/
Script.o: Other/Script.cpp Other/Script.hpp Other/Gamestate.hpp Entites/Entite.hpp Entites/Mechants/Mechants.hpp
	$(CC) -c $< $(WFLAGS) $(SFMLFLAGS_OBJ)




clean:
	rm *.o




test_texture: test_texture.o Forme.o Brique.o
	$(CC) -o $@ test_texture.o Forme.o Brique.o $(WFLAGS) $(SFMLFLAGS_LINK)

test_texture.o: test_texture.cpp Formes/Brique.hpp Formes/Forme.hpp
	$(CC) -c $< $(WFLAGS) $(SFMLFLAGS_OBJ)



test_main: test_main.o Forme.o Brique.o
		$(CC) -o $@ test_main.o Forme.o Brique.o $(WFLAGS) $(SFMLFLAGS_LINK)

test_main.o: test_main.cpp Formes/Brique.hpp Formes/Forme.hpp Catch.hpp
		$(CC) -c $< $(WFLAGS) $(SFMLFLAGS_OBJ)
