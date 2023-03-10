/**
 * @file GarbageBug.h
 * @author Kaijia Joanna Zhan
 * @author Flora Pieters
 *
 * Header for bug type Garbage Bug
 */

#ifndef PROJECT1_COPY_GAMELIB_GARBAGEBUG_H
#define PROJECT1_COPY_GAMELIB_GARBAGEBUG_H

#include "BugCollection.h"

/**
 * Class for type GarbageBug
 */

class GarbageBug : public BugCollection
{
private:
	/// The underlying GarbageBug image
    std::unique_ptr<wxImage> mGarbageBugImage;

    /// The bitmap we can display for this bug
    std::unique_ptr<wxBitmap> mGarbageBugBitmap;

public:
	/// Default constructor (disabled)
	GarbageBug() = delete;

	/// Copy constructor (disabled)
	GarbageBug(const GarbageBug &) = delete;

	/// Assignment operator
	void operator=(const GarbageBug &) = delete;

	GarbageBug(Game* game);

	void Draw(wxDC* dc) override;

};

#endif //PROJECT1_COPY_GAMELIB_GARBAGEBUG_H
