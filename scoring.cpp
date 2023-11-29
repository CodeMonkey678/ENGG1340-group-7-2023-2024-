#include "scoring.h"
#include <map>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
using namespace std;

/* 
    -function takes name and new score after game over, returns nothing
    - handles data storing with user needs and commands, thus actively interacting with user
*/

void scorer(string name, int score){
    map<string,int> mapping; // storing all data efficiently before printing to user & storing to file

    ofstream Board;
    Board.open("scoreBoard.txt", ios::app); // useful for first-time running

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
    
    while(getline(writer, line)){
        //wanna treat 'line' as a new input, and traverse through it
        istringstream iss(line);
        //traversing through the single line below
        while(iss>>word){
            //if(!mapping.count(word)){
            while(iss>>nameScore){
                mapping[word]=nameScore;
                }
            //}
        }
    }
    writer.close();

    //below, if user name exists, h/she is asked if wants to overwrite previous scores
    if(mapping.count(name)>0){
        cout << "\nName already exists... \n";
        cout << "\n Previous score: " << name << " - " << mapping[name] << endl;
        cout << "\noverwrite with new score("<<score<<")? [Y/n]: ";
        string overwrite;
        cin >> overwrite;
        
        if (overwrite=="Y" || overwrite == "y"){
            //nameScore = score; // Update nameScore variable
            mapping[name] = score; // Update mapping[name] with nameScore
            cout << "\nOverwritten!" << endl;
        }
    } else {
        mapping[name] = score; //username is new, so new score and name recorded
    }

    //now printing the entire standing
    map<string, int>::iterator itr;
    Board.open("scoreBoard.txt");
    cout << "\n" << "\nSTATS:\n";
    for(itr=mapping.begin(); itr != mapping.end(); itr++){
        Board << (*itr).first << "  " << (*itr).second << "\n"; //writing to file
        cout << (*itr).first << " - " << (*itr).second << endl; //printing for user to see
        
        
    }
    cout << endl;
    
    Board.close();
    string reset;

    cout << "\nWOULD YOU LIKE TO ERASE ALL STATS DATA? [Y/n]: "; //asks whether restart the stats
    cin >> reset;
    if (reset=="Y" || reset == "y"){
            Board.open("scoreBoard.txt");
            Board.close();
            cout << "\n";
            cout << "\nData reset!" << endl;
        }
}

