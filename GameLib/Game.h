/**
 * @file Game.h
 * @author rmpal
 * @author Courtney Thang
 * @author Kaijia Joanna Zhan
 */

#ifndef PROJECT1_GAMELIB_GAME_H
#define PROJECT1_GAMELIB_GAME_H

#include <memory>

using namespace std;

class Item;


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
