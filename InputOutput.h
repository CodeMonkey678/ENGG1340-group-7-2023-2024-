#ifndef INPUTOUTPUT_H
#define INPUTOUTPUT_H

#include <string>
#include <iostream>

void clearConsole();
void drawGameBoard(int width, int height, const Position& head, const Position& apple, const std::vector<Position>& snake, int score);
char getInput();
void showGameOver();

#endif // INPUTOUTPUT_H
