/*********************************************
 * Program Name: space.hpp
 * Author: Tyler Betley
 * Date: 12/10/2019
 * Description: space class declaration file.  Space is a linked structure class.
 *      It points to four other spaces that are derived from this class (N, S, E, W).
 *      This is an abstract class.
*********************************************/

#ifndef SPACE_HPP
#define SPACE_HPP

#include <iostream>
#include "player.hpp"
#include <random>

class Space
{
    public:
        Space* north;
        Space* south;
        Space* east;
        Space* west;
        bool visited;

        Space();
        virtual void handleSpaceEvent(Player* player) = 0;

};


#endif