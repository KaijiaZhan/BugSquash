/**
 * @file Feature.h
 * @author Courtney Thang
 * @author Parker Morgan
 * @author Flora Pieters
 */

#ifndef PROJECT1_GAMELIB_FEATURE_H
#define PROJECT1_GAMELIB_FEATURE_H

#include "BugCollection.h"

/**
 * Initializes the feature item
 */
class Feature : public BugCollection
{
private:
	/// The underlying Feature image
	std::unique_ptr<wxImage> mFeatureImage;

    /// The underlying fly splat image
    std::unique_ptr<wxImage> mFeatureSplat;

    /// The bitmap we can display for feature
    wxGraphicsBitmap mFeatureBitmap;

	/// Keeps track of what sprite we are at
	int mSprite = 0;

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

	bool HitTest(int x, int y) override;

	wxXmlNode* XmlSave(wxXmlNode* node) override;

	void Update(double elapsed, long totaltime) override;
};

#endif //PROJECT1_GAMELIB_FEATURE_H
