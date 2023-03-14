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

	/// Bug Speed in X direction
	/// Pixels per second
	double mSpeedX = 10;

	/// Bug Speed in Y direction
	/// Pixels per second
	double mSpeedY = 0;

	/// Elapsed Time that the bug should start to move
	double mStartTime = 0;

	/// If true the item is mirrored
	bool mMirror = false;

protected:

	/**
 	 * Constructor
     * @param game The game this item is a member of
     * @param filename The name of the file to display for this item
     * Move these comments to cpp once the BugCollection Constructor is in the cpp file
     */
	BugCollection(Game *game, const std::wstring &filename);

	/**
     * Constructor
     * @param pGame The aquarium this item is a member of
     * Move these comments to cpp once the BugCollection Constructor is in the cpp file
     */
	BugCollection(Game *pGame);

public:

	/// Default constructor (disabled)
	BugCollection() = delete;

	/// Copy constructor (disabled)
	BugCollection(const BugCollection &) = delete;

	/// Assignment operator
	void operator=(const BugCollection &) = delete;

//	/**
//     * Draw this item
//     * @param dc Device context to draw on
//     */
//    virtual void Draw(wxDC *dc) = 0;

	void Update(double elapsed);

	virtual void XmlLoad(wxXmlNode *node); //override;

};

#endif //PROJECT1_GAMELIB_BUGCOLLECTION_H
