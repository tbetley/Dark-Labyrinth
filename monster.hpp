/*********************************************
 * Program Name: monster.hpp
 * Author: Tyler Betley
 * Date: 12/10/2019
 * Description: monster class declaration file.  Monster inherits from space class.
 *      Handles fighting sequences with the player
*********************************************/

#ifndef MONSTER_HPP
#define MONSTER_HPP

#include "space.hpp"

class Monster : public Space
{
    private:

    public:
        Monster();
        void handleSpaceEvent(Player* player);
        void printSpider();
        void printHellMonster();
        void printCyclops();
};


#endif