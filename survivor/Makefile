LFLAGS=-lboost_system -lboost_random 
STDFLAGS=-ansi -pedantic -Wall -gstabs
CFLAGS=$(STDFLAGS)
OBJECTS=survivor.o trained_survivor.o weak_survivor.o infested_area.o \
	simulator.o hospital.o pub.o tokenizer.o os_error.o parser.o

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

simulator.o:simulator.cpp simulator.h survivor.h os_error.h weak_survivor.h \
	trained_survivor.h infested_area.h pub.h hospital.h parser.h
	g++ $(CFLAGS) -c simulator.cpp

hospital.o:hospital.cpp hospital.h infested_area.h
	g++ $(CFLAGS) -c hospital.cpp

pub.o:pub.cpp pub.h infested_area.h
	g++ $(CFLAGS) -c pub.cpp

tokenizer.o:tokenizer.cpp tokenizer.h 
	g++ $(CFLAGS) -c tokenizer.cpp

os_error.o:os_error.cpp os_error.h
	g++ $(CFLAGS) -c os_error.cpp

parser.o: parser.h parser.cpp os_error.h weak_survivor.h trained_survivor.h \
	tokenizer.h infested_area.h pub.h hospital.h simulator.h
	g++ $(CFLAGS) -c parser.cpp

clean:
	rm -f *.o survivalrate
