CC=gcc
CFLAGS=-Wall
LDFLAGS=-lm
EXEC=profil

all : $(EXEC)

profil : main.o fonctions_ES.o timers_b.o
		$(CC) -pg -o profil main.o fonctions_ES.o timers_b.o $(LDFLAGS)

main.o : main.c
		$(CC) -pg $(CFLAGS) -o $@ -c $^ $(LDFLAGS)

fonctions_ES.o : fonctions_ES.c
		$(CC) -pg $(CFLAGS) -o $@ -c $^

timers_b.o : timers_b.c
		$(CC) -pg $(CFLAGS) -o $@ -c $^
clean:
	rm -f *.o

mrproper: clean
	rm -f $(EXEC)
