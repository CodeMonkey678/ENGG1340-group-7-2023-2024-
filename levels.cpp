#include "levels.h"
#include <map>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
using namespace std;

int levels(string name){
    int level;
    map<string,int> leveling;

    ofstream Board;
    Board.open("scoreBoard.txt", ios::app);

    if(Board.fail()){
        cout << "File open error... please restart program" << endl;
        exit(1);
    }
    Board.close();  // will work for first-time creating a file

    ifstream writer;
    writer.open("scoreBoard.txt");
    if(writer.fail()){
        cout << "File open error... please restart program" << endl;
        exit(1);
    }
    string line, word;
    int nameScore;
    bool failed = true;
    while(getline(writer, line)){
        //wanna treat 'line' as a new input, and traverse through it
        istringstream iss(line);
        //traversing through the single line below
        while(iss>>word){
            if(!leveling.count(word)){
                while(iss>>nameScore){
                    leveling[word]=nameScore;
                }
            }
        }
    }
    writer.close(); //we have our leveling, which has all the data

    if(leveling.count(name)>0){
        cout << "\nWELCOME BACK, " << name << "!!!" << endl;
        if(leveling[name]>=1000){
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
            return level;
        } else {
            // not unlocked, low scores
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

