/*
 * Parser.cpp
 *
 *  Created on: 24/03/2018
 *      Author: ricar
 */

#include "Parser.h"

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

