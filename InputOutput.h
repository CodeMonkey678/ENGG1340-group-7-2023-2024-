#ifndef INPUTOUTPUT_H
#define INPUTOUTPUT_H

#include <vector>
#include <string>
#include <iostream>
#include "SnakeGame.h"
//this is just a  output head file

void Console_Clear();//this function responsible for cleaning the screen
//this function is to draw the game board
void Game_Board(int width, int height, const Position& head, const Position& apple, const std::vector<Position>& snake, int *score);
char Show_Input();//get the user input's character
void Show_Game_Over();//show the game is over laaa!1

#endif // INPUTOUTPUT_H
