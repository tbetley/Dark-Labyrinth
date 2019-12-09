/*********************************************
 * Program Name: candle.cpp
 * Author: Tyler Betley
 * Date: 12/10/2019
 * Description: item - candle class implementation file. Candle hold information related to 
 *      the candle object.  The candle represents the time left in the game. Additional candle
 *      wicking can be added by random events in the Floor Space.
*********************************************/

#include "candle.hpp"

/**************************************************
** candle(): set intitial candle conditions
**************************************************/
Candle::Candle()
{
    setAmount(10); // initial turn time of 10
}



/**************************************************
** setWick(int w): sets the wick of the candle
**************************************************/
void Candle::setAmount(int a)
{
    itemAmount = a;
}


/**************************************************
** getWick(): returns the amount of wick left
**************************************************/
int Candle::getAmount()
{
    return itemAmount;
}