/**
 * @file GarbageBug.cpp
 * @author Kaijia Joanna Zhan
 * @author Flora Pieters
 * @author Courtney Thang
 *
 * Source file for type GarbageBug
 */

#include "pch.h"
#include "GarbageBug.h"
#include "Game.h"
#include <string>
using namespace std;

/// The bug sprite image
const wstring GarbageBugSpriteImageName = L"images/blue-maize-bug.png";

/// The splat image
const wstring GarbageBugSplatImageName = L"images/blue-maize-splat.png";

/**
 * Constructor
 * @param game Game this bug is a member of
 */
GarbageBug::GarbageBug(Game *game) : BugCollection(game, GarbageBugSpriteImageName)
{
    mGarbageBugImage = make_unique<wxImage>(GarbageBugSpriteImageName, wxBITMAP_TYPE_ANY);
	mGarbageSplat = make_unique<wxImage>(GarbageBugSplatImageName, wxBITMAP_TYPE_ANY);
}

/**
 * Draw this bug
 * @param dc Device context to draw on
 */
void GarbageBug::Draw(std::shared_ptr<wxGraphicsContext> graphics)
{

	double wid = mGarbageBugImage->GetWidth();
	double hit = mGarbageBugImage->GetHeight();

	double spriteHit = hit/5;

	if(mGarbageBugBitmap.IsNull())
	{
		mGarbageBugBitmap = graphics->CreateBitmap(*mGarbageBugImage);

	}
	double angle = atan2(500-GetY(), 625-GetX());

	graphics->PushState();
	graphics->Translate(GetX(),GetY());
	graphics->Rotate(angle);
	graphics->Clip(-wid/2,-spriteHit/2,wid,100);
	graphics->DrawBitmap(mGarbageBugBitmap, -wid/2, -mSprite - spriteHit/2, wid, hit);
	graphics->PopState();
}

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

wxXmlNode* GarbageBug::XmlSave(wxXmlNode* node)
{
	auto itemNode = Item::XmlSave(node);

	itemNode->AddAttribute(L"type", L"garbage");

	return itemNode;
}

void GarbageBug::Update(double elapsed, long totalTime)
{
	double startTime = GetStartTime();

	if (totalTime < startTime)
	{
		mSprite = 500;
	}
	else
	{
		BugCollection::Update(elapsed, totalTime);

		mSprite += 100;
		if (mSprite >= 500)
		{
			mSprite = 0;
		}
	}

}
