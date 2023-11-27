#include "SnakeGame.h"

#include <cstdlib>
#include <ctime>
#include <thread>
#include <chrono>
#include <termios.h>
#include <sys/ioctl.h>
#include <stdio.h>
#include <unistd.h>
#include <fstream>
#include <iostream>
using namespace std;

static struct termios old, newer;
//this is the snake game c++ file
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

// this function to check if there is any keyboard input waiting to be read
bool keyboardhit() {
    termios term;
    //tcgetattr is called to get the current terminal attributes for file descriptor 0
    tcgetattr(0, &term);

    termios term2 = term;
    term2.c_lflag &= ~ICANON;
    tcsetattr(0, TCSANOW, &term2);

    int byteswaiting;
    //called the ioctl function to determine how many bytes are waiting in the input buffer.
    ioctl(0, FIONREAD, &byteswaiting);//it is an input buffer

    tcsetattr(0, TCSANOW, &term);

    return byteswaiting > 0;
}

void resetTermios(void) {
    // this function restores the original terminal attributes
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
    //this allows you to read a character from the keyboard without echo
    return getch_(0);
}

char getche(void) {
    return getch_(1);//similar, but with echo the character to the console
}
// this is the SnakeGame class
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
    newApple.x = rand() % width;  //x position of the new apple generated
    newApple.y = rand() % height; //y position of the new apple generated
    return newApple;
}

void SnakeGame::Drawing_Function() {
    // Clear the console output
    cout << "\033[2J\033[H";// kind of weird??

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
                    cout << " ";//cout it if it is not the body part of the snake
                }
            }
            if (j == width - 1) {
                cout << "#";
            }
        }
        cout << endl;//change the line
    }

    for (int i = 0; i < width + 2; i++) {
        cout << "#";
    }
    cout << endl;
    cout << *name << " - ";//count the name of the player
    cout << "Score: " << *score << endl;//print the score of the player
}
//this is to get the user input from the keyboard, to move the snake
void SnakeGame::Input_Function() {
    if (keyboardhit())
    {
        char input = GETCH();
            
        if ((input == 'w' || input == 'W') && dir != DOWN) {
            dir = UP;//w is go up
        }
        else if ((input == 's' || input == 'S') && dir != UP) {
            dir = DOWN;//s is go down
        }
        else if ((input == 'a' || input == 'A') && dir != RIGHT) {
            dir = LEFT;//a is go left
        }
        else if ((input == 'd' || input == 'D') && dir != LEFT) {
            dir = RIGHT;//d is go right
        }
        else if (input == 'x' || input == 'X') {
            gameOver = true;//x can quit the game
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
        //400 divided by level (input from user
        //to reduce the sleep-for time, making game more challenging
        this_thread::sleep_for(chrono::milliseconds(400/level));
    }
       
    if (gameOver) {
        //print out the game over page
        cout << "\033[2J\033[H";
        cout << "Game over" << endl;
        cout << "Thank you for playing!" <<endl;
        cout << "\n\n";

        delete name; // dynamic memory release
        delete score; // dynamic memory release
        name = 0;
        score = 0;
    }
}
void SnakeGame::Naming_Function() {
    level = 1; //Function for getting player name and choosing the level of difficulty
    cout << "\033[2J\033[H";//this line is used to clear the screen
    cout << "Welcome to the game" << endl;
    cout << "What is your name? (no spaces)" << endl;
    cin >> *name;//get the user's name
    //print out the starting page of the game
    cout << "Choose Game Difficulty by INSERTING 1,2,3,4,5 or 6:" << endl;
    cout <<"    1 for Easy," << endl;
    cout <<"    2 for Medium," << endl;
    cout <<"    3 for Hard," << endl;
    cout <<"    4 for Extreme," << endl;
    cout <<"    5 for Nightmare," << endl;
    cout <<"    6 for HELL!\n" << endl;
    cout <<"LEVEL: ";
    cin >> level;
    cout << endl;
            
    cout << "\033[2J\033[H";
}
