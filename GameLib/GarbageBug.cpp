/**
 * @file GarbageBug.cpp
 * @author Kaijia Joanna Zhan
 * @author Flora Pieters
 *
 * Source file for type GarbageBug
 */

#include "pch.h"
#include <string>
#include "GarbageBug.h"
#include "BugCollection.h"
using namespace std;

/// The bug sprite image
const wstring GarbageBugSpriteImageName = L"blue-maize-bug.png";

/// The splat image
const wstring GarbageBugSplatImageName = L"blue-maize-splat.png";

/**
 * Constructor
 * @param game Game this bug is a member of
 */
GarbageBug::GarbageBug(Game *game) : BugCollection(game)
{
    mGarbageBugImage = make_unique<wxImage>(GarbageBugSpriteImageName, wxBITMAP_TYPE_ANY);
    mGarbageBugBitmap = make_unique<wxBitmap>(*mGarbageBugImage);
}

///**
// * Draw this bug
// * @param dc Device context to draw on
// */
//void GarbageBug::Draw(wxDC *dc)
//{
//    double wid = mGarbageBugBitmap->GetWidth();
//    double hit = mGarbageBugBitmap->GetHeight();
//
//    dc->DrawBitmap(*mGarbageBugBitmap,
//                   int(GetX() - wid / 2),
//                   int(GetY() - hit / 2));
//}

/**
 * Test to see if we hit this object with a mouse.
 * @param x X position to test
 * @param y Y position to test
 * @return true if hit.
 */
bool GarbageBug::HitTest(int x, int y)
{
	double wid = mGarbageBugImage->GetWidth();
	double hit = mGarbageBugImage->GetHeight();

	// Make x and y relative to the top-left corner of the bitmap image
	// Subtracting the center makes x, y relative to the image center
	// Adding half the size makes x, y relative to theimage top corner
	double testX = x - GetX() + wid / 2;
	double testY = y - GetY() + hit / 2;

	// Test to see if x, y are in the image
	if (testX < 0 || testY < 0 || testX >= wid || testY >= hit)
	{
		// We are outside the image
		return false;
	}

	// Test to see if x, y are in the drawn part of the image
	// If the location is transparent, we are not in the drawn
	// part of the image
	return !mGarbageBugImage->IsTransparent((int)testX, (int)testY);
}
