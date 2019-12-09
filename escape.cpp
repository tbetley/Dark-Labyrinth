/*********************************************
 * Program Name: escape.cpp
 * Author: Tyler Betley
 * Date: 12/10/2019
 * Description: escape class implementation file.  Escape class inherits from space class.
 *      Interactions with this class may result in win condition if the number of keys is correct.
*********************************************/

#include "escape.hpp"

/**************************************************
** Escape: constructor
**************************************************/
Escape::Escape()
{

}



/**************************************************
** handleSpaceEvent(): Handles the escape win event for the player.
**************************************************/
void Escape::handleSpaceEvent(Player* player)
{
    std::cout << "Escape Event" << std::endl;

    // check if number of keys is correct
    if (player->getItems()[2]->getAmount() >= 3)
    {
        player->setEscaped(true);
    }
    else
    {
        std::cout << "*** You require " << 3 - player->getItems()[2]->getAmount() << " more keys to escape!!!" << std::endl;
    }
    
}
