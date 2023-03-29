/**
 * @file Level.h
 * @author Courtney Thang
 * @author Kaijia Zhan
 *
 * Initializes the level base class where all levels are derived from.
 *
 */

#ifndef PROJECT1_GAMELIB_LEVEL_H
#define PROJECT1_GAMELIB_LEVEL_H

#include <random>
class Laptop;

class Game;
class Item;

class Level
{
private:

	/// Pointer to the game
	Game* mGame;

	/// All of the items in level
	std::vector<std::shared_ptr<Item>> mLevelItems;

	/// Random number generator
	std::mt19937 mRandom;

	/// Time loaded in from the levels
	double mTimeLoaded;

	/// The name of the level
	std::string mLevelName;

	/// The current time in the game
	double mCurrentTime;

	/// The name that is displayed on top of the laptop
	std::wstring mProgramName;

public:

	/// Constructor
	Level();

	void Load(const wxString &filename, Game * game);
	void XmlItem(wxXmlNode *node, Game * game,std::shared_ptr<Laptop> parent);

	/**
	 * Getter for mLevelItems
	 * @return mLevelItems
	 */
	std::vector<std::shared_ptr<Item>> GetLevel() { return mLevelItems; }

	/**
	* Get the random number generator
	* @return Pointer to the random number generator
	*/
	std::mt19937 &GetRandom() { return mRandom; }

	void Clear();

	void Update(double elapsed);

	void DrawTitle(std::shared_ptr<wxGraphicsContext> graphics, int wid, int height);


};

#endif //PROJECT1_GAMELIB_LEVEL_H
