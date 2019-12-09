/*********************************************
 * Program Name: floor.hpp
 * Author: Tyler Betley
 * Date: 12/10/2019
 * Description: floor class declaration file. This class inherits from Space class.
 *      floor contains a function that generates a random object for the user to gather.
 *      This object can be added to the inventory.
*********************************************/

#ifndef FLOOR_HPP
#define FLOOR_HPP

#include "space.hpp"

class Floor : public Space
{
    private:

    public:
        Floor();
        void handleSpaceEvent(Player* player);
};


#endif