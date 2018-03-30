#include "Utilities.h"

namespace Utilities {
    void clearCinBuffer() {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    void trimString(string &s) {
        if (s.find_first_not_of(' ') == string::npos) {
            s = "";
            return;
        }

        if (s.find(' ') != string::npos) {
            s = s.substr(s.find_first_not_of(' '));
            s = s.substr(0, s.find_last_not_of(' ') + 1);
        }
    }

    bool isNumber(const string &s) {
        return !s.empty() && find_if(s.begin(), s.end(), [](char c) { return !isdigit(c); }) == s.end();
    }

    bool isEmail(const string &s) {
        // define a regular expression
        const regex pattern ("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");

        // try to match the string with the regular expression
        return regex_match(s, pattern);
    }
}