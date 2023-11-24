#include "InputOutput.h"
#include <iostream>
#include <cstdlib>

using namespace std;

void clearConsole() {
    cout << "\033[2J\033[H";
}

void drawGameBoard(int width, int height, const Position& head, const Position& apple, const std::vector<Position>& snake, int score) {
    clearConsole();

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

    cout << "Score: " << score << endl;
}

char getInput() {
    char input;
    cin >> input;
    return input;
}

void showGameOver() {
    clearConsole();
    cout << "Game over" << endl;
    cout << "Thank you for playing!" << endl;
    cout << "\n\n";
}
