/**
 * @file RedundancyFly.cpp
 * @author Courtney Thang
 * @author Joanna Rodriguez
 * @author Parker Morgan
 * @author Kaijia Zhan
 */

#include "pch.h"
#include "RedundancyFly.h"
#include "Game.h"
#include <string>
#include <stdlib.h>
#include <wx/event.h>
#include <cmath>


using namespace std;

/// Redundancy fly filename
const wstring FlyBaseImage = L"images/redundancy-fly-base.png";

/// Redundancy fly filename
const wstring FlyLeftWing = L"images/redundancy-fly-lwing.png";

/// Redundancy fly filename
const wstring FlyRightWing = L"images/redundancy-fly-rwing.png";

/// Redundancy fly filename
const wstring FlyTopImage = L"images/redundancy-fly-top.png";

/// Redundancy fly filename
const wstring FlySplat = L"images/redundancy-fly-splat.png";

/// Wing flapping period in seconds
const double WingPeriod = 0.2;

/// Starting rotation angle for wings in radians
const double WingRotateStart = 0.0;

/// End rotation angle for wings in radians
const double WingRotateEnd = 1.5;

/// How many sets of wings does this bug have?
const int NumberOfSetsOfWings = 4;

/// Number of virtual pixels between each of the wing sets
const int WingSetXOffset = 12;

/// X position relative to center of bug for the first (back) wing set
const int FirstWingSetX = -36;

/// Y position relative to center of bug for the right wings. The negative
/// of this is the Y position for the left wings.
const int WingSetY = 5;


/**
 * Constructor
 * @param game Game this fly is a member of
 */
RedundancyFly::RedundancyFly(Game *game) : BugCollection(game, FlyBaseImage)
{
	/// m var in game that holds map of all images
	/// a function in game that gets the image (65-73)
	/// a function in game that gets the images into the map
	/// call game function that adds image to the map

	//loads the image of the flybase
	mFlyBaseImage = make_unique<wxImage>(FlyBaseImage, wxBITMAP_TYPE_ANY);

	mFlyLeftWingImage = make_unique<wxImage>(FlyLeftWing, wxBITMAP_TYPE_ANY);

	mFlyRightWingImage = make_unique<wxImage>(FlyRightWing, wxBITMAP_TYPE_ANY);

	mFlyTopImage = make_unique<wxImage>(FlyTopImage, wxBITMAP_TYPE_ANY);

	mFlySplat = make_unique<wxImage>(FlySplat, wxBITMAP_TYPE_ANY);

	mGame = game;

}

/**
 * Draw this fly
 * @param dc Device context to draw on
 */
void RedundancyFly::Draw(std::shared_ptr<wxGraphicsContext> graphics)
{
	if (!GetSplat()) {
		if(mFlyBaseBitmap.IsNull())
		{
			mFlyBaseBitmap = graphics->CreateBitmapFromImage(*mFlyBaseImage);
		}
		if(mFlyLeftWingBitmap.IsNull())
		{
			mFlyLeftWingBitmap = graphics->CreateBitmapFromImage(*mFlyLeftWingImage);
		}
		if(mFlyRightWingBitmap.IsNull())
		{
			mFlyRightWingBitmap = graphics->CreateBitmapFromImage(*mFlyRightWingImage);
		}
		if(mFlyTopBitmap.IsNull())
		{
			mFlyTopBitmap = graphics->CreateBitmapFromImage(*mFlyTopImage);
		}

		int wid = mFlyBaseImage->GetWidth();
		int hit = mFlyBaseImage->GetHeight();

		int widleft = mFlyLeftWingImage->GetWidth();
		int hitleft = mFlyLeftWingImage->GetHeight();

		int widright = mFlyRightWingImage->GetWidth();
		int hitright = mFlyLeftWingImage->GetHeight();

		int draw_amt = 0;
		double wingTime = (2 * fmod(mDuration, WingPeriod))/ WingPeriod;

		if (wingTime > 1)
		{
			wingTime = 2 - wingTime;
		}

		double angle = atan2(GetLaptop()->GetY() - GetY(), GetLaptop()->GetX() - GetX());
		double angleWings = (WingRotateStart + (wingTime * (WingRotateEnd - WingRotateStart)));

		graphics->PushState();
		graphics->Translate(GetX(), GetY());
		graphics->Rotate(angle);
		graphics->DrawBitmap(mFlyBaseBitmap, (-wid / 2), (-hit / 2), wid, hit);

		while(draw_amt < NumberOfSetsOfWings)
		{
			graphics->PushState();
			graphics->Translate(FirstWingSetX + (WingSetXOffset * (draw_amt)), -WingSetY);
			graphics->Rotate(-angleWings);
			graphics->DrawBitmap(mFlyLeftWingBitmap, (- wid / 2), - hit / 2, widleft, hitleft);
			graphics->PopState();

			graphics->PushState();
			graphics->Translate(FirstWingSetX + (WingSetXOffset * (draw_amt)), WingSetY);
			graphics->Rotate(angleWings);
			graphics->DrawBitmap(mFlyRightWingBitmap, (- wid / 2), -hit / 2, widright, hitright);
			graphics->PopState();

			draw_amt += 1;
		}

		graphics->DrawBitmap(mFlyTopBitmap, (-wid / 2), (-hit / 2), wid, hit);

		graphics->PopState();
		
	}
	else
	{
		double wid = mFlySplat->GetWidth();
		double hit = mFlySplat->GetHeight();

		if(mFlySplatBitmap.IsNull())
		{
			mFlySplatBitmap = graphics->CreateBitmap(*mFlySplat);

		}
		double angle = atan2(GetLaptop()->GetY() - GetY(), GetLaptop()->GetX() - GetX());

		graphics->PushState();
		graphics->Translate(GetX(), GetY());
		graphics->Rotate(angle);
		graphics->DrawBitmap(mFlySplatBitmap, -wid / 2, -hit / 2, wid, hit);
		graphics->PopState();
	}
}

wxXmlNode* RedundancyFly::XmlSave(wxXmlNode* node)
{
	auto itemNode = Item::XmlSave(node);

	itemNode->AddAttribute(L"type", L"redundancyfly");

	return itemNode;
}

/**
 * Test to see if we hit this object with a mouse.
 * @param x X position to test
 * @param y Y position to test
 * @return true if hit.
 */
bool RedundancyFly::HitTest(int x, int y)
{
	double dx = x - GetX();
	double dy = y - GetY();

	return sqrt(dx * dx + dy * dy) < 50;
}

void RedundancyFly::SingleClick(int x, int y)
{
	if (mInitFly)
	{
		//tell game to multiply
		mGame->RedundancyFlySplit(this);
		//SetDel(true);
		SetSplat(true);
		BugCollection::SetSpeed(0);
	}
	else
	{
		SetSplat(true);
        BugCollection::SetSpeed(0);
	}
}

void RedundancyFly::setInit(bool init)
{
	mInitFly = init;
}

void RedundancyFly::Update(double elapsed, long totalTime)
{
	BugCollection::Update(elapsed, totalTime);
	mDuration += elapsed;
}

