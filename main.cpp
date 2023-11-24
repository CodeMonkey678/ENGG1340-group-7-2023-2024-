#include <iostream>
#include "SnakeGame.h"
#include "InputOutput.h"
using namespace std;

int main() {
    srand(static_cast<unsigned>(time(nullptr)));

    SnakeGame game;
    game.Name();
    game.Run();

    return 0;
}
