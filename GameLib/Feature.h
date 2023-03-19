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
class Feature : public Item
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

	/// Constructor
	Feature(Game* game);

	/// Draws Feature
    void Draw(std::shared_ptr<wxGraphicsContext> graphics) override;

    wxXmlNode* XmlSave(wxXmlNode* node) override;
};

#endif //PROJECT1_GAMELIB_FEATURE_H
