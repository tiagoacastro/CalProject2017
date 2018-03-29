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
#include <iostream>

#include "SharingSpot.h"
#include "Node.h"
#include "Street.h"
#include "Relation.h"
#include "exceptions.h"

using namespace std;

class Parser {

	private:
		vector <string> readLines(string file); //Reads lines from file and stores it in a vector.

	public:
		Parser() {};
        vector <SharingSpot> readSharingSpots(string file);
		vector <Node> readNodes(string file);
		vector <Street> readStreets(string file);
		vector <Relation> readRelations(string file);

        SharingSpot createSharingSpot(string &line);

        Node createNode(string &line);
		Street createStreet(string &line);
		Relation createRelation(string &line);

   		/**
        * @brief separates string based on the separator
        * @param elem int &elem
        * @param piece string &piece
        * @param separator string separator
        */
        void next(unsigned long long int &elem, string &piece, string separator);

        void next(double &elem, string &piece, string separator);

        /**
        * @brief separates string based on the separator
        * @param piece
        * @param line
        * @param separator
        */
        void next(string &piece, string &line, string separator);

    /**
        * @brief checks if input is valid
        * @param s string &s
        * @return true if input is valid and false otherwise
        */
        bool validString(string &s);
};



#endif /* PARSER_H_ */
