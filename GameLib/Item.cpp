/**
 * @file Item.cpp
 * @author Parker Morgan
 */

#include "pch.h"
#include "Item.h"

#include <string>

class Game;

using namespace std;

/**
 * Constructor
 * @param game The game this item is a member of
 */
Item::Item(Game *game) : mGame(game)
{
}

/**
 * Destructor
 */
Item::~Item()
{

}