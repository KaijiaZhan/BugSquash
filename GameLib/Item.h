/**
 * @file Item.h
 * @author Parker Morgan
 * @author Joanna Rodriguez
 * @author Courtney Thang
 * @author Kaijia Zhan
 *
 * Base class for any item in our game.
 */

#ifndef PROJECT1_GAMELIB_ITEM_H
#define PROJECT1_GAMELIB_ITEM_H

#include <wx/graphics.h>
#include "Game.h"

class GameView;

class Game;

/**
 * Base class for any item in our game
 */
class Item {
private:
	/// The game the item is contained in
	Game *mGame;

	/// Underlying Image
	std::unique_ptr<wxImage> mItemImage;

	/// The bitmap that can be displayed for the item
	wxGraphicsBitmap mItemBitmap;

	/// Item location in the game
	double  mX = 0;     ///< X location for the center of the item
	double  mY = 0;     ///< Y location for the center of the item

	/// Item speed
	double mSpeed = 0;

	/// Item hit range
	int mItemHitRange = 50;

	/// Bool to delete an item
	bool mToDel = false;

protected:
	Item(Game *game);

public:
	virtual ~Item();

	/// Default constructor (disabled)
	Item() = delete;

	/// Copy constructor (disabled)
	Item(const Item &) = delete;

	/// Assignment operator
	void operator=(const Item &) = delete;

	/**
	 * The X location of the item
	 * @return X location in pixels
	 */
	double GetX() const { return mX; }

	/**
	 * The Y location of the item
	 * @return Y location in pixels
	 */
	double GetY() const { return mY; }

	/**
	 * Set the item location
	 * @param x X location in pixels
	 * @param y Y location in pixels
	 */
	void SetLocation(double x, double y) { mX = x; mY = y; }

	/**
	 * Virtual setter that sets the speed of the items
	 * @param speed the speed of the bug
	 */
	virtual void SetSpeed(double speed) {}

	virtual void Draw(std::shared_ptr<wxGraphicsContext> graphics) = 0;

	/**
	 * Update this item
	 * @param elapsed the elapsed time
	 * @param totalTime the total time of the game
	 */
	virtual void Update(double elapsed, long totalTime) {}

	virtual bool HitTest(int x, int y);

	virtual void XmlLoad(wxXmlNode *node);

	virtual wxXmlNode *XmlSave(wxXmlNode *node);

	/**
	 * Getter for the items hit range
	 * @return mItemHitRange the hit range of the item
	 */
	double GetHitRange() { return mItemHitRange; }

	/**
	 * Setter to set the deletion bool
	 * @param del the bool to delete the item
	 */
	virtual void SetDel(bool del) {mToDel = del;}

	/**
	 * Getter to get the deletion bool
	 * @return mToDel the bool to delete item
	 */
	bool GetDel() {return mToDel;}

	/**
	 * Setter to set the starttime of the item
	 * @param startTime The startTime of the item
	 */
	virtual void SetStartTime(double startTime) {}

	/**
	 * Handle a double-click on an item
	 * @param x X location in the aquarium of the double-click
	 * @param y Y location in the aquarium of the double-click
	 */
	virtual void DoubleClick(wxWindow* view, int x, int y) {}

	/**
	 * Getter to get the game pointer
	 * @return mGame the game pointer
	 */
	Game * GetGame() { return mGame; }

	/**
	 * Single clicks the item
	 * @param x the x coordinate
	 * @param y the y coordinate
	 */
	virtual void SingleClick(int x, int y) {}

	/**
	 * Getter to get the item type
	 * @return the item type
	 */
	virtual std::string GetType() {return "Item";}

	/**
	 * Boolean to squash the bugs
	 * @return the boolean that indicates squashing the bug
	 */
	virtual bool GetSquashed() {return false;}
};

#endif //PROJECT1_GAMELIB_ITEM_H
