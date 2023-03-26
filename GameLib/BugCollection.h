/**
 * @file BugCollection.h
 * @author Rossi Palomba
 * @author Courtney Thang
 * @author Kaijia Zhan
 */

#ifndef PROJECT1_GAMELIB_BUGCOLLECTION_H
#define PROJECT1_GAMELIB_BUGCOLLECTION_H

#include "Game.h"
#include "Item.h"
#include "BugCounter.h"
#include "Laptop.h"

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

	std::shared_ptr<Laptop> mLaptop;
	
	/// The underlying Bug image
	std::shared_ptr<wxImage> mBugImage;

	///Splat image
	std::shared_ptr<wxImage> mBugSplatImage;

	/// The bitmap we can display for this bug
	wxGraphicsBitmap mBugBitmap;

	/// Splay bitmap
    wxGraphicsBitmap mBugSplatBitmap;

	/// Keeps track of what sprite we are at
	int mSprite = 0;

	/// Sprite count
	int mSpriteCount = 0;

	double mScaling = 0;

	bool mSplat = false;

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

	void SetSplat(bool splat) { mSplat = splat; }

	double GetHitRange() { return BugHitRange; }

	void SetStartTime(double startTime) override { mStartTime = startTime; }

	double GetStartTime() { return mStartTime; }

	bool GetSplat() { return mSplat; }

    int GetSpriteCount() { return mSpriteCount; }

    int GetSprite() { return mSprite; }

	double GetScaling() { return mScaling; }

	void SetLaptop(std::shared_ptr<Laptop> laptop);

//	double GetSpeeds() { return mSpeedX, mSpeedY; }

	/// bug image, number of sprites, splat image
	void BugSetImage(std::wstring BugImage, int spriteNum, std::wstring splatImage);

	void Draw(std::shared_ptr<wxGraphicsContext> graphics) override;

	std::string GetType() override {return "Bug";}

	std::shared_ptr<Laptop> GetLaptop() { return mLaptop; }


	virtual void SetScale(double scale) { mScaling = scale;};

	void Accept(BugCounter* visitor) override {visitor->VisitBugCollection(this);}

};

#endif //PROJECT1_GAMELIB_BUGCOLLECTION_H
