/*********************************************
 * Program Name: space.cpp
 * Author: Tyler Betley
 * Date: 12/10/2019
 * Description: space class inpmlementation file.  Space is a linked structure class.
 *      It points to four other spaces that are derived from this class (N, S, E, W).
 *      This is an abstract class.
*********************************************/

#include "space.hpp"

Space::Space()
{
    visited = false;
}