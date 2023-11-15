#include <iostream>
using namespace std;

int main(){
    cout<< "Welcome to the maze game" <<endl;

    cout<< "Please enter your name" <<endl ;

    string playername;
    string level;
    cin >> playername;
    cout<< "Hello " << playername <<endl ;
    
    bool input = true;
    while (input==true){
        cout << "Please select the maze level" << endl;
    cout << "Low , middle or high" << endl;
    cin >> level;
        if (level=="Low" || level == "low"){
            cout << "You have chosen " << level  <<" level maze" <<endl;
            input=false;
        }
        else if (level == "Middle" || level == "middle" ){
            cout << "You have chosen " << level  <<" level maze" <<endl;
            input=false;
        } else if (level == "High" || level == "high"){
            cout << "You have chosen " << level  <<" level maze"<< endl;
            input=false;
            
        } else {
            cout << "invalid try again" << endl;
        }
    }
    
    cout<<endl;

    return 0;
}
