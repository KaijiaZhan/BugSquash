/**
 * @file Game.h
 * @author rmpal
 * @author Courtney Thang
 * @author Kaijia Joanna Zhan
 */


#ifndef PROJECT1_GAMELIB_GAME_H
#define PROJECT1_GAMELIB_GAME_H

#include <memory>
#include <string>
#include "item.h"

class Item;

/**
 * Class game that holds all of the items
 */
class Game
{
private:

	/// All of the items in our Game
	std::vector<std::shared_ptr<Item>> mItems;

public:

	/**
	 * Constructor
	 */
	Game();

	void OnDraw(wxDC *dc);

};

#endif //PROJECT1_GAMELIB_GAME_H
