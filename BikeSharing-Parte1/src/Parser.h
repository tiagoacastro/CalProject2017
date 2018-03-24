/*
 * Parser.h
 *
 *  Created on: 24/03/2018
 *      Author: ricar
 */

#ifndef PARSER_H_
#define PARSER_H_


#include <vector>
#include <string>
#include <fstream>

#include "SharingSpot.h"
#include "Node.h"
#include "Street.h"

using namespace std;

class Parser {

	private:
		static vector <string> readLines(string file); //Reads lines from file and stores it in a vector.

	public:
		static vector <SharingSpot> readSharingSpots(string file);
		static vector <Node> readNodes(string file);
		static vector <Street> readStreets(string file);
};



#endif /* PARSER_H_ */
