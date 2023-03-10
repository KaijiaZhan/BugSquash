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
//#include "BugCollection.h"
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
    mFishImage = make_unique<wxImage>(GarbageBugSpriteImageName, wxBITMAP_TYPE_ANY);
    mFishBitmap = make_unique<wxBitmap>(*mFishImage);
}
