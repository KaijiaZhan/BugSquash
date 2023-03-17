/**
 * @file Game.h
 * @author rmpal
 * @author Courtney Thang
 * @author Kaijia Joanna Zhan
 * @author Parker Morgan
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
	void Update(double elapsed, long totalTime);
	std::shared_ptr<Item> HitTest(int x, int y);

	void Load(const wxString &filename);

	/// Initializing clearing the old data
	void Clear();

	/// Adds new bug to the game
	void Add(std::shared_ptr<Item> item);

	void Game::XmlItem(wxXmlNode *node);


};

#endif //PROJECT1_GAMELIB_GAME_H
