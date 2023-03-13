/**
 * @file RedundancyFly.h
 * @author Courtney Thang
 * @author Parker Morgan
 *
 * Initializes the Redundancy Fly in the game
 */

#ifndef PROJECT1_GAMELIB_REDUNDANCYFLY_H
#define PROJECT1_GAMELIB_REDUNDANCYFLY_H

#include "Item.h"

/**
 * Initializes the Redundancy Fly in the game
 */
class RedundancyFly : public Item
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
	/// The bitmap we can display for this fly
	std::unique_ptr<wxBitmap> mFlyBitmap;

public:
	/// Default constructor (disabled)
	RedundancyFly() = delete;

	/// Copy constructor (disabled)
	RedundancyFly(const RedundancyFly &) = delete;

	/// Assignment operator
	void operator=(const RedundancyFly &) = delete;

	RedundancyFly(Game *game);

	void Draw(wxDC* dc) override;

};

#endif //PROJECT1_GAMELIB_REDUNDANCYFLY_H
