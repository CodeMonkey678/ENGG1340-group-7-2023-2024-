#include<ncurses.h> //ncurses is a library for creating text-based user interface. eg. handling user keyboard input
#include "src/Board.hpp"

#define BOARD_DIM 20
#define BOARD_ROWS BOARD_DIM
#define BOARD_COLS BOARD_DIM * 2.5

int main(int argc, char **argv)
{
  initscr();
  refresh();

  //making the gameboard
  //get the x and y axis size
  int xMax, yMax;
  getxy(stdscr,yMax,xMax);
  WINDOW * board_win = newwin(BOARD_ROWS, BOARD_COLS, (yMax/2)-(BOARD_ROWS-2), (xMax/2)-(BOARD_COLS-2));//(height,width, display in the middle)-->make a square window
  box(board_win,0,0);
  wrefresh(board_win);//refresh the window
  
  getch();
  endwin();

  return 0;
}
