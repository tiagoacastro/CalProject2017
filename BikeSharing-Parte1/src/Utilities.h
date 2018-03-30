#ifndef UTILITIES_H_
#define UTILITIES_H_

#include <iostream>
#include <limits>
using namespace std;

/**
 * @brief Clears cin buffer and error flags
 */
void clearCinBuffer();

/**
 * @brief Removes white spaces on the sides of the string
 * @param s     string to trim
 */
void trimString(string &s);

#endif //UTILITIES_H_
