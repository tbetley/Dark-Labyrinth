/*********************************************
 * Program Name: escape.hpp
 * Author: Tyler Betley
 * Date: 12/10/2019
 * Description: escape class declaration file.  Escape class inherits from space class.
 *      Interactions with this class may result in win condition if the number of keys is correct.
*********************************************/

#ifndef ESCAPE_HPP
#define ESCAPE_HPP

#include "space.hpp"

class Escape : public Space
{
    private:

    public:
        Escape();
        void handleSpaceEvent(Player* player);
};


#endif