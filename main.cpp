#include <iostream>
#include "SnakeGame.h"

int main() {
    srand(static_cast<unsigned>(time(nullptr)));

    SnakeGame game;
    game.Name();
    game.Run();

    return 0;
}
