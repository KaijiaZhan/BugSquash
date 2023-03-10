/**
 * @file BugCollection.h
 * @author rmpal
 *
 *
 */

#ifndef PROJECT1_GAMELIB_BUGCOLLECTION_H
#define PROJECT1_GAMELIB_BUGCOLLECTION_H

#include "Item.h"

class Game;

/**
 * Base Class for a Bug
 */
class BugCollection : public Item
{
private:

	/// The game the bug is contained in
	Game* mGame;

	/// Underlying Bug Image
	std::unique_ptr<wxImage> mBugImage;

	/// The bitmap that can be displayed for the bug
	std::unique_ptr<wxImage> mBugBitmap;

	/// X location for Center of Bug
	double mX = 0;

	/// Y location for Center of Bug
	double mY = 0;

	/// Bug Speed in X direction
	/// Pixels per second
	double mSpeedX = 0;

	/// Bug Speed in Y direction
	/// Pixels per second
	double mSpeedY = 0;

	/// If true the item is mirrored
	bool mMirror = false;

protected:
	BugCollection(Game *game, const std::wstring &filename);

	BugCollection(Game *pGame);

public:

	/// Default constructor (disabled)
	BugCollection() = delete;

	/// Copy constructor (disabled)
	BugCollection(const BugCollection &) = delete;

	/// Assignment operator
	void operator=(const BugCollection &) = delete;

	/**
     * Draw this item
     * @param dc Device context to draw on
     */
    virtual void Draw(wxDC *dc) = 0;

	/**
     * The X location of the bug
     * @return X location in pixels
     */
    double GetX() const { return mX; }

    /**
     * The Y location of the bug
     * @return Y location in pixels
     */
    double GetY() const { return mY; }
};

#endif //PROJECT1_GAMELIB_BUGCOLLECTION_H
