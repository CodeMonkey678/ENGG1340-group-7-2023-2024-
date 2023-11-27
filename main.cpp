#include <iostream>
#include "SnakeGame.h"//include the snake game header file, to run the functions
#include "InputOutput.h"//include the input output header file to run the functions
#include "scoring.h" // specifically for storing the scores
using namespace std;
//this is the main file to run the snake game
int main() {
    //random function
    srand(static_cast<unsigned>(time(nullptr)));//it is to seed the random number generator with the current time.

    SnakeGame game;//a snakegame class called game is created
    game.Naming_Function();
    game.Run_Function();

    return 0;
}
