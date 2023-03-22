/**
 * @file Feature.cpp
 * @author Courtney Thang
 * @author Parker Morgan
 */

#include "pch.h"
#include "Feature.h"
#include "Game.h"
#include <string>

using namespace std;

class Game;

/// Feature filename
const wstring FeatureImage = L"images/feature.png";

/// Feature filenames
const wstring FeatureSplat = L"images/feature-splat.png";

/**
 * Constructor
 * @param game Game this bug is a member of
 */
Feature::Feature(Game *game) : BugCollection(game,FeatureImage)
{
    mFeatureImage = make_unique<wxImage>(FeatureImage, wxBITMAP_TYPE_ANY);

    mFeatureSplat = make_unique<wxImage>(FeatureSplat, wxBITMAP_TYPE_ANY);

}

/**
 * Draw this feature
 * @param dc Device context to draw on
 */
void Feature::Draw(std::shared_ptr<wxGraphicsContext> graphics)
{

	double wid = mFeatureImage->GetWidth();
	double hit = mFeatureImage->GetHeight();

	double spriteHit = hit/7;

	if(mFeatureBitmap.IsNull())
	{
		mFeatureBitmap = graphics->CreateBitmap(*mFeatureImage);

	}
	double angle = atan2(500-GetY(), 625-GetX());

	graphics->PushState();
	graphics->Translate(GetX(),GetY());
	graphics->Rotate(angle);
	graphics->Clip(-wid/2,-spriteHit/2,wid,spriteHit);
	graphics->DrawBitmap(mFeatureBitmap, -wid/2, -mSprite - spriteHit/2, wid, hit);
	graphics->PopState();
}

/**
 * Test to see if we hit this object with a mouse.
 * @param x X position to test
 * @param y Y position to test
 * @return true if hit.
 */
bool Feature::HitTest(int x, int y)
{
    double dx = x - GetX();
    double dy = y - GetY();

    return sqrt(dx * dx + dy * dy) < GetHitRange();
}

wxXmlNode* Feature::XmlSave(wxXmlNode* node)
{
	auto itemNode = Item::XmlSave(node);

	itemNode->AddAttribute(L"type", L"feature");

	return itemNode;
}

void Feature::Update(double elapsed, long totalTime)
{
	double startTime = GetStartTime();

	if (totalTime < startTime)
	{
		mSprite = 700;
	}
	else
	{
		BugCollection::Update(elapsed, totalTime);

		mSprite += 100;
		if (mSprite >= 700)
		{
			mSprite = 0;
		}
	}

}
