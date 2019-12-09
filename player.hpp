/*********************************************
 * Program Name: player.hpp
 * Author: Tyler Betley
 * Date: 12/10/2019
 * Description: Player class declaration file. Holds all player relavent information.
 *      Holds player items and location, as well as helper functions.
*********************************************/

#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "item.hpp"
#include "gun.hpp"
#include "candle.hpp"
#include "key.hpp"
#include <vector>

class Player
{
    private:
        int xPosition;
        int yPosition;
        bool alive;
        bool escaped;
        std::vector<Item*> itemList;    // vector that holds item objects 

    public:
        Player();      // set initial conditions, location
        ~Player();
        void setXPosition(int x);
        void setYPosition(int y);
        void setAlive(bool b);
        void setEscaped(bool e);

        std::vector<Item*> getItems();
        int getXPosition();
        int getYPosition();
        bool isAlive();
        bool hasEscaped();


};

#endif