CC=g++
ER=-Wall -g -c


.PHONY: all
all : airsim

#Makes executable
airsim : airsim.o Airplane.o Boolsource.o Queue.o Runway.o StatKeeper.o
	$(CC) -o airsim $^

#Makes airsim object used for executable
airsim.o : airsim.cpp Airplane.h Boolsource.h Queue.h Runway.h StatKeeper.h
	$(CC) $(ER) airsim.cpp

#Makes Airplane object file
Airplane.o : Airplane.cpp Airplane.h
	$(CC) $(ER) $@ Airplane.cpp

#Makes Boolsource object file
Boolsource.o : Boolsource.h Boolsource.cpp
	$(CC) $(ER) $@ Boolsource.cpp

#Makes Queue object file
Queue.o : Queue.cpp Queue.h
	$(CC) $(ER) $@ Queue.cpp

#Makes Runway object file
Runway.o : Runway.cpp Runway.h
	$(CC) $(ER) $@ Runway.cpp

#Makes StatKeeper object file
StatKeeper.o : StatKeeper.cpp StatKeeper.h
	$(CC) $(ER) $@ StatKeeper.cpp

#Removes the Object files if needed to update
.PHONY: clean
clean :
	rm airsim Airplane.o Boolsource.o Queue.o Runway.o StatKeeper.o


