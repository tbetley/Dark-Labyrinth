/*********************************************
 * Program Name: gun.cpp
 * Author: Tyler Betley
 * Date: 12/10/2019
 * Description: item - gun class implementation file. Derived class from item parent.
 *      Gun hold the number of bullets.  More bullets can be added to the class 
 *      dependent on Floor Space random item events
*********************************************/

#include "gun.hpp"

/**************************************************
** constructor: set initial conditions
**************************************************/
Gun::Gun()
{
    setAmount(6);  // set number of bullets
}



/**************************************************
** setAmount(int a): sets the amount of bullets
**************************************************/
void Gun::setAmount(int a)
{
    itemAmount = a;
    if (itemAmount > 10)  // limit round capacity
    {
        itemAmount = 10;
    }
}


/**************************************************
** getAmount(): gets the amount of bullets remaining
**************************************************/
int Gun::getAmount()
{
    return itemAmount;
}