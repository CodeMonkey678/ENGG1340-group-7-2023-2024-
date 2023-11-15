#include<ncurses.h> //ncurses is a library for creating text-based user interface. eg. handling user keyboard input
#include "src/Board.hpp"

int main(int argc, char **argv)
{
  initscr();
  refresh();

  //making the gameboard
  
  //get the x and y axis size
  int x, y;
  getxy(stdscr,y,x);
  WINDOW * board_win = newwin(20, 20, (y/2)-10, (x/2)-10);//(height,width, display in the middle)
  box(board_win,0,0);
  wrefresh(board_win);//refresh the window
  
  getch();
  endwin();

  return 0;
}
