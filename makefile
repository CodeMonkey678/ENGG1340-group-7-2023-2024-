all: main

main: main.cpp src/Board.hpp src/SnakeGame.hpp
  g++ main.cpp -lncurses -o main
