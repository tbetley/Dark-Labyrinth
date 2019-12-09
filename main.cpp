/*********************************************
 * Program Name: Final Project - Dark Labrainth
 * Author: Tyler Betley
 * Date: 12/10/2019
 * Description: Main program file for CS162 Final Project, Dark Labyrinth.
 *      This game uses linked spaces to create maze-like escape game, where the
 *      player is racing against the clock to exit the labrinth
*********************************************/

#include "menu.hpp"
#include "game.hpp"
#include <iostream>

int main()
{
    Menu menu;

    menu.clearScreen();

    int choice;
    do
    {
        choice = menu.startMenu();
        if (choice == 1)
        {
            Game game;
            game.run();
        }

    } while (choice != 2);

    return 0;
}