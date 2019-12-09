/*********************************************
 * Program Name: game.hpp
 * Author: Tyler Betley
 * Date: 12/10/2019
 * Description: Game class declaration file, contains all game realated functions
 *      and variables.
*********************************************/

#ifndef GAME_HPP
#define GAME_HPP

#include "menu.hpp"
#include "input.hpp"
#include "space.hpp"
#include "floor.hpp"
#include "barrier.hpp"
#include "monster.hpp"
#include "escape.hpp"
#include "player.hpp"

#include <random>
#include <time.h>
#include <vector>

#define GAME_ROWS 6
#define GAME_COLS 8

class Game
{
    private:
        char MasterGameMap[GAME_ROWS][GAME_COLS] = {
                            {'_', '_', '_', '_', '_', '_', '_', '_'},
                            {'|', 'M', ' ', ' ', 'X', ' ', ' ', '|'},
                            {'|', 'M', 'X', ' ', ' ', 'M', 'M', '|'},
                            {'|', ' ', 'X', ' ', 'X', ' ', ' ', '|'},
                            {'|', ' ', ' ', 'M', 'X', 'X', 'E', '|'},
                            {'-', '-', '-', '-', '-', '-', '-', '-'}
                            };

        char PlayerGameMap[GAME_ROWS][GAME_COLS] = {
                            {'_', '_', '_', '_', '_', '_', '_', '_'},
                            {'|', '?', '?', '?', '?', '?', '?', '|'},
                            {'|', '?', '?', '?', '?', '?', '?', '|'},
                            {'|', '?', '?', '?', '?', '?', '?', '|'},
                            {'|', '?', '?', '?', '?', '?', '?', '|'},
                            {'-', '-', '-', '-', '-', '-', '-', '-'}
                            };

        Space* SpaceMap[GAME_ROWS - 2][GAME_COLS - 2];
        
        Menu menu;
        bool winFlag = false;
        bool loseFlag = false;
        int turn;
        Space* playerSpacePtr = nullptr;      // points to the current space the player is in
        Space* prevPlayerSpacePtr = nullptr;  // points to previous space to allow double linked spaces
        Player* playerPtr;      // initialized player items in player constructor


    public:
        Game();
        ~Game();
        void run();
        void updateMap();
        void printMap();
        void printGameInstructions();
        void printPlayerData();
        void createSpaceBoard();

};



#endif // GAME_HPP