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
    // implementation
}

void resetTermios(void) {
    // implementation
}

char getch_(int echo) {
    // implementation
}

char GETCH(void) {
    // implementation
}

char getche(void) {
    // implementation
}

SnakeGame::SnakeGame() {
    // implementation
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
