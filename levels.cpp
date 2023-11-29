#include "levels.h"
#include <map>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
using namespace std;

/*
    - the levels function takes user name, checks to see if it is first time or existing
    - if first time, function welcomes user, introduces him to which levels they can choose
    - Otherwise, it checks previous score to determine which levels can be selected
    - function checks to see if level chosen is valid
    - Prints out messages to interact with user, then finally returns an integer
    - which is used for determining game difficulty
*/

int levels(string name){ 
    int level; // value to be returned to SnakeGame
    map<string,int> leveling; // unload data from scoreBoard.txt for efficient manipulation

    ofstream Board;
    Board.open("scoreBoard.txt", ios::app); // ensures file is created in case first-time

    if(Board.fail()){
        cout << "File open error... please restart program" << endl;
        exit(1);
    }
    Board.close();  // will work for first-time creating a file

    ifstream writer;
    writer.open("scoreBoard.txt"); // file will be empty first-time playing
    if(writer.fail()){
        cout << "File open error... please restart program" << endl;
        exit(1);
    }
    
    string line, word; // line for taking whole line from file, word for istringstream
    int nameScore; // temporariry storing each name's score
    
    while(getline(writer, line)){
        //wanna treat 'line' as a new input, and traverse through it
        istringstream iss(line);
        //traversing through the single line below
        while(iss>>word){
            if(!leveling.count(word)){ 
                while(iss>>nameScore){
                    leveling[word]=nameScore; // this way, it stores every user-score in maps
                }
            }
        }
    }
    writer.close(); //we now have our leveling, which has all the data

    if(leveling.count(name)>0){ //i.e. user not-first time, thus Welcome back
        cout << "\nWELCOME BACK, " << name << "!!!" << endl;
        
        if((leveling[name]) > 950){  // i.e 1000 and above, level 5 & 6 unlocked
            // ALL LEVELS UNLOCKED! RETURN ANY DESIRABLE LEVEL
                cout << "Choose Game Difficulty by INSERTING 1,2,3,4,5 or 6:" << endl;
                cout <<"    1 for Easy," << endl;
                cout <<"    2 for Medium," << endl;
                cout <<"    3 for Hard," << endl;
                cout <<"    4 for Extreme," << endl;
                cout <<"    5 for Nightmare, (NOW UNLOCKED!!!)" << endl;
                cout <<"    6 for HELL! (NOW UNLOCKED!!!)\n" << endl;
                cout <<"LEVEL: ";
                cin >> level;
                
                if (level > 6){ // checking for valid input of level
                    cout << "level beyond 6 does not exist, level 6 selected by default." << endl;
                    string gotIt;
                    cout << "press any letter, then ENTER to continue: "; cin >> gotIt;
                    cout << endl;
                    level = 6;
                }
                if (level < 1) { // further checking for valid input of level
                    cout << "No level below 1 exists! Level 1 selected by default." << endl;
                    string gotIt;
                    cout << "press any letter, then ENTER to continue: "; cin >> gotIt;
                    cout << endl;
                    level = 1;
                }
            return level; //terminates here for unlocked levels
        } else {
            
            // not unlocked, previous score 900 or below
                cout << "Choose Game Difficulty by INSERTING 1,2,3,4,5 or 6:" << endl;
                cout <<"    1 for Easy," << endl;
                cout <<"    2 for Medium," << endl;
                cout <<"    3 for Hard," << endl;
                cout <<"    4 for Extreme," << endl;
                cout <<"    5 for Nightmare, (LOCKED, your previous scores are below 1000 for level 1-4)" << endl;
                cout <<"    6 for HELL! (LOCKED, your previous scores are below 1000 for level 1-4)\n" << endl;
                cout <<"LEVEL: ";
                cin >> level;

                if (level > 4){ // checking for valid input of level
                    cout << "reach above 1000 points to unlock level 5 and 6. level 4 selected by default." << endl;
                    string gotIt;
                    cout << "press any letter, then ENTER to continue: "; cin >> gotIt;
                    cout << endl;
                    level = 4;
                }
                if (level < 1) { // further checking for valid input of level
                    cout << "No level below 1 exists! Level 1 selected by default." << endl;
                    string gotIt;
                    cout << "press any letter, then ENTER to continue: "; cin >> gotIt;
                    cout << endl;
                    level = 1;
                }
            return level;
        }
    } else {
        //not unlocked, new player
        cout << "\nWELCOME, " << name << "!!!" << endl;
        cout << "Choose Game Difficulty by INSERTING 1,2,3,4,5 or 6:" << endl;
        cout <<"    1 for Easy," << endl;
        cout <<"    2 for Medium," << endl;
        cout <<"    3 for Hard," << endl;
        cout <<"    4 for Extreme," << endl;
        cout <<"    5 for Nightmare, (LOCKED, reach 1000 points in any level 1-4 to unlock)" << endl;
        cout <<"    6 for HELL! (LOCKED, reach 1000 points in any level 1-4 to unlock)\n" << endl;
        cout <<"LEVEL: ";
        cin >> level;

        if (level > 4){ // checking for valid input of level
            cout << "reach above 1000 points to unlock level 5 and 6. level 4 selected by default." << endl;
            string gotIt;
            cout << "press any letter, then ENTER to continue: "; cin >> gotIt;
            cout << endl;
            level = 4;
        }
        if (level < 1) { // further checking for valid input of level
            cout << "No level below 1 exists! Level 1 selected by default." << endl;
            string gotIt;
            cout << "press any letter, then ENTER to continue: "; cin >> gotIt;
            cout << endl;
            level = 1;
        }
            return level;
    }


}

