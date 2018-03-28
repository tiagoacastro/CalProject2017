/*
 * Parser.cpp
 *
 *  Created on: 24/03/2018
 *      Author: ricar
 */

#include "Parser.h"

#include <iomanip>

using namespace std;

vector <string> Parser::readLines(string file)
	{
		vector<string> lines;

		ifstream inFile(file.c_str());
		if (inFile.is_open()) {
			string line;

			while (getline(inFile, line))
				lines.push_back(line);
			inFile.close();
		}
		return lines;
	}

SharingSpot Parser::createSharingSpot(string &line){

}

Node Parser::createNode(string &line) {
    int id;
    double latitude, longitude;
    double latRadians, longRadians;

    try { next(id, line, ";"); } catch (InvalidFormat) {
        cout << "Please insert the SharingSpot data in the correct format.\n";
        return nullptr;
    }

    try { next(latitude, line, ";"); } catch (InvalidFormat) {
        cout << "Please insert the SharingSpot data in the correct format.\n";
        return nullptr;
    }

    try { next(longitude, line, ";"); } catch (InvalidFormat) {
        cout << "Please insert the SharingSpot data in the correct format.\n";
        return nullptr;
    }

    try { next(longRadians, line, ";"); } catch (InvalidFormat) {
        cout << "Please insert the SharingSpot data in the correct format.\n";
        return nullptr;
    }

    latRadians = stod(line);

    //Constructor
}

vector <SharingSpot> Parser::readSharingSpots(string file)
{
}

vector <Node> Parser::readNodes(string file)
{
    vector<string> lines = readLines(file);
    vector <Node> nodes;

    for (auto &line : lines) {
        nodes.push_back(createNode(line));
    }

    return nodes;
}

vector <Street> Parser::readStreets(string file)
{
    vector<Street> s;
	return s;
}

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

void Parser::next(int &elem,string &piece, string separator) {

    string elemstring;
    size_t i;
    bool err = false;
    next(elemstring, piece, separator);
    try {

        elem = stoi(elemstring, &i);

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

bool validString(string &s) {

    getline(cin, s);

    if (s == "") {
        cout << "Invalid input. Reenter.\n";
        return false;
    }

    return true;
}



