#ifndef INPUTOUTPUT_H
#define INPUTOUTPUT_H

#include <vector>
#include <string>
#include <iostream>
#include "SnakeGame.h"
//this is just a  output head file

void Console_Clear();

void Game_Board(int width, int height, const Position& head, const Position& apple, const std::vector<Position>& snake, int *score);
char Show_Input();
void Show_Game_Over();

#endif // INPUTOUTPUT_H
