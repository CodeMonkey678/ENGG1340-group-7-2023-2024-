EXECUTABLE = snake
CXX = g++
LDFLAGS = -lncursesw
FLAGS = -pedantic-errors -std=c++11
OBJECTS = main-2.o SnakeGame.o InputOutput.o

main-2.o: main.cpp SnakeGame.h InputOutput.h
	$(CXX) $(FLAGS) -c $< -o $@

SnakeGame.o: SnakeGame.cpp SnakeGame.h
	$(CXX) $(FLAGS) -c $< -o $@

InputOutput.o: InputOutput.cpp InputOutput.h SnakeGame.h
	$(CXX) $(FLAGS) -c $< -o $@

compile: $(OBJECTS)
	$(CXX) $(FLAGS) -o $(EXECUTABLE) $(OBJECTS) $(LDFLAGS)

clean:
	rm -f $(OBJECTS) $(EXECUTABLE)

run: $(EXECUTABLE)
	./$(EXECUTABLE)

.PHONY: compile clean run





