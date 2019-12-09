/*********************************************
 * Program Name: item.hpp
 * Author: Tyler Betley
 * Date: 12/10/2019
 * Description: item class declaration file. Abstract parent class for item.
 *      Items are used by the player, each item type hold different data
 *      and can result in different actions within the game.
*********************************************/

#ifndef ITEM_HPP
#define ITEM_HPP

class Item
{
    protected:
        int itemAmount;

    public:
        Item();
        virtual void setAmount(int a) = 0;
        virtual int getAmount() = 0;
};

#endif