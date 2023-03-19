/**
 * @file RedundancyFly.cpp
 * @author Courtney Thang
 * @author Joanna Rodriguez
 * @author Parker Morgan
 */

#include "pch.h"
#include "RedundancyFly.h"
#include "Game.h"
#include <string>

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
	//loads the image of the flybase
	mFlyBaseImage = make_unique<wxImage>(FlyBaseImage, wxBITMAP_TYPE_ANY);

	mFlyLeftWingImage = make_unique<wxImage>(FlyLeftWing, wxBITMAP_TYPE_ANY);

	mFlyRightWingImage = make_unique<wxImage>(FlyRightWing, wxBITMAP_TYPE_ANY);

	mFlyTopImage = make_unique<wxImage>(FlyTopImage, wxBITMAP_TYPE_ANY);

	mFlySplat = make_unique<wxImage>(FlySplat, wxBITMAP_TYPE_ANY);
	//mFlyBitmap = make_unique<wxBitmap>(*mFlySplat);

}


/**
 * Draw this fly
 * @param dc Device context to draw on
 */
void RedundancyFly::Draw(std::shared_ptr<wxGraphicsContext> graphics)
{
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
	graphics->DrawBitmap(mFlyBaseBitmap,
						 int(GetX() - wid / 2),
						 int(GetY() - hit / 2), wid, hit);

	int widleft = mFlyLeftWingImage->GetWidth();
	int hitleft = mFlyLeftWingImage->GetHeight();
	graphics->DrawBitmap(mFlyLeftWingBitmap,
						 int(GetX()- wid / 2),
						 int(GetY() - WingSetY - hit / 2), widleft, hitleft);

	graphics->DrawBitmap(mFlyLeftWingBitmap,
						 int(GetX() - WingSetXOffset - wid / 2),
						 int(GetY() - WingSetY - hit / 2), widleft, hitleft);

	graphics->DrawBitmap(mFlyLeftWingBitmap,
						 int(GetX() - (WingSetXOffset * 2) - wid / 2),
						 int(GetY() - WingSetY - hit / 2), widleft, hitleft);

	graphics->DrawBitmap(mFlyLeftWingBitmap,
						 int(GetX() - (WingSetXOffset * 3) - wid / 2),
						 int(GetY() - WingSetY - hit / 2), widleft, hitleft);

	int widright = mFlyRightWingImage->GetWidth();
	int hitright = mFlyLeftWingImage->GetHeight();
	graphics->DrawBitmap(mFlyRightWingBitmap,
						 int(GetX()- wid / 2),
						 int(GetY() + WingSetY - hit / 2), widright, hitright);

	graphics->DrawBitmap(mFlyRightWingBitmap,
						 int(GetX() - WingSetXOffset - wid / 2),
						 int(GetY() + WingSetY - hit / 2), widright, hitright);

	graphics->DrawBitmap(mFlyRightWingBitmap,
						 int(GetX() - (WingSetXOffset * 2) - wid / 2),
						 int(GetY() + WingSetY - hit / 2), widright, hitright);

	graphics->DrawBitmap(mFlyRightWingBitmap,
						 int(GetX() - (WingSetXOffset * 3) - wid / 2),
						 int(GetY() + WingSetY - hit / 2), widright, hitright);

	int widtop = mFlyTopImage->GetWidth();
	int hittop = mFlyTopImage->GetHeight();
	graphics->DrawBitmap(mFlyTopBitmap,
						 int(GetX() - wid / 2),
						 int(GetY() - hit / 2), widtop, hittop);
}

wxXmlNode* RedundancyFly::XmlSave(wxXmlNode* node)
{
	auto itemNode = Item::XmlSave(node);

	itemNode->AddAttribute(L"type", L"redundancyfly");

	return itemNode;
}