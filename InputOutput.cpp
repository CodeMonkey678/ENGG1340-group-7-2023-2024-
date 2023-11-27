#include "SnakeGame.h"
#include "InputOutput.h"
#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;
// this is inputoutput c++ file


void Console_Clear() {
    cout << "\033[2J\033[H";//it can use to clear the console screen, so weird
}
// this function is used to draw the game board, including snake, apple and score
void Game_Board(int width, int height, const Position& head, const Position& apple, const std::vector<Position>& snake, int *score) {
    Console_Clear();

    for (int i = 0; i < width + 2; i++) {
        cout << "#";
    }
    std::cout << std::endl;
//using for loop to print out the snake body, head and apple on the screen
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (j == 0) {
                cout << "#";//this is to draw the snake's body, when the condition is satisfied
            }
            if (i == head.y && j == head.x) {
                cout << "O";//this is to draw the snake's head
            }
            else if (i == apple.y && j == apple.x) {
                cout << "A";//print out the apple on the screen
            }
            else {
                bool isBodyPart = false;
                for (int k = 1; k < snake.size(); k++) {
                    if (snake[k].x == j && snake[k].y == i) {
                        cout << "o";
                        isBodyPart = true;
                        break;
                    }
                }
                if (!isBodyPart) {
                    cout << " ";
                }
            }
            if (j == width - 1) {
                cout << "#";
            }
        }
        cout << endl;
    }

    for (int i = 0; i < width + 2; i++) {
        cout << "#";
    }
    cout << endl;

    cout << "Score: " << *score << endl;//count the score of player
}

char Show_Input() {
    char input;
    cin >> input;//get the input
    return input;//return the input character
}

void Show_Game_Over() {
    Console_Clear();
    cout << "Game over" << endl;
    cout << "Thank you for playing!" << endl;//end of the game
    cout << "Snake game by COMP2113/ENGG1340 group 7" << endl;//nice team
    cout << "\n\n";
}
