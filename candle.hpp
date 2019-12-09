/*********************************************
 * Program Name: candle.hpp
 * Author: Tyler Betley
 * Date: 12/10/2019
 * Description: item - candle class declaration file. Candle hold information related to 
 *      the candle object.  The candle represents the time left in the game. Additional candle
 *      wicking can be added by random events in the Floor Space.
*********************************************/

#ifndef CANDLE_HPP
#define CANDLE_HPP

#include "item.hpp"

class Candle : public Item
{
    private:

    public:
        Candle();
        void setAmount(int a);
        int getAmount();
};

#endif