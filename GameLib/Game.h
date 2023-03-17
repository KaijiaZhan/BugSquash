/**
 * @file Game.h
 * @author rmpal
 * @author Courtney Thang
 * @author Kaijia Joanna Zhan
 * @author Parker Morgan
 */


#ifndef PROJECT1_GAMELIB_GAME_H
#define PROJECT1_GAMELIB_GAME_H

#include "item.h"

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

public:

	/**
	 * Constructor
	 */
	Game();

	void OnDraw(wxDC *dc);
	void Update(double elapsed, long totalTime);
	std::shared_ptr<Item> HitTest(int x, int y);

	void Load(const wxString &filename);

	/// Initializing clearing the old data
	void Clear();

	/// Adds new bug to the game
	void Add(std::shared_ptr<Item> item);

	void Game::XmlItem(wxXmlNode *node);

	void Game::Save(const wxString &filename);

	/**
	 * Get the random number generator
	 * @return Pointer to the random number generator
	 */
	std::mt19937 &GetRandom() { return mRandom; }

};

#endif //PROJECT1_GAMELIB_GAME_H
