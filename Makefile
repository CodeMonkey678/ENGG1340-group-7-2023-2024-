EXECUTABLE = snake
CXX = g++
LDFLAGS = -lncursesw
FLAGS = -pedantic-errors -std=c++11
OBJECTS = main.o SnakeGame.o InputOutput.o scoring.o levels.o

main.o: main.cpp SnakeGame.h InputOutput.h scoring.h levels.h
	$(CXX) $(FLAGS) -c $< -o $@

SnakeGame.o: SnakeGame.cpp SnakeGame.h scoring.h levels.h
	$(CXX) $(FLAGS) -c $< -o $@

InputOutput.o: InputOutput.cpp InputOutput.h SnakeGame.h
	$(CXX) $(FLAGS) -c $< -o $@

scoring.o: scoring.cpp scoring.h
	$(CXX) $(FLAGS) -c $< -o $@

levels.o: levels.cpp levels.h
	$(CXX) $(FLAGS) -c $< -o $@

compile: $(OBJECTS)
	$(CXX) $(FLAGS) -o $(EXECUTABLE) $(OBJECTS) $(LDFLAGS)

clean:
	rm -f $(OBJECTS) $(EXECUTABLE)

run: $(EXECUTABLE)
	./$(EXECUTABLE)

.PHONY: compile clean run

