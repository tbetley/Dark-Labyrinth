/*********************************************
 * Program Name: game.cpp
 * Author: Tyler Betley
 * Date: 12/10/2019
 * Description: Game class implementation file, contains all game realated functions
 *      and variables.
*********************************************/

#include "game.hpp"

/**************************************************
** Game: constructor to set initial starting values 
**************************************************/
Game::Game()
{
    // set player data
    playerPtr = new Player;
    playerPtr->setXPosition(1);
    playerPtr->setYPosition(4);
    turn = 1;

    // set random seed
    srand(time(NULL));

    // create and link map
    createSpaceBoard();

    // assign player space pointer to starting location
    playerSpacePtr = SpaceMap[playerPtr->getYPosition() - 1][playerPtr->getXPosition() - 1];
    prevPlayerSpacePtr = playerSpacePtr;

}


/**************************************************
** run(): runs the game instance, controls overall game flow
**************************************************/
void Game::run()
{
    // clear screen and print instructions
    menu.clearScreen();
    

    // run game loop
    while (!loseFlag && !winFlag)
    {
        printGameInstructions();
        // display player inventory

        updateMap(); // update player map

        printPlayerData();  // print current player and game infomation

        printMap();  // print current player map


        // display movement options and check boundary conditions to verify valid move
        int movement;
        bool validMove;
        do
        {
            validMove = true;
            movement = menu.movementSelection();
            int row;
            int col;
            if (movement == 1) // north
            {
                row = playerPtr->getYPosition() - 1;
                col = playerPtr->getXPosition();
                playerSpacePtr = playerSpacePtr->north;
            }
            else if (movement == 2) // east
            {
                row = playerPtr->getYPosition();
                col = playerPtr->getXPosition() + 1;
                playerSpacePtr = playerSpacePtr->east;
            }
            else if (movement == 3) // south
            {
                row = playerPtr->getYPosition() + 1;
                col = playerPtr->getXPosition();
                playerSpacePtr = playerSpacePtr->south;
            }
            else if (movement == 4) // west
            {
                row = playerPtr->getYPosition();
                col = playerPtr->getXPosition() - 1;
                playerSpacePtr = playerSpacePtr->west;
            }
            else
            {
                validMove = false;
            }
            
            if (validMove)
            {
                char move = PlayerGameMap[row][col];
                if (move == 'X' || move == '-' || move == '|' || move == '_')
                {
                    validMove = false;
                    playerSpacePtr = prevPlayerSpacePtr;   // point player back to where they were, move invalid
                }
                else
                {
                    // handle monster condition, ask user if they would like to stay away
                    if (move == 'M')
                    {
                        int monsterChoice = menu.fightMonsterOption();
                        if (monsterChoice == 1)
                        {
                            playerSpacePtr->handleSpaceEvent(playerPtr);  // move is valid, handle space event and player interaction, dependent on type of space

                            // leave a space in previous location in playerMap and MasterMap
                            PlayerGameMap[playerPtr->getYPosition()][playerPtr->getXPosition()] = ' ';
                            MasterGameMap[playerPtr->getYPosition()][playerPtr->getXPosition()] = ' ';

                            // update player location, and update map location
                            playerPtr->setXPosition(col);
                            playerPtr->setYPosition(row);
                            prevPlayerSpacePtr = playerSpacePtr; // update previous pointer
                        }   
                        else if (monsterChoice == 2)
                        {
                            std::cout << "You have decided to run away, your candle is still burning..." << std::endl;
                            playerSpacePtr = prevPlayerSpacePtr;   // point player back to where they were, move invalid
                        }
                        
                    }
                    else if (move == 'E')
                    {
                        playerSpacePtr->handleSpaceEvent(playerPtr);  // sets escaped condition
                        playerSpacePtr = prevPlayerSpacePtr;          // do not move the player to the next position
                    }
                    else
                    {
                        playerSpacePtr->handleSpaceEvent(playerPtr);  // move is valid, handle space event and player interaction, dependent on type of space

                        // leave a space in previous location in playerMap and MasterMap

                        PlayerGameMap[playerPtr->getYPosition()][playerPtr->getXPosition()] = ' ';
                        MasterGameMap[playerPtr->getYPosition()][playerPtr->getXPosition()] = ' ';
                        
                        // update player location, and update map location
                        playerPtr->setXPosition(col);
                        playerPtr->setYPosition(row);
                        prevPlayerSpacePtr = playerSpacePtr; // update previous pointer
                    }
                    
                    
                }
            }

        } while (!validMove);
        
        // decrement the candle wick
        playerPtr->getItems()[1]->setAmount(playerPtr->getItems()[1]->getAmount() - 1);
        
        // increment the turn
        turn++;

        // check win/lose conditions by priority
        if (playerPtr->hasEscaped())
        {
            std::cout << "***************************************" << std::endl;
            std::cout << "************ YOU ESCAPED **************" << std::endl;
            std::cout << "***************************************" << std::endl;
            winFlag = true;
        }
        else if (playerPtr->isAlive() == false)
        {
            std::cout << "***************************************" << std::endl;
            std::cout << "************** GAME OVER **************" << std::endl;
            std::cout << "***************************************" << std::endl;
            loseFlag = true;
        }
        else if (playerPtr->getItems()[1]->getAmount() <= 0)  // check if candle is out of wick and print lose condition
        {
            loseFlag = true;
            std::cout << "**************************************" << std::endl;
            std::cout << "YOUR CANDLE RAN OUT OF WICK, GAME OVER" << std::endl;
            std::cout << "**************************************" << std::endl;
        }

    
        // exit or continue prompt, keeps data on screen
        int quitVal = menu.quitGame();
        if (quitVal == 2)
        {
            loseFlag = true;
        }

        menu.clearScreen();
    }
}


