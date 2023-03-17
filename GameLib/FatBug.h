/**
 * @file FatBug.h
 * @author Courtney Thang
 * @author Kaijia Joanna Zhan
 *
 */

#ifndef PROJECT1_GAMELIB_FATBUG_H
#define PROJECT1_GAMELIB_FATBUG_H

#include "BugCollection.h"

/**
 * Class for type Fatbug
 */
class FatBug : public BugCollection
{
private:
	/// The underlying fatnull image
	std::unique_ptr<wxImage> mFatNullImage;

	/// The bitmap we can display for this bug
	std::unique_ptr<wxBitmap> mFatNullBitImage;

	/// The underlying fatgarbage image
	std::unique_ptr<wxImage> mFatGarbageImage;

	/// The bitmap we can display for this bug
	std::unique_ptr<wxBitmap> mFatGarbageBitImage;

public:
	/// Default constructor (disabled)
	FatBug() = delete;

	/// Copy constructor (disabled)
	FatBug(const FatBug &) = delete;

	/// Assignment operator
	void operator=(const FatBug &) = delete;

	/// Constructor 
	FatBug(Game* game);

	/// Draws FatBug
	void Draw(wxDC* dc) override;
};

#endif //PROJECT1_GAMELIB_FATBUG_H
