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
	double dx = x - GetX();
	double dy = y - GetY();

	return sqrt(dx * dx + dy * dy) < GetHitRange();
}
