#include <iostream>
#include "SnakeGame.h"
#include "InputOutput.h"
using namespace std;
//this is the main file to run the snake game
int main() {
    srand(static_cast<unsigned>(time(nullptr)));

    SnakeGame game;
    game.Naming_Function();
    game.Run_Function();

    return 0;
}
