/**
 * @file BugCollection.h
 * @author Rossi Palomba
 *
 */

#ifndef PROJECT1_GAMELIB_BUGCOLLECTION_H
#define PROJECT1_GAMELIB_BUGCOLLECTION_H

#include "Game.h"
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

	/// Bug Speed in X direction (Pixels per second)
	double mSpeedX = 50;

	/// Bug Speed in Y direction (Pixels per second)
	double mSpeedY = 50;

	/// Elapsed Time that the bug should start to move
	double mStartTime = 0;

	/// If true the item is mirrored
	bool mMirror = false;

	double BugHitRange = 50;

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

	void Update(double elapsed, long totalTime) override;

	void XmlLoad(wxXmlNode *node) override;

	/**
	 * Set the item speed
	 * @param x SpeedX*x in pixels
	 * @param y SpeedY*y in pixels
	 */
	 void SetSpeed(double speed) override { mSpeedX = speed, mSpeedY = speed; }

	double GetHitRange() { return BugHitRange; }

	void SetStartTime(double startTime) override { mStartTime = startTime; }

	double GetStartTime() { return mStartTime; }

//	double GetSpeeds() { return mSpeedX, mSpeedY; }


};

#endif //PROJECT1_GAMELIB_BUGCOLLECTION_H
