/*********************************************
 * Program Name: player.cpp
 * Author: Tyler Betley
 * Date: 12/10/2019
 * Description: Player class implementation file. Holds all player relavent information.
 *      Holds player items and location, as well as helper functions.
*********************************************/

#include "player.hpp"


/**************************************************
** constructor: set initial conditions
**************************************************/
Player::Player()
{
    // set up player item list
    itemList.push_back(new Gun);     // add a gun to the items
    itemList.push_back(new Candle);  // add a candle to the items
    itemList.push_back(new Key);     // add a key ring to the items

    // set life
    setAlive(true);

}


/**************************************************
** setXPositon: sets the x position of the player
**************************************************/
void Player::setXPosition(int x)
{
    xPosition = x;
}


/**************************************************
** setYPosition: sets the y position of the player
**************************************************/
void Player::setYPosition(int y)
{
    yPosition = y;
}


/**************************************************
** setAlive(bool b): sets the life condition of the player
**************************************************/
void Player::setAlive(bool b)
{
    alive = b;
}


/**************************************************
** setEscaped(bool e): sets the win condition if the player has escaped
**************************************************/
void Player::setEscaped(bool e)
{
    escaped = e;
}



/**************************************************
** getItems(): returns a pointer to an item within the vector
**************************************************/
std::vector<Item*> Player::getItems()
{
    return itemList;
}



/**************************************************
** getXPosition
**************************************************/
int Player::getXPosition()
{
    return xPosition;
}

/**************************************************
** getYPosition
**************************************************/
int Player::getYPosition()
{
    return yPosition;
}


/**************************************************
** isAlive(): returns the life condition of the user
**************************************************/
bool Player::isAlive()
{
    return alive;
}


/**************************************************
** hasEscaped(): returns true if the player has escaped
**************************************************/
bool Player::hasEscaped()
{
    return escaped;
}



/**************************************************
** destructor: delete memory
**************************************************/
Player::~Player()
{
    for (int i = 0; i < itemList.size(); i++)
    {
        delete itemList[i];
    }
}