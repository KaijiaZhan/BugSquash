/**
 * @file Game.h
 * @author rmpal
 * @author Courtney Thang
 *
 */

#ifndef PROJECT1_GAMELIB_GAME_H
#define PROJECT1_GAMELIB_GAME_H

#include <memory>
#include <vector>

#include "Item.h"


class Game
{
private:
//	/// Background image for Game
//	std::unique_ptr<wxBitmap> mBackground;
//
//	/// All of the items in our Game
//	std::vector<std::shared_ptr<Item>> mItems;
public:

//	/**
//	 * Constructor
//	 */
//	Game();
//
//	/**
//	 * Destructor
//	 */
//	virtual ~Game() = default;

	void OnDraw(wxDC *dc);
};

#endif //PROJECT1_GAMELIB_GAME_H
