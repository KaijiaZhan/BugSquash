/**
 * @file NullBug.h
 * @author Kaijia Joanna Zhan
 * @author Flora Pieters
 *
 */

#ifndef PROJECT1_COPY_GAMELIB_NULLBUG_H
#define PROJECT1_COPY_GAMELIB_NULLBUG_H

#include "BugCollection.h"

/**
 * Class for bug type NullBug
 */
class NullBug : public BugCollection
{
private:
	/// The underlying NullBug image
    std::unique_ptr<wxImage> mNullBugImage;

    /// The bitmap we can display for this bug
	wxGraphicsBitmap mNullBugBitmap;

	/// Keeps track of what sprite we are at
	int mSprite = 0;

public:
	/// Default constructor (disabled)
	NullBug() = delete;

	/// Copy constructor (disabled)
	NullBug(const NullBug &) = delete;

	/// Assignment operator
	void operator=(const NullBug &) = delete;

	NullBug(Game *game);

	void Draw(std::shared_ptr<wxGraphicsContext> graphics) override;

	bool HitTest(int x, int y) override;

	wxXmlNode* XmlSave(wxXmlNode* node) override;

	void Update(double elapsed, long totaltime) override;

};

#endif //PROJECT1_COPY_GAMELIB_NULLBUG_H
