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
const std::wstring NullBugSpriteImageName = L"scarlet-gray-bug.png";

/// The splat image
const std::wstring NullBugSplatImageName = L"scarlet-gray-splat.png";

/// Number of sprite images
const int NullBugNumSpriteImages = 6;

/**
 * Constructor
 * @param game Game this bug is a member of
 */
NullBug::NullBug(Game *game) : BugCollection(game)
{
    mNullBugImage = make_unique<wxImage>(NullBugSpriteImageName, wxBITMAP_TYPE_ANY);
    mNullBugBitmap = make_unique<wxBitmap>(*mNullBugImage);
}

/**
 * Draw this bug
 * @param dc Device context to draw on
 */
void NullBug::Draw(wxDC *dc)
{
    double wid = mNullBugBitmap->GetWidth();
    double hit = mNullBugBitmap->GetHeight();

    dc->DrawBitmap(*mNullBugBitmap,
                   int(GetX() - wid / 2),
                   int(GetY() - hit / 2));
}
