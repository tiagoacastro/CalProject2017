#pragma once
#include <vector>
#include <string>
#include <algorithm>
#include "BikeCompany.h"
#include "Utilities.h"
using namespace std;
/**
 * Gets information about the user
 * @return  user class with information
 */
User askUser();
/**
 * starts the menu
 * @param company   company class used to call functions
 */
void startMenu(BikeCompany &company);
/**
 * menu for the path options
 * @param company   company class used to call functions
 */
void calculatePath (BikeCompany &company);
/**
 * Output shortest path
 * @param company   company class used to call functions
 */
void shortestPath(BikeCompany &company);
/**
 * Output cheapest path
 * @param company   company class used to call functions
 */
void cheapestPath(BikeCompany &company);
