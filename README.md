README

GROUP MEMBERS: 
  TSE Wang Pok (UID: 3036065642), 
  TAMANG PALDEN (UID: 3036106240), 
  Ho Chun Kau (UID: 3036068876) , 
  CHANDAFA Abraham Ernest (UID: 3036030958),
  DAIYAN Ahmed Zuhaier (UID: 3035962403)
  
  
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

The snake will keep moving in the specified direction until another direction is pressed

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
Generation of random position for an apple within the game board, using the rand() function to generate random coordinates for x and y. The resulting position is returned.
Member called Apple_Generation() within a class named SnakeGame. This function is responsible for generating a new apple position within the game board.
The function starts by declaring a variable called newApple of type Position.
Next, the x coordinate of the newApple position is set to a random value between 0 and width - 1. This is achieved by using the modulo operator % with the rand() function, which generates a random number.
Similarly, the y coordinate of the newApple position is set to a random value between 0 and height - 1 using the same approach.
Finally, the function returns the newApple position.


Data structures for storing game status:
Utilized a wide range of data structures, such as vectors, dynamically allocated arrays, strings, and integers. Pointers are also extensively employed, for instance, a vector of pointers is utilized to manage and access all dynamically allocated instances of a class.

Dynamic memory management:
Dynamic String Allocation: In the case where the user input is invalid (level greater than 4 or less than 1), dynamic memory allocation is used to create a new string object gotIt. This string is used to inform the user of the invalid input and measures taken. For example: string *gotIt = new string;.
Dynamic String Deallocation: After serving its purpose, the dynamically allocated string gotIt is deallocated to free up the memory. The code delete gotIt; gotIt = 0; is used to delete the dynamically allocated string and set the pointer to null.
The dynamic memory allocation and deallocation are employed to handle user input validation and ensure that memory is properly managed during runtime. By allocating memory only when necessary and releasing it promptly, the code optimizes memory usage and avoids memory leaks.


File input/output (e.g., for loading/saving game status):
scoring.cpp opens a file named "scoreBoard.txt" to store game scores. It reads existing scores from the file and stores them in a map called mapping. New scores are added to the map. The updated scores are written back to the file, and the current standings are displayed to the user. The file is closed after the operations are completed.

Program codes in multiple files:
The game has been implemented using multiple files to organize and separate different components of the game. Each file focuses on a specific aspect of the game, such as the game logic, user input, and scoring etc. This allows for better code organization, reusability, and maintainability. By dividing the code into multiple files, it becomes easier to manage and work on individual components independently while ensuring proper integration between them.

Proper indentation and naming styles:
All code blocks are indented with appropriate spacing. All functions, classes and variables are named appropriately with easy to understand names, relating to its purpose

In-code documentation:
Consistent use of in code documentation in all files, describing the purpose of the function and what it does.


FILES:

main.cpp:
Main file to run the snake game,and where the snakegame class called game is created.


InputOutput.cpp InputOutput.h:
Contains functions to draw the game board, including snake, apple and score, and is used to show the game over message.


SnakeGame.cpp SnakeGame.h:
This is the main file containing the logic of the game. Contains functions to read real time player keyboard input and contains functions to generate tha apple in random positions and conditions for game over.


levels.cpp levels.h:
Contains the level function which takes user name, checks to see if it is first time or existing, if first time, function welcomes user, introduces him to which levels they can choose
Otherwise, it checks previous score to determine which levels can be selected
function checks to see if level chosen is valid
Prints out messages to interact with user, then finally returns an integer
which is used for determining game difficulty


scoring.cpp scoring.h: 
Uses maps to store all data efficiently before printing to user & storing to file, function takes name and new score after game over, returns nothing.


Makefile:
Used to compile and build the game. The Makefile defines compilation rules for each source file, specifying dependencies and commands to generate object files. The "compile" target compiles the source files into object files and links them to create the "snake" executable. The "clean" target removes generated files, ensuring a clean build environment. The "run" target executes the "snake" program.




