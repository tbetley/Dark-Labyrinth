/*********************************************
 * Program Name: input.cpp
 * Author: Tyler Betley
 * Date: 10/27/2019
 * Description: Class implementation file for the input class. This class takes input and
 *  validates it depending on the type selected as the input.
*********************************************/

#include "input.hpp"


/**************************************************
** getInteger: returns and integer value; Max Value 999999999.
**************************************************/
int Input::getInteger()
{
    // use getline to get a string
    std::string input;
    bool validInt = false;

    // loop through the input, if invalid input, retry
    do
    {
        std::getline(std::cin, input);

        // handle cin failure
        if (std::cin.fail())
        {
            std::cout << "Retry input (expect integer): ";
        }
        // handle large inputs
        else if (input.length() > 9)
        {
            std::cout << "Retry input (expect integer): ";
        }
        else
        {
            // loop through and check if integer
            for (int i = 0; i < input.length(); i++)
            {
                if(std::isdigit(input[i]) == false)
                {
                    validInt = false;
                    std::cout << "Retry input (expect integer): ";
                    break;
                }
                validInt = true;
            }
        }

    } while(!validInt);

    // convert int and return
    return std::stoi(input, nullptr);

}

/**************************************************
** getInteger (int min, int max): returns and integer value based on min and max values
**************************************************/
int Input::getInteger(int min, int max)
{
    std::string input;
    int output;
    bool validInt = false;

    // loop over, getting input and validating 
    do
    {
        std::getline(std::cin, input);

        // handle cin failure
        if (std::cin.fail())
        {
            std::cout << "cin failure, retry input: ";
            std::cin.clear();
            break;
        }

        // convert to stringstream
        std::stringstream extraction(input);

        if (extraction >> output && !(extraction >> input))
        {
            if (output >= min && output <= max)
            {
                validInt = true;
            }
            else
            {
                std::cout << "Integer out of range, retry input: ";
            }
            
        }
        else
        {
            std::cout << "Not an Integer, Retry input: ";
        }
        
    } while(!validInt);

    return output;
}