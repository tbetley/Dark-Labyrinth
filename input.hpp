/*********************************************
 * Program Name: input.hpp
 * Author: Tyler Betley
 * Date: 10/6/2019
 * Description: Class declaration file for the input class. This class takes input and
 *  validates it depending on the type selected as the input.
*********************************************/
#ifndef INPUT_HPP
#define INPUT_HPP

#include <string>
#include <iostream>
#include <sstream>

class Input
{
    public:
        int getInteger();
        int getInteger(int min, int max);

};

#endif

