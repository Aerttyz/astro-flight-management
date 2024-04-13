CC = g++
CFLAGS = -std=c++11 -Wall
OBJ = main.o astronauta.o voo.o

all: programa

programa: $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o programa

main.o: main.cpp astronauta.h voo.h
	$(CC) $(CFLAGS) -c main.cpp

astronauta.o: astronauta.cpp astronauta.h
	$(CC) $(CFLAGS) -c astronauta.cpp

voo.o: voo.cpp voo.h astronauta.h
	$(CC) $(CFLAGS) -c voo.cpp

clean:
	rm -f *.o programa

