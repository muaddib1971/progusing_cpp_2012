LFLAGS=-lboost_system -lboost_random
STDFLAGS=-ansi -pedantic -Wall
CFLAGS=$(STDFLAGS)
OBJECTS=main.o survivor.o trained_survivor.o weak_survivor.o infested_area.o \
	simulator.o hospital.o pub.o

all:$(OBJECTS)
	g++ $(LFLAGS) $(OBJECTS) -o survivalrate

debug:CFLAGS=$(STDFLAGS) -DDEBUG
debug:clean $(OBJECTS)
	g++ $(LFLAGS) $(OBJECTS) -o survivalrate

main.o:main.cpp main.h survivor.h
	g++ $(CFLAGS) -c main.cpp

survivor.o:survivor.cpp survivor.h
	g++ $(CFLAGS) -c survivor.cpp

trained_survivor.o:trained_survivor.cpp trained_survivor.h survivor.h
	g++ $(CFLAGS) -c trained_survivor.cpp

weak_survivor.o:weak_survivor.cpp weak_survivor.h survivor.h
	g++ $(CFLAGS) -c weak_survivor.cpp

infested_area.o:infested_area.cpp infested_area.h
	g++ $(CFLAGS) -c infested_area.cpp

simulator.o:simulator.cpp simulator.h survivor.h
	g++ $(CFLAGS) -c simulator.cpp

hospital.o:hospital.cpp hospital.h infested_area.h
	g++ $(CFLAGS) -c hospital.cpp

pub.o:pub.cpp pub.h infested_area.h
	g++ $(CFLAGS) -c pub.cpp

clean:
	rm -f *.o survivalrate
