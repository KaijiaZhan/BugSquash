/**
 * @file FatBug.h
 * @author Courtney Thang
 * @author Kaijia Joanna Zhan
 * @author Parker Morgan
 */

#ifndef PROJECT1_GAMELIB_FATBUG_H
#define PROJECT1_GAMELIB_FATBUG_H

#include "GameView.h"
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
	wxGraphicsBitmap mFatGarbageBitImage;

	/// The underlying garbage splat image
	std::unique_ptr<wxImage> mFatGarbageSplat;

	/// The bitmap for the splat image
	wxGraphicsBitmap mFatGarbageSplatBitmap;

public:
	/// Default constructor (disabled)
	FatBug() = delete;

	/// Copy constructor (disabled)
	FatBug(const FatBug &) = delete;

	/// Assignment operator
	void operator=(const FatBug &) = delete;

	/// Constructor 
	FatBug(Game* game);

//	/// Draws FatBug
	void Draw(std::shared_ptr<wxGraphicsContext> graphics) override;

	wxXmlNode* XmlSave(wxXmlNode* node) override;

	bool HitTest(int x, int y) override;

	void OpenWindow(int x); //temp parameter

	void DoubleClick(wxMouseEvent &event);

	void SingleClick(int x, int y) override;

	std::string GetType() override {return "FatBug";}

};

#endif //PROJECT1_GAMELIB_FATBUG_H
