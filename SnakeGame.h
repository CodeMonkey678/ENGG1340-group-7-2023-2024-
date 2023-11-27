#ifndef SNAKEGAME_H
#define SNAKEGAME_H

#include <vector>//using STL method
#include <string>

//this is a snake game head file
struct Position {
    int x;//the x and y position in the game grid
    int y;
};
//it defines the all directions of the snake
enum Direction {
    UP,
    DOWN,
    LEFT,
    RIGHT
};

class SnakeGame {
private:
//these two define the dimensional size of the game grid, which is 40x20
    const int width = 40;
    const int height = 20;

    bool gameOver;//to check whether is game over or not
    Position apple;//apple is tasty for snake!
    Position head;//head of the snake
    std::vector<Position> snake;//this vector stores the positions of the snake's body segment
    Direction dir;
    // dynamic memory for score and names
    // integer for user-chosen level
    int *score = new int(0);
    int level = 1;
    std::string *name = new std::string;

public:
    SnakeGame();
// all the required functions
    Position Apple_Generation();
    void Drawing_Function();
    void Input_Function();
    void Logic_Function();
    void Run_Function();
    void Naming_Function();
};

#endif  // SNAKEGAME_H
