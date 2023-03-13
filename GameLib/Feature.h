/**
 * @file Feature.h
 * @author Courtney Thang
 * @author Parker Morgan
 *
 */

#ifndef PROJECT1_GAMELIB_FEATURE_H
#define PROJECT1_GAMELIB_FEATURE_H

#include "Game.h"
#include "Item.h"
#include "ScoreBoard.h"
#include "GameView.h"

/**
 * Initializes the feature item
 */
class Feature
{
private:
	/// The underlying Feature image
	std::unique_ptr<wxImage> mFeatureImage;

	/// The bitmap we can display for feature
	std::unique_ptr<wxBitmap> mFeatureBitmap;
public:
	/// Default constructor (disabled)
	Feature() = delete;

	/// Copy constructor (disabled)
	Feature(const Feature &) = delete;

	/// Assignment operator
	void operator=(const Feature &) = delete;

	Feature(Game* game);

	//void Draw(wxDC* dc) override;
};

#endif //PROJECT1_GAMELIB_FEATURE_H
