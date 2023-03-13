/**
 * @file Item.h
 * @author Parker Morgan
 * @author Joanna Rodriguez
 * @author Courtney Thang
 *
 * Base class for any item in our game.
 */

#ifndef PROJECT1_GAMELIB_ITEM_H
#define PROJECT1_GAMELIB_ITEM_H

class Game;

/**
 * Base class for any item in our game.
 */
class Item {
private:
	/// The game the item is contained in
	Game *mGame;

	/// Underlying Image
	std::unique_ptr<wxImage> mItemImage;

	/// The bitmap that can be displayed for the item
	std::unique_ptr<wxBitmap> mItemBitmap;

	// Item location in the game
	double  mX = 0;     ///< X location for the center of the item
	double  mY = 0;     ///< Y location for the center of the item



protected:
	Item(Game *game, const std::wstring &filename);

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
	 * Draw this item
	 * @param dc Device context to draw on
	 */
	virtual void Draw(wxDC *dc);

};

#endif //PROJECT1_GAMELIB_ITEM_H
