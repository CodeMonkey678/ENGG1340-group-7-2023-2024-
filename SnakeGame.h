#ifndef SNAKEGAME_H
#define SNAKEGAME_H

#include <vector>
#include <string>


struct Position {
    int x;
    int y;
};

enum Direction {
    UP,
    DOWN,
    LEFT,
    RIGHT
};

class SnakeGame {
private:
    const int width = 40;
    const int height = 20;

    bool gameOver;
    Position apple;
    Position head;
    std::vector<Position> snake;
    Direction dir;
    int *score = new int(0);

public:
    SnakeGame();

    Position Apple_Generation();
    void Drawing_Function();
    void Input_Function();
    void Logic_Function();
    void Run_Function();
    void Naming_Function();
};

#endif  // SNAKEGAME_H
