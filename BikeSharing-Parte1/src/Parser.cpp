/*
 * Parser.cpp
 *
 *  Created on: 24/03/2018
 *      Author: ricar
 */

#include "Parser.h"

#include <iomanip>

using namespace std;

vector <string> Parser::readLines(string file) {
    vector<string> lines;
    string line;

    ifstream inFile(file);
    if (inFile.is_open()) {
        while (getline(inFile, line)) {
            lines.push_back(line);
        }
        inFile.close();
    }
    return lines;
}

Node Parser::createNode(string &line) {
    unsigned long long int id;
    double latitude, longitude;
    double latRadians, longRadians;

    try { next(id, line, ";"); } catch (InvalidFormat) {
        cout << "Please insert the Node data in the correct format.\n";
    }

    try { next(latitude, line, ";"); } catch (InvalidFormat) {
        cout << "Please insert the Node data in the correct format.\n";
    }

    try { next(longitude, line, ";"); } catch (InvalidFormat) {
        cout << "Please insert the Node data in the correct format.\n";
    }

    try { next(longRadians, line, ";"); } catch (InvalidFormat) {
        cout << "Please insert the Node data in the correct format.\n";
    }

    latRadians = stod(line);

    Node n(id,latRadians,longRadians);

    return n;
}

Street Parser::createStreet(string &line) {

    unsigned long long int id;
    string name , bothways;

    try { next(id, line, ";"); } catch (InvalidFormat) {
        cout << "Please insert the Street data in the correct format.\n";
    }

    try { next(name, line, ";"); } catch (InvalidFormat) {
        cout << "Please insert the Street data in the correct format.\n";
    }

    try { next(bothways, line, ";"); } catch (InvalidFormat) {
        cout << "Please insert the Street data in the correct format.\n";
    }

    Street s(id,name,true);
    if (bothways == "False")
        s.setTwoWays(false);
    return s;
}

Relation Parser::createRelation(string &line) {

    unsigned long long int roadID, node1ID, node2ID;

    try { next(roadID, line, ";"); } catch (InvalidFormat) {
        cout << "Please insert the Relation data in the correct format.\n";
    }

    try { next(node1ID, line, ";"); } catch (InvalidFormat) {
        cout << "Please insert the Relation data in the correct format.\n";
    }

    try { next(node2ID, line, ";"); } catch (InvalidFormat) {
        cout << "Please insert the Relation data in the correct format.\n";
    }

    Relation r(roadID,node1ID,node2ID);

    return r;
}

vector <Node> Parser::readNodes(string file) {
    vector<string> lines = readLines(file);
    vector <Node> nodes;

    for (auto &line : lines) {
        nodes.push_back(createNode(line));
    }

    return nodes;
}

vector <Street> Parser::readStreets(string file) {

    vector<string> lines = readLines(file);
    vector <Street> streets;

    for (auto &line : lines) {
        streets.push_back(createStreet(line));
    }

    return streets;
}

vector <Relation> Parser::readRelations(string file) {

    vector<string> lines = readLines(file);
    vector <Relation> relations;

    for (auto &line : lines) {
        relations.push_back(createRelation(line));
    }

    return relations;
}

//Helper Functions

void Parser::next(string &piece, string &line, string separator) {
    int temp = line.find_first_of(separator);
    if (temp == string::npos) {
        piece = line;
        line = "";
    } else {
        piece = line.substr(0, temp);
        line = line.substr(temp + 1, line.length() - 1);
    }
}

void Parser::next(unsigned long long int &elem,string &piece, string separator) {

    string elemstring;
    size_t i;
    bool err = false;
    next(elemstring, piece, separator);
    try {

        elem = stoull(elemstring, &i);

    } catch (std::invalid_argument &i) {
        err = true;
    }

    if (i != elemstring.length() || err) throw InvalidFormat();
}

void Parser::next(double &elem, string &piece, string separator) {

    string elemstring;
    size_t i;
    bool err = false;
    next(elemstring, piece, separator);
    try {

        elem = stod(elemstring, &i);

    } catch (std::invalid_argument &i) {
        err = true;
    }

    if (i != elemstring.length() || err) throw InvalidFormat();

}

bool Parser::validString(string &s) {

    getline(cin, s);

    if (s == "") {
        cout << "Invalid input. Reenter.\n";
        return false;
    }

    return true;
}



