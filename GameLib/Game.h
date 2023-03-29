/**
 * @file Game.h
 * @author rmpal
 * @author Courtney Thang
 * @author Kaijia Zhan
 * @author Parker Morgan
 * @author Joanna Rodriguez
 *
 * Our game
 */


#ifndef PROJECT1_GAMELIB_GAME_H
#define PROJECT1_GAMELIB_GAME_H

#include "Level.h"
#include "ScoreBoard.h"
#include "Leaderboard.h"

#include <memory>
#include <string>
#include <algorithm>
#include <random>
#include <unordered_map>

class RedundancyFly;
class BugCollection;


class Item;

class ScoreBoard;

/**
 * Initialize our game
 */
class Game
{
private:

	/// All of the items in our Game
	std::vector<std::shared_ptr<Item>> mItems;

	/// Unordered map for bug images
	std::unordered_map<std::wstring, std::shared_ptr<wxImage>> mImage;

	/// Resources directory
	std::wstring mResourcesDirectory;

	/// Game area in virtual pixels
	const static int Width = 1250;

	/// Game area height in virtual pixels
	const static int Height = 1000;

	/// Scale to shrink to when in shrink mode
	const double ShrinkScale = 0.75;

	/// boolean that sets window size
	bool mShrinked = false;

	/// The x offset for virtual pixels
	double mXOffset = 0;

	/// The y offset for virtual pixels
	double mYOffset = 0;

	/// Scaling
	double mScale = 0;

	/// The level we are on
	int mWhatLevel = 0;

	/// XML for level 0
	Level mLevel0;

	/// XML for level 1
	Level mLevel1;

	/// XML for level 2
	Level mLevel2;

	/// XML for level 3
	Level mLevel3;

	/// Random number generator
	std::mt19937 mRandom;

	/// Label for score font size to use
	const int LabelSize = 40;

	/// The font color to use
	const wxColour FontColor = wxColour(0, 200, 200);

	/// Left score X location. The right score is
	/// the width minus this value.
	const int LeftScoreX = 150;

	/// Score Y location
	const int ScoreY = 20;

	/// Score label Y location
	const int ScoreLabelY = 100;

	/// The elapsed time
	double mElapsed = 0;

	/// the ScoreBoard
	ScoreBoard mScoreBoard;

	/// the leaderboard
	Leaderboard mLeaderboard;

	/// The types of state
	enum class State {Start, Playing, End};

	/// The type of state
	State mState =State::Start;

	/// The laptop
	std::shared_ptr<Laptop> mLaptop;

	/// Vector of items to be deleted
	std::vector<Item*> mDeleteItems;

	/// The elapsed time to end the level and move onto next
	double mLevelEnd = 0;

public:

	/**
	 * Constructor
	 */
	Game();

	void OnDraw(std::shared_ptr<wxGraphicsContext> graphics, int width, int height);

	void Update(double elapsed, long totalTime);

	std::shared_ptr<Item> HitTest(int x, int y);

	void LoadLevel(int level);

	void Clear();

	void Save(const wxString &filename);

	void Add(std::shared_ptr<Item> item);

	/**
	 * Setting what level and getting what level items
	 * @param levelItems
	 */
	void SetLevel(std::vector<std::shared_ptr<Item>> levelItems) {mItems = levelItems;}

	/**
	 * Get the width of the game
	 * @return Width the width of the game
	 */
	double GetWidth() const { return Width; }

	/**
	 * Get the height of the game
	 * @return
	 */
	double GetHeight() const { return Height; }

	/**
	* Get the random number generator
	* @return Pointer to the random number generator
	*/
	std::mt19937 &GetRandom() { return mRandom; }

	/**
	 * Getter to get mShrinked
	 * @return mShrinked the boolean for shrinking the game
	 */
	bool GetShrink() const {return mShrinked;}

	/**
	 * Setter to set mShrinked
	 * @param shrink the boolean that sets mShrinked
	 */
	void SetShrink(bool shrink) {mShrinked = shrink;}

	void OnLeftDown(int x, int y);

	void SetImagesDirectory(const std::wstring &dir);

	std::shared_ptr<wxImage> SetImage(std::wstring imageName);

	void IncreaseOops(int add);

	void IncreaseFix(int add);

	void IncreaseMissed(int add);

	void RedundancyFlySplit(RedundancyFly* fly);

	void SetLaptop(std::shared_ptr<Laptop> laptop);

	void ToDelete(Item* item);

	void DeleteItem();

	double GetBugsLeft();

	void MoveItemFirst(std::shared_ptr<Item> item);

	void OnDoubleClick(wxWindow *view, int x, int y);
};

#endif //PROJECT1_GAMELIB_GAME_H
