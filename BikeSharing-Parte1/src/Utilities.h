#pragma once
#include <iostream>
#include <limits>
#include <algorithm>
#include <regex>
using namespace std;

/**
 * @brief Utilities is a namespace created to contain useful functions
 * @addtogroup Utilities
 * @{
 */
namespace Utilities {
    /**
     * @brief Clears cin buffer and error flags
     */
    void clearCinBuffer();

    /**
     * @brief Removes white spaces on the sides of the string
     * @param s     string to trim
     */
    void trimString(string &s);

    /**
     * @brief Checks if the string is a number
     * @param s     string to check
     */
    bool isNumber(const string& s);

    /**
     * @brief Checks if the string is an e-mail
     * @param s     string to check
     */
    bool isEmail(const string& s);
}
/*! @} End of Doxygen Utilities group*/

