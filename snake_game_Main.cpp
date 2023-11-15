#include<ncurses.h> //ncurses is a library for creating text-based user interface. eg. handling user keyboard input
#include "src/Board.hpp" // it is a header file

#define BOARD_DIM 20
#define BOARD_ROWS BOARD_DIM
#define BOARD_COLS BOARD_DIM * 2.5

int main(int argc, char **argv)
{
  initscr();
  refresh();
  //noecho();
  SnakeGame game(BOARD_ROWS, BOARD_COLS);

  while (!game.isOver())//while game is not over
  {
    game.processInput();
    //1.get input from user
    
    game.updateState();
    //2.update game state

    game.redraw();
    //3.redraw display
  }

  //4.go to step 1, unless game over
  
  getch();
  endwin();

  return 0;
}
