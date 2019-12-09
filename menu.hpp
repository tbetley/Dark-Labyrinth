/*********************************************
 * Program Name: menu.hpp
 * Author: Tyler Betley
 * Date: 10/27/2019
 * Description: Class declaration file for the menu class.  This class provides a
 *  scalable menu for use in different programs.
*********************************************/

#ifndef MENU_HPP
#define MENU_HPP
#include "input.hpp"
#include <iostream>

class Menu
{
    private:
        Input input;

    public:
        int startMenu();

        int movementSelection();
        
        void clearScreen();

        int quitGame();

        int fightMonsterOption();
};

#endif