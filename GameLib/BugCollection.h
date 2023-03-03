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
	BugCollection(Game *game, const std::wstring &filename)

public:

	/// Default constructor (disabled)
	BugCollection() = delete;

	/// Copy constructor (disabled)
	BugCollection(const BugCollection &) = delete;

	/// Assignment operator
	void operator=(const BugCollection &) = delete;
};

#endif //PROJECT1_GAMELIB_BUGCOLLECTION_H
