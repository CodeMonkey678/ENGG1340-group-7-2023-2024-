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
    int score;

public:
    SnakeGame();

    Position Apple_Generation();
    void Draw();
    void Input();
    void Logic();
    void Run();
    void Name();
};

#endif  // SNAKEGAME_H
