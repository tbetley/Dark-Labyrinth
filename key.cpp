/*********************************************
 * Program Name: key.cpp
 * Author: Tyler Betley
 * Date: 12/10/2019
 * Description: item - key class implementation file.  Key class is derived from item class.
 *      Key holds the number of keys the player has. The Key Space will increase the number of 
 *      keys the player holds.
*********************************************/

#include "key.hpp"

/**************************************************
** constructor: set initial conditions
**************************************************/
Key::Key()
{
    setAmount(0);
}


/**************************************************
** setAmount(int a): sets the amount of bullets
**************************************************/
void Key::setAmount(int a)
{
    itemAmount = a;
}


/**************************************************
** getAmount(): gets the amount of bullets remaining
**************************************************/
int Key::getAmount()
{
    return itemAmount;
}