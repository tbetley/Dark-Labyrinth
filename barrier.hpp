/*********************************************
 * Program Name: barrier.hpp
 * Author: Tyler Betley
 * Date: 12/10/2019
 * Description: Barrier class decraration file. Class inherits from space class.
 *      Barrier provides no real funcitonality to the game.
*********************************************/

#ifndef BARRIER_HPP
#define BARRIER_HPP

#include "space.hpp"

class Barrier : public Space
{
    private:

    public:
        Barrier();
        void handleSpaceEvent(Player* player);  // no event
};


#endif