/**************************************************
** printGameInstructions
**************************************************/
void Game::printGameInstructions()
{
    std::cout << "You wake up in an unknown place. A lone candle lights only a few feet around you." << std::endl;
    std::cout << "You have a bag with you. You look inside to find a compass, a map, a gun, and a note."  << std::endl;
    std::cout << "The note reads: \"You are not alone. Find the three keys and the exit to escape\"." << std::endl;
    std::cout << std::endl;
}


/**************************************************
** updateMap(): reveals map locations based on player location
**************************************************/
void Game::updateMap()
{
    // reassign player location and reveal locations on player game map
    int row = playerPtr->getYPosition();
    int col = playerPtr->getXPosition();
    PlayerGameMap[row][col] = 'P';
    PlayerGameMap[row - 1][col] = MasterGameMap[row - 1][col];
    PlayerGameMap[row + 1][col] = MasterGameMap[row + 1][col];
    PlayerGameMap[row][col - 1] = MasterGameMap[row][col - 1];
    PlayerGameMap[row][col + 1] = MasterGameMap[row][col + 1];
}

/**************************************************
** printMap(): prints the current game map
**************************************************/
void Game::printMap()
{
    std::cout << "MAP:" << std::endl;
    for (int i = 0; i < GAME_ROWS; i++)
    {
        for (int j = 0; j < GAME_COLS; j++)
        {
            std::cout << PlayerGameMap[i][j] << ' ';
        }
        std::cout << std::endl;
    }
}


/**************************************************
** printPlayerData(): prints current player and game information
**************************************************/
void Game::printPlayerData()
{
    std::cout << "********** Turn: " << turn << " **********" << std::endl;
    std::cout << "Candle Remaining: " << playerPtr->getItems()[1]->getAmount() << std::endl;
    std::cout << "Bullets Remainig: " << playerPtr->getItems()[0]->getAmount() << std::endl;
    std::cout << "Keys Found: " << playerPtr->getItems()[2]->getAmount() << std::endl;
}



/**************************************************
** createSpaceBoard(): creates a the linked 2D space based on MasterMap
**************************************************/
void Game::createSpaceBoard()
{
    // loop over the master map, create new spaces for each position
    for (int i = 1; i < 5; i++) // for each row
    {
        for (int j = 1; j < 7; j++)   // for each column
        {
            if (MasterGameMap[i][j] == ' ')     // create new floor
            {
                SpaceMap[i - 1][j - 1] = new Floor;
            }
            else if (MasterGameMap[i][j] == 'X')   // create new barrier
            {
                SpaceMap[i - 1][j - 1] = new Barrier;
            }
            else if (MasterGameMap[i][j] == 'M')   // create new monster
            {
                SpaceMap[i - 1][j - 1] = new Monster;
            }
            else if (MasterGameMap[i][j] == 'E')   // create new escape
            {
                SpaceMap[i - 1][j - 1] = new Escape;
            }
        }
    }

    // link spaces together
    for (int i = 0; i < 4; i++)  // for each row
    {
        for (int j = 0; j < 6; j++)  // for each column
        {
            Space* tempPtr = SpaceMap[i][j];

            // handle north
            if (i - 1 < 0)
            {
                tempPtr->north = nullptr;
            }
            else
            {
                tempPtr->north = SpaceMap[i - 1][j];
            }

            // handle east
            if (j + 1 > 5)
            {
                tempPtr->east = nullptr;
            }
            else
            {
                tempPtr->east = SpaceMap[i][j + 1];
            }
            
            // handle south
            if (i + 1 > 3)
            {
                tempPtr->south = nullptr;
            }
            else
            {
                tempPtr->south = SpaceMap[i + 1][j];
            }
            
            // handle west
            if (j - 1 < 0)
            {
                tempPtr->west = nullptr;
            }
            else
            {
                tempPtr->west = SpaceMap[i][j - 1];
            }
            
        }
    }
}


/**************************************************
** Destructor: delete all allocated memory
**************************************************/
Game::~Game()
{
    delete playerPtr;

    // delete spaces from linked list
    for (int i = 0; i < 4; i++)  // for each row
    {
        for (int j = 0; j < 6; j++)  // for each column
        {
            delete SpaceMap[i][j];
        }
    }
}