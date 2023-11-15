all: main

main: main.cpp src/Board.hpp src/SnakeGame.hpp
  g++ -pedantic-erros -std=c++11 main.cpp -lncurses -o main
