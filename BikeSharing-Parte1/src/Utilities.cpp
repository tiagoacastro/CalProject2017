#include "Utilities.h"

void clearCinBuffer(){
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void trimString(string &s) {
    if(s.find_first_not_of(' ') == string::npos){
        s = "";
        return;
    }

    if (s.find(' ') != string::npos) {
        s = s.substr(s.find_first_not_of(' '));
        s = s.substr(0, s.find_last_not_of(' ') + 1);
    }
}
