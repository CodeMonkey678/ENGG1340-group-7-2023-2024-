#include "SnakeGame.h"
#include "InputOutput.h"
#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;
// this is inputoutput c++ file


void Console_Clear() {
    cout << "\033[2J\033[H";
}

void Game_Board(int width, int height, const Position& head, const Position& apple, const std::vector<Position>& snake, int *score) {
    Console_Clear();

    for (int i = 0; i < width + 2; i++) {
        cout << "#";
    }
    std::cout << std::endl;

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (j == 0) {
                cout << "#";
            }
            if (i == head.y && j == head.x) {
                cout << "O";
            }
            else if (i == apple.y && j == apple.x) {
                cout << "A";
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

    cout << "Score: " << *score << endl;
}

char Show_Input() {
    char input;
    cin >> input;
    return input;
}

void Show_Game_Over() {
    Console_Clear();
    cout << "Game over" << endl;
    cout << "Thank you for playing!" << endl;
    cout << "Snake game by COMP2113/ENGG1340 group 7" << endl;
    cout << "\n\n";
}
