/*********************************************
 * Program Name: menu.cpp
 * Author: Tyler Betley
 * Date: 10/27/2019
 * Description: Class impelmentation file for the menu class.  This class provides a
 *  scalable menu for use in different programs.
*********************************************/

#include "menu.hpp"

/**************************************************
** startMenu: starting menu for the program. Displays choices for the user and takes/validates user input.
**      Returns the user selection.
**************************************************/
int Menu::startMenu()
{
    int choice;
    do
    {
        std::cout << "\n" << "Dark Labyrinth" << std::endl;
        std::cout << "1) Play" << std::endl;
        std::cout << "2) Quit" << std::endl;
        std::cout << "Enter Your Choice: ";

        return choice = input.getInteger(1, 2);
        
    } while(true);
}

/**************************************************
** movementSelection: prompts user to select movement
**************************************************/
int Menu::movementSelection()
{
    int choice; 
    do
    {
        std::cout << "What Direction Would you Like to Move?" << std::endl;
        std::cout << "1) North" << std::endl;
        std::cout << "2) East" << std::endl;
        std::cout << "3) South" << std::endl;
        std::cout << "4) West" << std::endl;
        std::cout << "Enter Your Choice: ";

        return choice = input.getInteger(1, 4);

    } while (true);
    
}

/**************************************************
**  clearScreen: clears the terminal window using ASCII
**************************************************/
void Menu::clearScreen()
{
    std::cout << "\033[2J\033[1;1H";
}


/**************************************************
** quitGame(): reuturns the quit value condition.
**************************************************/
int Menu::quitGame()
{
    int choice; 
    do
    {
        std::cout << "Would you like to keep playing?" << std::endl;
        std::cout << "1) Yes" << std::endl;
        std::cout << "2) No" << std::endl;
        std::cout << "Enter Your Choice: ";

        return choice = input.getInteger(1, 2);

    } while (true);
    
}


/**************************************************
** fightMonsterOption(): prompts user if they would like to fight the monster
**************************************************/
int Menu::fightMonsterOption()
{
    int choice; 
    do
    {
        std::cout << "You are about to encounter a monster, would you like to continue?" << std::endl;
        std::cout << "1) Yes" << std::endl;
        std::cout << "2) No" << std::endl;
        std::cout << "Enter Your Choice: ";

        return choice = input.getInteger(1, 2);

    } while (true);
    
}