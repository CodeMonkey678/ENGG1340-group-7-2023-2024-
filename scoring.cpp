#include <map>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <istream>
using namespace std;

void scorer(string name, int score){
    map<string,int> mapping;

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
            if(!mapping.count(word)){
                while(iss>>nameScore){
                    mapping[word]=nameScore;
                }
            }
        }
    }
    writer.close();

    //now this part is called whenever the player writes his name;
    //Board.open("scoreBoard.txt", ios::app);
    if(mapping.count(name)>0){
        cout << "Name already exists... \n";
        cout << name << " - " << mapping[name] << endl;
        cout << "overwrite? [Y/n]: ";
        string overwrite;
        cin >> overwrite;
        if (overwrite=="Y" || overwrite == "y"){
            mapping[name] = score;
            cout << "\nOverwritten!" << endl;
        }
    } else {
        mapping[name] = score;
    }

    //now printing the entire standing
    map<string, int>::iterator itr;
    Board.open("scoreBoard.txt", ios::app);
    cout << "\nSTATS:\n";
    for(itr=mapping.begin(); itr != mapping.end(); itr++){
        cout << (*itr).first << " - " << (*itr).second << endl;
        Board << (*itr).first << " " << (*itr).second << endl;
    }
    Board.close();
    string reset;

    cout << "\nRESET ALL DATA? [Y/n]: ";
    cin >> reset;
    if (reset=="Y" || reset == "y"){
            Board.open("scoreBoard.txt");
            Board.close();
            cout << "\nData reset!" << endl;
        }
}

