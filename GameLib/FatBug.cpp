/**
 * @file FatBug.cpp
 * @author Courtney Thang
 * @author Kaijia Joanna Zhan
 * @author Parker Morgan
 */

#include "pch.h"
#include "FatBug.h"
#include "BugCollection.h"

#include <string>

using namespace std;

/// The bug sprite image
const wstring GarbageBugSpriteImageName = L"images/blue-maize-bug.png";

/// The splat image
const wstring GarbageBugSplatImageName = L"images/blue-maize-splat.png";

/// The bug sprite image
const std::wstring NullBugSpriteImageName = L"images/scarlet-gray-bug.png";

/// The splat image
const std::wstring NullBugSplatImageName = L"images/scarlet-gray-splat.png";

/// The code to be displayed in the code window
//const wstring mCode = L"test!!";

/// The FatBug size modifier (25% larger than counterparts)
const double FatBugSize = 1.25;

/**
 * Constructor
 * @param game Game this bug is a member of
 */
FatBug::FatBug(Game *game) : BugCollection(game, GarbageBugSpriteImageName)
{
	mFatGarbageImage = make_unique<wxImage>(GarbageBugSpriteImageName, wxBITMAP_TYPE_ANY);
	mFatGarbageSplat = make_unique<wxImage>(GarbageBugSplatImageName, wxBITMAP_TYPE_ANY);

//	mFatNullImage = make_unique<wxImage>(NullBugSpriteImageName, wxBITMAP_TYPE_ANY);
//	mFatNullBitImage = make_unique<wxBitmap>(*mFatNullImage);
}

/**
 * Draw this bug
 * @param dc Device context to draw on
 */
void FatBug::Draw(std::shared_ptr<wxGraphicsContext> graphics)
{
	if(mFatGarbageBitImage.IsNull())
	{
		mFatGarbageBitImage = graphics->CreateBitmapFromImage(*mFatGarbageImage);
	}
	double wid = mFatGarbageImage->GetWidth();
	double hit = mFatGarbageImage->GetHeight();
	graphics->DrawBitmap(mFatGarbageBitImage,
						 int(GetX() - wid / 2),
						 int(GetY() - hit / 2),wid,hit);
}

/**
 * Test to see if we hit this object with a mouse.
 * @param x X position to test
 * @param y Y position to test
 * @return true if hit.
 */
bool FatBug::HitTest(int x, int y)
{
	double dx = x - GetX();
	double dy = y - GetY();

	return sqrt(dx * dx + dy * dy) < GetHitRange();
}

wxXmlNode* FatBug::XmlSave(wxXmlNode* node)
{
	auto itemNode = Item::XmlSave(node);

	itemNode->AddAttribute(L"type", L"fat");

	return itemNode;
}

/// Function to open IDE window that displays code
void FatBug::OpenWindow(int x) // temp parameter
{
	//copied from fat bug page not sure how to implement
	//CodeDlg dlg(window, mCode);
	//dlg.ShowModal();
}

///Function to call OpenWindow if Fat Bug is double clicked
//void FatBug::DoubleClick(wxMouseEvent &event)
//{
//	// how to implement mAquarium type variable from step 4
//	mSelectedBug = mAquarium.HitTest(event.GetX(), event.GetY());
//	// If an item is being moved, we only continue to
//	// move it while the left button is down.
//	if(event.LeftIsDown())
//	{
//		mSelectedBug->SetLocation(event.GetX(), event.GetY());
//	}
//	else
//	{
//		// When the left button is released, we release the
//		// item.
//		mSelectedBug = nullptr;
//	}
//}