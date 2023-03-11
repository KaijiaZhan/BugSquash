/**
 * @file FatBug.cpp
 * @author Courtney Thang
 * @author Kaijia Joanna Zhan
 */

#include "pch.h"
#include "FatBug.h"

#include <string>

using namespace std;

/// The bug sprite image
const wstring GarbageBugSpriteImageName = L"blue-maize-bug.png";

/// The splat image
const wstring GarbageBugSplatImageName = L"blue-maize-splat.png";

/// The bug sprite image
const std::wstring NullBugSpriteImageName = L"scarlet-gray-bug.png";

/// The splat image
const std::wstring NullBugSplatImageName = L"scarlet-gray-splat.png";

/**
 * Constructor
 * @param game Game this bug is a member of
 */
FatBug::FatBug(Game *game) : BugCollection(game)
{
	mFatGarbageImage = make_unique<wxImage>(GarbageBugSpriteImageName, wxBITMAP_TYPE_ANY);
	mFatGarbageBitImage = make_unique<wxBitmap>(*mFatGarbageImage);

	mFatNullImage = make_unique<wxImage>(NullBugSpriteImageName, wxBITMAP_TYPE_ANY);
	mFatNullBitImage = make_unique<wxBitmap>(*mFatNullImage);
}

/**
 * Draw this bug
 * @param dc Device context to draw on
 */
void FatBug::Draw(wxDC *dc)
{
	double wid = (mFatGarbageBitImage->GetWidth()) * 1.25;
	double hit = mFatGarbageBitImage->GetHeight() * 1.25;

	double wid2 = mFatNullBitImage->GetWidth() * 1.25;
	double hit2 = mFatNullBitImage->GetHeight() * 1.25;

	dc->DrawBitmap(*mFatGarbageBitImage,
				   int(GetX() - wid / 2),
				   int(GetY() - hit / 2));

	dc->DrawBitmap(*mFatNullBitImage,
				   int(GetX() - wid2 / 2),
				   int(GetY() - hit2 / 2));
}




