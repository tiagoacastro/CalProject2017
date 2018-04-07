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

bool findStreetID(vector<int> streets, int streetID){

    for(int i = 0; i < streets.size(); i++) {
        if (streets.at(i) == streetID)
            return true;
    }
    return false;
}

int findStreet(vector<Street> streets, int id){

    for(int i = 0; i < streets.size(); i++) {
        if (streets.at(i).getId() == id)
            return i;
    }
    return -1;
}

int findNode(vector<Node> nodes, unsigned long long int id){

    for(int i = 0; i < nodes.size(); i++) {
        if (nodes.at(i).getId() == id)
            return i;
    }
    return -1;
}

void Parser::createRelation(string &line, vector <Street> &streets, vector <Node> &nodes, vector <int> &streetsID) {

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

    int i = findStreet(streets ,roadID);
    int j1 = findNode(nodes, node1ID);
    int j2 = findNode(nodes, node2ID);

    if (!findStreetID(streetsID,roadID))  {
        streets.at(i).addNode(nodes.at(j1));
        streetsID.push_back(streets.at(i).getId());
    }

    nodes.at(j1).addStreet(streets.at(i).getId());

    if (streets.at(i).isTwoWays()){
        nodes.at(j2).addStreet(streets.at(i).getId());
    }

    streets.at(i).addNode(nodes.at(j2));
}

vector <Node> Parser::readNodes(string file, vector <SharingSpot> &spots) {
    vector<string> lines = readLines(file);
    vector <Node> nodes;
    int rand;

    for (auto &line : lines) {

        Node n = createNode(line);

        nodes.push_back(n);

        
        rand = std::rand()%5+1;

        switch(rand) {
            case 1:
                spots.push_back(SharingSpot(n));
                break;
            default:
                break;
        }

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

void Parser::readRelations(string file,vector <Street> &streets, vector <Node> &nodes ) {

    vector<string> lines = readLines(file);
    vector <int> ids;

    for (auto &line : lines) {

        createRelation(line, streets,nodes, ids);

    }
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



