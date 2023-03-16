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
    std::unique_ptr<wxBitmap> mNullBugBitmap;

public:
	/// Default constructor (disabled)
	NullBug() = delete;

	/// Copy constructor (disabled)
	NullBug(const NullBug &) = delete;

	/// Assignment operator
	void operator=(const NullBug &) = delete;

	NullBug(Game* game);

    void Draw(wxDC* dc) override;

};

#endif //PROJECT1_COPY_GAMELIB_NULLBUG_H
