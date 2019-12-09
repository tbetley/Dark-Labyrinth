/*********************************************
 * Program Name: monster.hpp
 * Author: Tyler Betley
 * Date: 12/10/2019
 * Description: monster class declaration file.  Monster inherits from space class.
 *      Handles fighting sequences with the player
*********************************************/

#include "monster.hpp"

/**************************************************
** monster(): constructor
**************************************************/
Monster::Monster()
{

}



/**************************************************
** handleSpaceEvent():  handles the attack sequence with the player
**************************************************/
void Monster::handleSpaceEvent(Player* player)
{
    std::cout << "Monster Event" << std::endl;

    if (!visited)  // if this space has not been touched yet
    {
        // get random even for different monsters
        int randMonster = rand() % 3;
        
        // print monster in ascii
        if (randMonster == 0) printSpider();
        else if (randMonster == 1) printHellMonster();
        else if (randMonster == 2) printCyclops();

        // handle killing the monster
        if (player->getItems()[0]->getAmount() >= 2)
        {
            player->getItems()[0]->setAmount(player->getItems()[0]->getAmount() - 2); // reduce the number of bullets
            player->getItems()[2]->setAmount(player->getItems()[2]->getAmount() + 1); // add a key to player items
            std::cout << "*** You fire 2 bullets at the monster, killing it. ***" << std::endl;
            std::cout << "*** You find one key on the monsters body! ***" << std::endl;
            
        }
        else
        {
            std::cout << "You attempt to shoot at the monster, but you do not have enough rounds to kill it..." << std::endl;
            player->setAlive(false);
        }

        visited = true;
    }
    else 
    {
        std::cout << "* You have been here before *" << std::endl;
    }
}



/********** Monsters Sourced from: asciiart.eu ****************/
/**************************************************
** printSpider(): prints a spider in ASCII to the screen
**************************************************/
void Monster::printSpider()
{
std::cout << R"(               ____                      ,)" << std::endl;
std::cout << R"(          /---.'.__             ____//)" << std::endl;
std::cout << R"(               '--.\           /.---')" << std::endl;
std::cout << R"(          _______  \\         //)" << std::endl;
std::cout << R"(        /.------.\  \|      .'/  ______)" << std::endl;
std::cout << R"(       //  ___  \ \ ||/|\  //  _/_----.\__)" << std::endl;
std::cout << R"(         //   \'. | \'.|.'/ /_/ /  \\)" << std::endl;
std::cout << R"(        //     \ \_\/" ' ~\-'.-'    \\)" << std::endl;
std::cout << R"(       //       '-._| :H: |'-.__     \\)" << std::endl;
std::cout << R"(      //           (/'==='\)'-._\     ||)" << std::endl;
std::cout << R"(      ||                        \\    \|)" << std::endl;
std::cout << R"(      ||                         \\    ')" << std::endl;
std::cout << R"(      |/                          \\)" << std::endl;
std::cout << R"(                                   ||)" << std::endl;
std::cout << R"(                                   ||)" << std::endl;
std::cout << R"(                                   \\)" << std::endl;
std::cout << R"(                                    ')" << std::endl;
}


/**************************************************
** printHellMonster(): prints a monster in ASCII to the screen
**************************************************/
void Monster::printHellMonster()
{
std::cout << R"(                            ,-.                             )" << std::endl;      
std::cout << R"(       ___,---.__          /'|`\          __,---,___        )" << std::endl;  
std::cout << R"(    ,-'    \`    `-.____,-'  |  `-.____,-'    //    `-.     )" << std::endl;  
std::cout << R"(  ,'        |           ~'\     /`~           |        `.   )" << std::endl;   
std::cout << R"( /      ___//              `. ,'          ,  , \___      \  )" << std::endl;  
std::cout << R"(|    ,-'   `-.__   _         |        ,    __,-'   `-.    | )" << std::endl;   
std::cout << R"(|   /          /\_  `   .    |    ,      _/\          \   | )" << std::endl;  
std::cout << R"(\  |           \ \`-.___ \   |   / ___,-'/ /           |  / )" << std::endl; 
std::cout << R"( \  \           | `._   `\\  |  //'   _,' |           /  /  )" << std::endl;    
std::cout << R"(  `-.\         /'  _ `---'' , . ``---' _  `\         /,-'   )" << std::endl;  
std::cout << R"(     ``       /     \    ,='/ \`=.    /     \       ''      )" << std::endl;    
std::cout << R"(             |__   /|\_,--.,-.--,--._/|\   __|              )" << std::endl;    
std::cout << R"(             /  `./  \\`\ |  |  | /,//' \,'  \              )" << std::endl;    
std::cout << R"(eViL        /   /     ||--+--|--+-/-|     \   \             )" << std::endl;    
std::cout << R"(           |   |     /'\_\_\ | /_/_/`\     |   |            )" << std::endl;    
std::cout << R"(            \   \__, \_     `~'     _/ .__/   /             )" << std::endl;
std::cout << R"(             `-._,-'   `-._______,-'   `-._,-'              )" << std::endl;
}



/**************************************************
** printCyclops(): prints a monster in ASCII to the screen
**************************************************/
void Monster::printCyclops()
{
std::cout << R"(       .-'.'.'.'.'.'.`-.            )" << std::endl;
std::cout << R"(     .'.'.'.'.'.'.'.'.'.`.          )" << std::endl;   
std::cout << R"(    /.'.'               '.\         )" << std::endl;
std::cout << R"(    |.'    _.--...--._     |        )" << std::endl;
std::cout << R"(    \    `._.-.....-._.'   /        )" << std::endl;
std::cout << R"(    |     _..- .-. -.._   |         )" << std::endl;
std::cout << R"( .-.'    `.   ((@))  .'   '.-.      )" << std::endl;
std::cout << R"(( ^ \      `--.   .-'     / ^ )     )" << std::endl;
std::cout << R"( \  /         .   .       \  /      )" << std::endl;
std::cout << R"( /          .'     '.  .-    \      )" << std::endl;
std::cout << R"(( _.\    \ (_`-._.-'_)    /._\)     )" << std::endl;
std::cout << R"( `-' \   ' .--.          / `-'      )" << std::endl;
std::cout << R"(     |  / /|_| `-._.'\   |          )" << std::endl;
std::cout << R"(     |   |       |_| |   /-.._      )" << std::endl;
std::cout << R"( _..-\   `.--.______.'  |           )" << std::endl;
std::cout << R"(      \       .....     |           )" << std::endl;
std::cout << R"(       `.  .'      `.  /            )" << std::endl;
std::cout << R"(         \           .'             )" << std::endl;
std::cout << R"(  LGB     `-..___..-`               )" << std::endl;
}