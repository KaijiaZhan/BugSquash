/**
 * @file Game.h
 * @author rmpal
 * @author Courtney Thang
 * @author Kaijia Joanna Zhan
 * @author Parker Morgan
 */


#ifndef PROJECT1_GAMELIB_GAME_H
#define PROJECT1_GAMELIB_GAME_H

#include "Item.h"
#include "Level.h"

#include <memory>
#include <string>
#include <algorithm>
#include <random>

class Item;

/**
 * Class game that holds all of the items
 */
class Game
{
private:

	/// All of the items in our Game
	std::vector<std::shared_ptr<Item>> mItems;

	///Random number generator
	std::mt19937 mRandom;

	/// Game area in virtual pixels
	const static int Width = 1250;

	/// Game area height in virtual pixels
	const static int Height = 1000;

	/// boolean that sets window size
	bool mShrinked = false;

	/// XML for level 0
	Level mLevel0;

	/// XML for level 1
	Level mLevel1;

	/// XML for level 2
	Level mLevel2;

	/// XML for level 3
	Level mLevel3;

public:

	/**
	 * Constructor
	 */
	Game();

	void OnDraw(wxDC *dc);
	void Update(double elapsed, long totalTime);
	std::shared_ptr<Item> HitTest(int x, int y);

	void LoadLevel(int level);

	/// Initializing clearing the old data
	void Clear();

	/// Adds new bug to the game
	void Add(std::shared_ptr<Item> item);

	void Save(const wxString &filename);

	/**
	 * Get the random number generator
	 * @return Pointer to the random number generator
	 */
	std::mt19937 &GetRandom() { return mRandom; }

	void SetLevel(std::vector<std::shared_ptr<Item>> levelItems) {mItems = levelItems;}

};

#endif //PROJECT1_GAMELIB_GAME_H
