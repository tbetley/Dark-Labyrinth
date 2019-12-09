/*********************************************
 * Program Name: key.hpp
 * Author: Tyler Betley
 * Date: 12/10/2019
 * Description: item - key class declaration file.  Key class is derived from item class.
 *      Key holds the number of keys the player has. The Key Space will increase the number of 
 *      keys the player holds.
*********************************************/

#ifndef KEY_HPP
#define KEY_HPP

#include "item.hpp"

class Key : public Item
{
    private:

    public:
        Key();
        void setAmount(int a);
        int getAmount();


};


#endif