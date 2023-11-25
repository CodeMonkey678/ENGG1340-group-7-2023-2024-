#include "SnakeGame.h"

#include <cstdlib>
#include <ctime>
#include <thread>
#include <chrono>
#include <termios.h>
#include <sys/ioctl.h>
#include <stdio.h>
#include <unistd.h>
#include <iostream>
using namespace std;

static struct termios old, newer;

void initializeTermios(int echo) {
    //Gets the current terminal attributes from the file descriptor 0 (standard input) and stores them in struct old.
    tcgetattr(0, &old);
    newer = old;
    //Sets the ICANON flag in the c_lflag field of newer to 0 (false) by performing a bitwise AND operation with the bitwise NOT of ICANON.
    newer.c_lflag &= ~ICANON;
    newer.c_lflag &= echo ? ECHO : ~ECHO;
    //calls the tcsetattr function to set the terminal attributes for file descriptor 0 to the values in newer.
    //The TCSANOW flag specifies that the changes should take effect immediately.
    tcsetattr(0, TCSANOW, &newer);
}

bool keyboardhit() {
    termios term;
    //tcgetattr is called to get the current terminal attributes for file descriptor 0
    tcgetattr(0, &term);

    termios term2 = term;
    term2.c_lflag &= ~ICANON;
    tcsetattr(0, TCSANOW, &term2);

    int byteswaiting;
    //called the ioctl function to determine how many bytes are waiting in the input buffer.
    ioctl(0, FIONREAD, &byteswaiting);

    tcsetattr(0, TCSANOW, &term);

    return byteswaiting > 0;
}

void resetTermios(void) {
    tcsetattr(0, TCSANOW, &old);
}

char getch_(int echo) {
    char ch;
    initializeTermios(echo);
    ch = getchar();
    resetTermios();
    return ch;
}

char GETCH(void) {
    return getch_(0);
}

char getche(void) {
    return getch_(1);
}

SnakeGame::SnakeGame() {
    gameOver = false; // initializes the game
    head = { width / 2, height / 2 };// head position of the snake
    apple = Apple_Generation();
    dir = RIGHT;//initial direction of the snake
    *score = 0;
    snake.push_back(head);// it adds the head position to the snake vector. Ensures that snake only have head at the beginning
}

Position SnakeGame::Apple_Generation() {
    Position newApple;
    newApple.x = rand() % width;
    newApple.y = rand() % height;
    return newApple;
}

void SnakeGame::Drawing_Function() {
    // Clear the console output
    cout << "\033[2J\033[H";

    for (int i = 0; i < width + 2; i++) {
        cout << "#";//print out the gameboard
    }
    cout << endl;

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (j == 0) {
                cout << "#";
            }
            if (i == head.y && j == head.x) {
                cout << "O";//print the head of snake
            }
            else if (i == apple.y && j == apple.x) {
                cout << "A";//print the apple
            }
            else {
                //to check current position corresponds to any body segment of the snake.
                //if true then print the character to represent the body segment.
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
    //cout << *name << " - ";
    cout << "Score: " << *score << endl;//print the score
}

void SnakeGame::Input_Function() {
    if (keyboardhit())
    {
        char input = GETCH();
            
        if ((input == 'w' || input == 'W') && dir != DOWN) {
            dir = UP;
        }
        else if ((input == 's' || input == 'S') && dir != UP) {
            dir = DOWN;
        }
        else if ((input == 'a' || input == 'A') && dir != RIGHT) {
            dir = LEFT;
        }
        else if ((input == 'd' || input == 'D') && dir != LEFT) {
            dir = RIGHT;
        }
        else if (input == 'x' || input == 'X') {
            gameOver = true;
        }
    }
}

void SnakeGame::Logic_Function() {
    Position prevTail = snake.empty() ? Position{0, 0} : snake.back();
    Position prevHead = head;
    //adjust the position by add and minus the coordinate of x and y of the snake.
    switch (dir) {
        case UP:
            head.y--;
            break;
        case DOWN:
            head.y++;
            break;
        case LEFT:
            head.x--;
            break;
        case RIGHT:
            head.x++;
            break;
    }

    if (head.x >= width || head.x < 0 || head.y >= height || head.y < 0) {
        gameOver = true;  // Snake collided with the wall
        return;
    }

    if (head.x == apple.x && head.y == apple.y) {
        *score += 100;
        apple = Apple_Generation();
        snake.push_back(prevTail);  // Increase snake size by adding the previous tail
    } else {
        snake.pop_back();  // Remove the tail on every move
    }

    // Check for collision with snake body
    for (int i = 1; i < snake.size(); i++) {
        if (head.x== snake[i].x && head.y == snake[i].y) {
            gameOver = true;
            break;
        }
    }

    snake.insert(snake.begin(), head);
}

void SnakeGame::Run_Function() {
    while (!gameOver) {
        Drawing_Function();
        Input_Function();
        if (!gameOver) {
            Logic_Function();
        }
        this_thread::sleep_for(chrono::milliseconds(400));
    }
       
    if (gameOver) {
        cout << "\033[2J\033[H";
        cout << "Game over" << endl;
        cout << "Thank you for playing!" <<endl;
        cout << "\n\n";
    }
}
void SnakeGame::Naming_Function() {
    string *name = new string;
    cout << "\033[2J\033[H";
    cout << "Welcome to the game" << endl;
    cout << "What is your name? (no spaces)" << endl;
    cin >> *name;
    cout << "\033[2J\033[H";
}
