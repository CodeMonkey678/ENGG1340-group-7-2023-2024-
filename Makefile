Executable= Snake
LDFLAGS= -lncursew
FLAGS = -pedantic-errors -std=c++11 gcd.o: gcd.cpp gcd.h
Objects = main-2.o SnakeGame.o InputOutput.o

main-2.o: main-2.cpp SnakeGame.h InputOutput.h
	g++ $(FLAGS) -c $<

SnakeGame.o: SnakeGame.cpp Snakegame.h
	g++ $(FLAGS) -c $<

InputOutput.o: InputOutput.cpp InputOutput.h SnakeGame.h
	g++ $(FLAGS) -c $<

Snake: main-2.o SnakeGame.o InputOutput.o
	g++ $(FLAGS) $^ -o $@ $(Objects) $(LDFLAGS)

clean:
	rm -f $(Objets) Snake

run:
	./$(Executable)

	
.PHONY: clean run







