/*********************************************
 * Program Name: gun.hpp
 * Author: Tyler Betley
 * Date: 12/10/2019
 * Description: item - gun class declaration file. Derived class from item parent.
 *      Gun hold the number of bullets.  More bullets can be added to the class 
 *      dependent on Floor Space random item events
*********************************************/

#ifndef GUN_HPP
#define GUN_HPP

#include "item.hpp"

class Gun : public Item
{
    private:

    public:
        Gun();
        virtual void setAmount(int a);
        virtual int getAmount();

};

#endif