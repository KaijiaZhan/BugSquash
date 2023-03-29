/**
 * @file FatBug.cpp
 * @author Courtney Thang
 * @author Kaijia Joanna Zhan
 * @author Parker Morgan
 * @author Joanna Rodriguez
 */

#include "pch.h"
#include "FatBug.h"
#include "BugCollection.h"
#include "Code.h"
#include "CodeWindow.h"
#include <wx/event.h>
#include <string>

using namespace std;

/// The bug sprite image
const wstring GarbageBugSpriteImageName = L"images/blue-maize-bug.png";

/// The splat image
const wstring GarbageBugSplatImageName = L"images/blue-maize-splat.png";

/// Number of sprite images
const int GarbageBugNumSpriteImages = 5;

/// The bug sprite image
const std::wstring NullBugSpriteImageName = L"images/scarlet-gray-bug.png";

/// The splat image
const std::wstring NullBugSplatImageName = L"images/scarlet-gray-splat.png";

/// Number of sprite images
const int NullBugNumSpriteImages = 6;

/// The FatBug size modifier (25% larger than counterparts)
const double FatBugSize = 1.25;

/**
 * Constructor
 * @param game Game this bug is a member of
 * @param bugType the type of bug
 * @param node the node from the xml
 */
FatBug::FatBug(Game *game, std::wstring bugType, wxXmlNode *node) : BugCollection(game, GarbageBugSpriteImageName)
{
	SetScale(FatBugSize);
	if (bugType =="null")
	{
		BugCollection::BugSetImage(NullBugSpriteImageName, NullBugNumSpriteImages, NullBugSplatImageName);
	}
	else if (bugType == "garbage")
	{
		BugCollection::BugSetImage(GarbageBugSpriteImageName, GarbageBugNumSpriteImages, GarbageBugSplatImageName);
	}

	auto child = node->GetChildren();
	for( ; child; child=child->GetNext())
	{
		auto name = child->GetName();
		if (name == "code") {
			mCodeFatBug = make_shared<Code>(child);
		}
	}
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

/**
 * Handles when fatbug is double clicked
 * @param view the game view
 * @param x the x location
 * @param y the y location
 */
void FatBug::DoubleClick(wxWindow* view, int x, int y)
{
	if (GetSplat()) {
		return;
	}

	CodeWindow dialog(view, mCodeFatBug);
	dialog.ShowModal();

	bool passes = mCodeFatBug->CompareCodes();

	if (passes)
	{
		SetSplat(true);
		FatBug::SetSpeed(0);
	}

}

