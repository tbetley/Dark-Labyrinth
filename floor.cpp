/*********************************************
 * Program Name: floor.cpp
 * Author: Tyler Betley
 * Date: 12/10/2019
 * Description: floor class implementation file. This class inherits from Space class.
 *      floor contains a function that generates a random object for the user to gather.
 *      This object can be added to the inventory.
*********************************************/

#include "floor.hpp"

/**************************************************
** Floor: constructor
**************************************************/
Floor::Floor()
{

}



/**************************************************
** handleSpaceEvent(): Handles the random event for the user.
**************************************************/
void Floor::handleSpaceEvent(Player* player)
{   
    std::cout << "Floor event" << std::endl;   

    if (!visited)  // if this space has not been touched yet
    {
        // create cases for random events
        int randEvent = rand() % 3;

        if (randEvent == 0)     // add bullets
        {
            std::cout << "*** You found two bullets on the ground. They have been added to your items. ***" << std::endl;

            int newBulletAmount = player->getItems()[0]->getAmount() + 2;
            if (newBulletAmount > 10)
            {
                newBulletAmount = 10;
                std::cout << "*** However, you can only carry 10 bullets, the remaining were dropped ***" << std::endl;
                player->getItems()[0]->setAmount(newBulletAmount);
            }
            else
            {
                player->getItems()[0]->setAmount(newBulletAmount);
            }
            
        }
        else if (randEvent == 1)   // add candle wick (time)
        {
            player->getItems()[1]->setAmount(player->getItems()[1]->getAmount() + 2);
            std::cout << "*** You found some candle wick, enough to last two more turns ***" << std::endl;
        }
        else if (randEvent == 2)   // do nothing
        {
            std::cout << "*** No event has occured on this space ***" << std::endl;
        }

        visited = true;
    }
    else 
    {
        std::cout << "* You have been here before *" << std::endl;
    }
    

}
