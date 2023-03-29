/**
 * @file RedundancyFly.h
 * @author Courtney Thang
 * @author Parker Morgan
 * @author Kaijia Zhan
 * @author Joanna Rodriguez
 *
 * Initializes the Redundancy Fly in the game
 */

#ifndef PROJECT1_GAMELIB_REDUNDANCYFLY_H
#define PROJECT1_GAMELIB_REDUNDANCYFLY_H

#include "Game.h"
#include "BugCollection.h"
#include "GameView.h"

class RedundancyFly : public BugCollection
{
private:
	/// The underlying fly image
	std::unique_ptr<wxImage> mFlyBaseImage;

	/// The underlying fly left wing image
	std::unique_ptr<wxImage> mFlyLeftWingImage;

	/// The underlying fly right wing image
	std::unique_ptr<wxImage> mFlyRightWingImage;

	/// The underlying fly top image
	std::unique_ptr<wxImage> mFlyTopImage;

	/// The underlying fly splat image
	std::unique_ptr<wxImage> mFlySplat;

	/// The bitmap we can display for this flybase
	wxGraphicsBitmap mFlyBaseBitmap;

	/// The bitmap we can display for this flyleftwing
	wxGraphicsBitmap mFlyLeftWingBitmap;

	/// The bitmap we can display for this flyrightwing
	wxGraphicsBitmap mFlyRightWingBitmap;

	/// The bitmap we can display for this flytop
	wxGraphicsBitmap mFlyTopBitmap;

	/// The bitmap we can display for a splat fly
	wxGraphicsBitmap mFlySplatBitmap;

	/// The game the bug is contained in
	Game* mGame;

	/// Whether it is the initial fly to spawn more flies
	bool mInitFly = true;

	/// The timer that allows for animation
	wxTimer mTimer;

	/// Duration of elapsed time
	double mDuration = 0;


public:
	/// Default constructor (disabled)
	RedundancyFly() = delete;

	/// Copy constructor (disabled)
	RedundancyFly(const RedundancyFly &) = delete;

	/// Assignment operator
	void operator=(const RedundancyFly &) = delete;

	/// Constructor
	RedundancyFly(Game *game);

	/// Draw function
	void Draw(std::shared_ptr<wxGraphicsContext> graphics) override;

	/// Saves Xml
	wxXmlNode* XmlSave(wxXmlNode* node) override;

	/// HitTest for Redundancy
	bool HitTest(int x, int y) override;

	/// SingleClick function for Redundancy 
	void SingleClick(int x, int y) override;

	/// Sets the initial redundancy fly
	void setInit(bool init);

	/// Updates elapsed time for redundancy fly
	void Update(double elapsed, long totalTime) override;


};

#endif //PROJECT1_GAMELIB_REDUNDANCYFLY_H
