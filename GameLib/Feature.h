/**
 * @file Feature.h
 * @author Courtney Thang
 * @author Parker Morgan
 * @author Flora Pieters
 */

#ifndef PROJECT1_GAMELIB_FEATURE_H
#define PROJECT1_GAMELIB_FEATURE_H

#include "Game.h"
#include "BugCollection.h"

/**
 * Initializes the feature item
 */
class Feature : public Item
{
private:
	/// The underlying Feature image
	std::unique_ptr<wxImage> mFeatureImage;

    /// The underlying fly splat image
    std::unique_ptr<wxImage> mFeatureSplat;

    /// The bitmap we can display for feature
    wxGraphicsBitmap mFeatureBitmap;

    /// The bitmap we can display for feature
    wxGraphicsBitmap mFeatureSplatBitmap;
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

	bool HitTest(int x, int y) override;
};

#endif //PROJECT1_GAMELIB_FEATURE_H
