#pragma once

class Board
{
public:
      Board(int height, int width)
      {
        //making the gameboard
        //get the x and y axis size
        int xMax, yMax;
        getxy(stdscr,yMax,xMax);
            
        board_win = newwin(height, width, (yMax/2)-(height-2), (xMax/2)-(width-2));//(height,width, display in the middle)-->make a square window
        box(board_win,0,0);
        wrefresh(board_win);//refresh the window
            
        this->height = height;
        this->width = width;
      }
private:
      WINDOW * board_win;
      int height, width;
};
