README

GROUP MEMBERS: 
  TSE Wang Pok (UID: 3036065642), 
  TAMANG PALDEN (UID: 3036106240), 
  Ho Chun Kau (UID: 3036068876) , 
  CHANDAFA Abraham Ernest (UID: 3036030958),
  
  
GROUP NUMBER: group 7

PROJECT DESCRIPTION: Snake Master (the snake game)

Compilation and execution instructions:
Download the zip file of the game, open the file and download it onto your computer. Next save it all into a single directory and start the compilation.
Compile the files by executing the command : make compile

Starting the game: 
start the game with ./snake after compiling and linking the files using "make compile"

Playing the Game:
Enter your name (without spaces)
Choose a level from 1-6

Level descriptions:
1 for Easy
2 for Medium
3 for Hard
4 for Extreme
5 for Nightmare
6 for HELL!

The higher the level, the faster the snake moves, the faster the pace of the game is

use the WASD to control the snake, and X to quit game:
W=UP,  S=DOWN,  A=LEFT,  D=RIGHT 

Use WASD to move the playable character. The snake will keep moving in the specified direction until another direction is pressed

Game rules:
Welcome to the thrilling world of Snake! 
As you slither through the pixelated landscape, keep these rules in mind:

Rule 1: Devour Treats 🍎
Your snake has an insatiable appetite for apples (A). These delectable treats will randomly appear on the board, and it's your job to guide your snake to them. Every time you devour an apple, your snake will grow longer and longer, making your victory even sweeter.

Rule 2: Mind Your Tail 🐍
Beware! Your own tail is your worst enemy. If you accidentally collide with any part of your elongating snake body, it's game over for you. The longer your snake grows, the more challenging it becomes to navigate without accidentally biting your own tail. 

Rule 3: Avoid Walls 🧱
The game arena is surrounded by solid walls. Crashing your snake into these barriers is game over. You must skillfully maneuver your snake through the ever-narrowing gaps as the walls close in.Be agile and use those reflexes to survive.

Rule 4: Speed and Precision ⚡️
Snake, like life, moves fast! You'll need lightning-fast reflexes to guide your snake around the obstacles and towards victory. Be precise in your movements, as a single wrong turn can cost you dearly.Depending on which level you choose, the pace of the game will be faster.

Rule 5: High Score Glory 🏆
The ultimate aim of the game is to achieve the highest score possible. Each apple you devour increases your score by 100 points, showcasing your mastery of the game.Can you become the ultimate Snake champion?
Remember, Snake is a test of strategy, reflexes, and determination. So,eat your way to victory, embark on this thrilling adventure,and let the world witness the rise of a legendary snake master!
Now, go forth and conquer the Snake game! 🐍🍎

IMPLEMENTATION NOTES:

list of features:
extensive use of dynamic memory
used pointers to keep track of all dynamic objects
randomised apple generaton
realtime input output
saved score under player inputted name
scores are saved to a separate textfile named scoreBoard.txt
utilised multiple STL containers
interactive main menu
variety of levels with a range of difficulties

Generation of random game sets or events:
Apple

Data structures for storing game status:
Utilized a wide range of data structures, such as vectors, dynamically allocated arrays, strings, and integers. Pointers are also extensively employed, for instance, a vector of pointers is utilized to manage and access all dynamically allocated instances of a class.

Dynamic memory management:

File input/output (e.g., for loading/saving game status):

Program codes in multiple files:

Proper indentation and naming styles:

In-code documentation:
Consistent use of in code documentation in all files, describing the purpose of the function and what it does.



DEPENDENCIES
require ncurses to render the game ncurses is used to draw all charcters at (y,x) coordinates only. ncurses on server is used.

DOCUMENTATION:

files:

QUICKSTART: 

Code Requirement. Your implementation should include all the following coding elements: Generation of random game sets or events
Data structures for storing game status
Dynamic memory management
File input/output (e.g., for loading/saving game status) Program codes in multiple files
Proper indentation and naming styles
In-code documentation

