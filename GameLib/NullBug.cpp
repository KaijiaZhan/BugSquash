/**
 * @file NullBug.cpp
 * @author Kaijia Joanna Zhan
 * @author Flora Pieters
 *
 * Source file for NullBug
 */

#include "pch.h"
#include <string>
#include "BugCollection.h"
#include "NullBug.h"
using namespace std;

/// The bug sprite image
const std::wstring NullBugSpriteImageName = L"images/scarlet-gray-bug.png";

/// The splat image
const std::wstring NullBugSplatImageName = L"images/scarlet-gray-splat.png";

/// Number of sprite images
const int NullBugNumSpriteImages = 6;

/**
 * Constructor
 * @param game Game this bug is a member of
 */
NullBug::NullBug(Game *game) : BugCollection(game,NullBugSpriteImageName)
{
    mNullBugImage = make_unique<wxImage>(NullBugSpriteImageName, wxBITMAP_TYPE_ANY);
}

/**
 * Draw this bug
 * @param dc Device context to draw on
 */
void NullBug::Draw(std::shared_ptr<wxGraphicsContext> graphics)
{

	if(mNullBugBitmap.IsNull())
	{
		mNullBugBitmap = graphics->CreateBitmapFromImage(*mNullBugImage);
	}

    double wid = mNullBugImage->GetWidth();
    double hit = mNullBugImage->GetHeight();

	graphics->DrawBitmap(mNullBugBitmap,
						 int(GetX() - wid / 2),
						 int(GetY() - hit / 2), wid, hit);
}

/**
 * Test to see if we hit this object with a mouse.
 * @param x X position to test
 * @param y Y position to test
 * @return true if hit.
 */
bool NullBug::HitTest(int x, int y)
{
	double dx = x - GetX();
	double dy = y - GetY();

	return sqrt(dx * dx + dy * dy) < GetHitRange();
}

wxXmlNode* NullBug::XmlSave(wxXmlNode* node)
{
	auto itemNode = Item::XmlSave(node);

	itemNode->AddAttribute(L"type", L"null");

	return itemNode;
}
