/*
 * Parser.h
 *
 *  Created on: 24/03/2018
 *      Author: ricar
 */

#pragma once

#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <random>

#include "SharingSpot.h"
#include "Node.h"
#include "Street.h"
#include "exceptions.h"

using namespace std;

class Parser {

	private:
		vector <string> readLines(string file); //Reads lines from file and stores it in a vector.

	public:
		/**
		 * @brief default constructor of a Parser object
		 */
		Parser() = default;
		/**
		 * @brief Returns a vector with all the nodes after being created from the data read from the file with the name passed as parameter
		 * @param file string
		 * @return vector <Node>
		 */
		vector <Node> readNodes(string file);
		/**
		 * @brief Returns a vector with all the streets after being created from the data read from the file with the name passed as parameter
		 * @param file string
		 * @return vector <Street>
		 */
		vector <Street> readStreets(string file);
		/**
		 * @brief Reads the relations between streets and Nodes and uses that information to complete the streets and nodes objects already created
		 * @param file string
		 * @param streets vector <Street>
		 * @param nodes vector <Node>
		 */
		void readRelations(string file,vector <Street> &streets, vector <Node> &nodes, vector <SharingSpot> &spots );

		/**
		 * Auxiliary function that creates and returns a Node based on the data in the line
		 * @param line
		 * @return Node
		 */
        Node createNode(string &line);
	 	 /**
		 * Auxiliary function that creates and returns a Street based on the data in the line
		 * @param line
		 * @return Street
		 */
		Street createStreet(string &line);
		/**
		 * @brief Analyzes a line from the Relations file and transforms that line into information to be put in Streets and Nodes
		 * @param line string
		 * @param streets vector <Street>
		 * @param nodes vector <Node>
		 * @param streetsID vector <int>
		 */
		void createRelation(string &line, vector <Street> &streets, vector <Node> &nodes, vector <unsigned long long int> &streetsID);

   		/**
        * @brief separates string based on the separator
        * @param elem unsigned long long int &elem
        * @param piece string &piece
        * @param separator string separator
        */
        void next(unsigned long long int &elem, string &piece, string separator);
		/**
        * @brief separates string based on the separator
        * @param elem double &elem
        * @param piece string &piece
        * @param separator string separator
        */
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

		void createSharingSpot(Node n, vector <SharingSpot> &spots);
};
