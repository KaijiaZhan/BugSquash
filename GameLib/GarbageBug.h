/**
 * @file GarbageBug.h
 * @author Kaijia Joanna Zhan
 * @author Flora Pieters
 *
 * Header for bug type Garbage Bug
 */

#ifndef PROJECT1_COPY_GAMELIB_GARBAGEBUG_H
#define PROJECT1_COPY_GAMELIB_GARBAGEBUG_H

#include "GameView.h"
#include "BugCollection.h"

/**
 * Class for type GarbageBug
 */

class GarbageBug : public BugCollection
{
private:
	/// The underlying GarbageBug image
    std::unique_ptr<wxImage> mGarbageBugImage;

	/// The underlying garbage splat image
	std::unique_ptr<wxImage> mGarbageSplat;

    /// The bitmap we can display for this bug
	wxGraphicsBitmap mGarbageBugBitmap;

	/// The bitmap for the splat image
	wxGraphicsBitmap mGarbageSplatBitmap;

public:
	/// Default constructor (disabled)
	GarbageBug() = delete;

	/// Copy constructor (disabled)
	GarbageBug(const GarbageBug &) = delete;

	/// Assignment operator
	void operator=(const GarbageBug &) = delete;

	GarbageBug(Game* game);

	void Draw(std::shared_ptr<wxGraphicsContext> graphics) override;

	bool HitTest(int x, int y) override;

	wxXmlNode* XmlSave(wxXmlNode* node) override;
};

#endif //PROJECT1_COPY_GAMELIB_GARBAGEBUG_H
