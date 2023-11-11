// this code can generate random maze with height x width (21 x 21)
#include <cctype>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

//represent upward direction in the maze
//downward direction in the maze
//left direction in the maze
//right direction in the maze
#define UP    0 
#define DOWN  1 
#define LEFT  2 
#define RIGHT 3 

int maze_size[2]; // it is an array, first arguement is height, second is width
int start_axis; // store the information about starting point
int start_axis;

//dfs_path is a two-dimensional vector of integers. It is used to store the path taken during the Depth-First Search (DFS) algorithm in the maze generation process.
vector< vector< int > > dfs_path;
