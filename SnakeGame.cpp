#include "SnakeGame.h"
#include <cstdlib>
#include <ctime>
#include <thread>
#include <chrono>
#include <termios.h>
#include <sys/ioctl.h>
#include <stdio.h>
#include <unistd.h>

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
    apple = GenerateApple();
    dir = RIGHT;//initial direction of the snake
    score = 0;
    snake.push_back(head);// it adds the head position to the snake vector. Ensures that snake only have head at the beginning
}

Position SnakeGame::GenerateApple() {
    // implementation
}

void SnakeGame::Draw() {
    // implementation
}

void SnakeGame::Input() {
    // implementation
}

void SnakeGame::Logic() {
    // implementation
}

void SnakeGame::Run() {
    // implementation
}

void SnakeGame::Name() {
    // implementation
}
