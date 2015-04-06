CC=g++
CFLAGS=-Wall -Werror
# Comment out for release build
DEBUG=-g -DDEBUG

BINARY=airsim
SOURCES=airsim.cpp Airplane.cpp BoolSource.cpp Queue.cpp Runway.cpp StatKeeper.cpp
OBJECTS=$(SOURCES:.cpp=.o)

.PHONY: all
all : $(BINARY)

# Makes executable
$(BINARY) : $(OBJECTS)
	$(CC) $(LDFLAGS) $(DEBUG) -o $@ $^

# Makes airsim object used for executable
# $@ = name of file matched by target
# $< = name of first prereq
airsim.o : airsim.cpp Airplane.h BoolSource.h Queue.h Runway.h StatKeeper.h
	$(CC) $(CFLAGS) $(DEBUG) -c -o $@ $<

# Makes Airplane object file
Airplane.o : Airplane.cpp Airplane.h
	$(CC) $(CFLAGS) $(DEBUG) -c -o $@ $<

# Makes BoolSource object file
BoolSource.o : BoolSource.cpp BoolSource.h
	$(CC) $(CFLAGS) $(DEBUG) -c -o $@ $<

# Makes Queue object file
Queue.o : Queue.cpp Queue.h
	$(CC) $(CFLAGS) $(DEBUG) -c -o $@ $<

# Makes Runway object file
Runway.o : Runway.cpp Runway.h
	$(CC) $(CFLAGS) $(DEBUG) -c -o $@ $<

# Makes StatKeeper object file
StatKeeper.o : StatKeeper.cpp StatKeeper.h
	$(CC) $(CFLAGS) $(DEBUG) -c -o $@ $<

# Removes the Object files if needed to update
.PHONY: clean
clean :
	rm $(BINARY) $(OBJECTS)
