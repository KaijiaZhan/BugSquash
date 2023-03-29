/**
 * @file BugCollection.h
 * @author Rossi Palomba
 * @author Courtney Thang
 * @author Kaijia Zhan
 * @author Joanna Rodriguez
 *
 * Base class for bugs
 */

#ifndef PROJECT1_GAMELIB_BUGCOLLECTION_H
#define PROJECT1_GAMELIB_BUGCOLLECTION_H

#include "Item.h"
#include "Laptop.h"
#include "CodeWindow.h"

class Game;

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

	/// The bug hit range
	double BugHitRange = 50;

	/// The laptop
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

	/// The scaling of the bug
	double mScaling = 0;

	/// Boolean to indicate if the bug is squashed
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

	virtual void Update(double elapsed, long totalTime) override;

	void XmlLoad(wxXmlNode *node) override;

	/**
	 * Set the item speed
	 * @param x SpeedX*x in pixels
	 * @param y SpeedY*y in pixels
	 */
	void SetSpeed(double speed) override { mSpeedX = speed, mSpeedY = speed; }

	/**
	 * Set the splat bool to indicate splat
	 * @param splat boolean to indicate if the bug is squashed
	 */
	void SetSplat(bool splat) { mSplat = splat; }

	/**
	 * Gt the hit range of the bug
	 * @return The bugs hit range
	 */
	double GetHitRange() { return BugHitRange; }

	/**
	 * Set the start time for the bug
	 * @param startTime The start time of the bug
	 */
	void SetStartTime(double startTime) override { mStartTime = startTime; }

	/**
	 * Get the start time of the bug
	 * @return mStarTime the start time of the bug
	 */
	double GetStartTime() { return mStartTime; }

	/**
	 * Get the boolean that indicates bug squashed
	 * @return mSplat the bool that indicates if the bug is squashed
	 */
	bool GetSplat() { return mSplat; }

	/**
	 * Get the scaling for the bugs
	 * @return mScaling the scaling of the bugs
	 */
	double GetScaling() { return mScaling; }

	void SetLaptop(std::shared_ptr<Laptop> laptop);

	void BugSetImage(std::wstring BugImage, int spriteNum, std::wstring splatImage);

	void Draw(std::shared_ptr<wxGraphicsContext> graphics) override;

	/**
	 * Gets the type of item
	 * @return Bug the type of item
	 */
	std::string GetType() override {return "Bug";}

	std::shared_ptr<Laptop> GetLaptop() { return mLaptop; }

	/**
	 * Set the scaling of the bugs
	 * @param scale the scaling of the bugs
	 */
	virtual void SetScale(double scale) { mScaling = scale;};

	void DoubleClick(wxWindow* view, int x, int y) override;

	bool GetSquashed() override {return mSplat;}

};

#endif //PROJECT1_GAMELIB_BUGCOLLECTION_H
