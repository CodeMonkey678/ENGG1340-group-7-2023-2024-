README

GROUP MEMBERS: TSE Wang Pok (UID: 3036065642), Palden TAMANG (UID: 3036106240), Ho Chun Kau (UID: 3036068876)

GROUP NUMBER: group 7

PROJECT DESCRIPTION:
Maze Master the maze game


Main menu

use arrow keys to navigate the main menu. view your previous highscores -> tied to the name you input quit the game play the game Loading sequence

Enter a name for you scores to be recorded under Loading animation Game

use the WASD to control the snake 

start the game with ./mazegame after compiling and linking using "make compile"

use arrow keys to navigate the main menu, press enter to click selected button

Press enter on "Play Game" to start game Press enter on "HighScores" to see all highscores of your attempts Press enter on Quit to close the game and clear screen Once you press "Play Game", enter in a name to save your highscore under. If you use a name you already used before, the highscore will be overridden under that name -> given that you beat the previous score under that name. Press enter once you typed your name to begin playing

Playing the Game:

Use arrow keys or WASD to move the playable character. The character will move in the direction you set it forever until you change direction. 
when you win or lose, your score is saved. winning happens when you eat all pills enter a winning page losing happens when a ghost touches you enter a losing page conclude winning/losing page Once you conclude the losing/winning page, you will be redirected to the main menu to view your highscores, play again, or quit. IMPLEMENTATION NOTES:

list of features:


DEPENDENCIES

require ncurses to render the game ncurses is used to draw all charcters at (y,x) coordinates only. ncurses on server is used.

DOCUMENTATION:

files:


                <CLASSES>
class hierarchy: upper = parent, lower = child
Screen Menu Item PlayableMap GameObject | :-----:----------: v v v
Ghost Pill Character all function notes and documentation can be found in the file comments.
