/**
 * @file Level.h
 * @author Courtney Thang
 *
 * Initializes the level base class where all levels are derived from.
 *
 */

#ifndef PROJECT1_GAMELIB_LEVEL_H
#define PROJECT1_GAMELIB_LEVEL_H

class Game;
class Item;

/**
 * Initializes the level base class where all levels are derived from.
 */
class Level
{
private:

	Game* mGame;

	/// All of the items in level
	std::vector<std::shared_ptr<Item>> mLevelItems;

public:

	/// Constructor
	Level();

	void Load(const wxString &filename, Game * game);
	void XmlItem(wxXmlNode *node);

	/**
	 * Getter for mLevelItems
	 * @return mLevelItems
	 */
	std::vector<std::shared_ptr<Item>> GetLevel() { return mLevelItems; }

};

#endif //PROJECT1_GAMELIB_LEVEL_H
