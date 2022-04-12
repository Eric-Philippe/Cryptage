# Compiler sans tenir compte des dépendances
all:
	gcc -o main main.c menus.c launcher.c encodeurC.c encodeurV utils.c

# Executable
main: main.o menus.o launcher.o encodeurC.o encodeurV.o utils.o
	gcc -o main main.o menus.o launcher.o encodeurC.o encodeurV.o utils.o

# Recompile si main.c ou les .h plus récents que main.o
main.o: main.c menus.h
	gcc -c main.c

# Recompile si menus.c ou les .h plus récents que menus.o
menus.o: menus.c menus.h launcher.h
	gcc -c menus.c

# Recompile si launcher.c ou les .h plus récents que launcher.o
launcher.o: launcher.c launcher.h utils.h encodeurC.h encodeurV.h
	gcc -c launcher.c

# Recompile si utils.c ou les .h plus récents que utils.o
utils.o: utils.c utils.h
	gcc -c utils.c

# Recompile si encodeurC.c ou les .h plus récents que encodeurC.o
encodeurC.o: encodeurC.c encodeurC.h
	gcc -c encodeurC.c

# Recompile si encodeurV.c ou les .h plus récents que encodeurV.o
encodeurV.o: encodeurV.c encodeurV.h
	gcc -c encodeurV.c

# Efface les objets, l'exécutable et les fichiers textes
clean:
	rm main.o menus.o launcher.o utils.o encodeurC.o encodeurV.o
	rm main
	rm *.txt
	
