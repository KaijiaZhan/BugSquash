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

/**
 * Constructor
 * @param game Game this fly is a member of
 */
RedundancyFly::RedundancyFly(Game *game) : BugCollection(game, FlyBaseImage)
{
	//loads the image of the flybase
	mFlyBaseImage = make_unique<wxImage>(FlyBaseImage, wxBITMAP_TYPE_ANY);
	mFlyBaseBitmap = make_unique<wxBitmap>(*mFlyBaseImage);
	mFlyLeftWingImage = make_unique<wxImage>(FlyLeftWing, wxBITMAP_TYPE_ANY);
	mFlyLeftWingBitmap = make_unique<wxBitmap>(*mFlyLeftWingImage);
	mFlyRightWingImage = make_unique<wxImage>(FlyRightWing, wxBITMAP_TYPE_ANY);
	mFlyRightWingBitmap = make_unique<wxBitmap>(*mFlyRightWingImage);
	mFlyTopImage = make_unique<wxImage>(FlyTopImage, wxBITMAP_TYPE_ANY);
	mFlyTopBitmap = make_unique<wxBitmap>(*mFlyTopImage);
	mFlySplat = make_unique<wxImage>(FlySplat, wxBITMAP_TYPE_ANY);
	//mFlyBitmap = make_unique<wxBitmap>(*mFlySplat);

}


/**
 * Draw this fly
 * @param dc Device context to draw on
 */
void RedundancyFly::Draw(wxDC *dc)
{

	double wid = mFlyBaseBitmap->GetWidth();
	double hit = mFlyBaseBitmap->GetHeight();
	dc->DrawBitmap(*mFlyBaseBitmap,
				   int(GetX() - wid / 2),
				   int(GetY() - hit / 2));

	double widleft = mFlyLeftWingBitmap->GetWidth();
	double hitleft = mFlyLeftWingBitmap->GetHeight();
	dc->DrawBitmap(*mFlyLeftWingBitmap,
				   int(GetX()- wid / 2),
				   int(GetY() - hit / 2));

	dc->DrawBitmap(*mFlyLeftWingBitmap,
				   int(GetX() - WingSetXOffset - wid / 2),
				   int(GetY() - hit / 2));

	dc->DrawBitmap(*mFlyLeftWingBitmap,
				   int(GetX() - (WingSetXOffset * 2) - wid / 2),
				   int(GetY() - hit / 2));

	dc->DrawBitmap(*mFlyLeftWingBitmap,
				   int(GetX() - (WingSetXOffset * 3) - wid / 2),
				   int(GetY() - hit / 2));

	double widright = mFlyRightWingBitmap->GetWidth();
	double hitright = mFlyRightWingBitmap->GetHeight();
	dc->DrawBitmap(*mFlyRightWingBitmap,
				   int(GetX() - wid / 2),
				   int(GetY() - hit / 2));
	dc->DrawBitmap(*mFlyRightWingBitmap,
				   int(GetX() - WingSetXOffset - wid / 2),
				   int(GetY() - hit / 2));

	dc->DrawBitmap(*mFlyRightWingBitmap,
				   int(GetX() - (WingSetXOffset * 2) - wid / 2),
				   int(GetY() - hit / 2));

	dc->DrawBitmap(*mFlyRightWingBitmap,
				   int(GetX() - (WingSetXOffset * 3) - wid / 2),
				   int(GetY() - hit / 2));

	double widtop = mFlyTopBitmap->GetWidth();
	double hittop = mFlyTopBitmap->GetHeight();
	dc->DrawBitmap(*mFlyTopBitmap,
				   int(GetX() - wid / 2),
				   int(GetY() - hit / 2));
}

wxXmlNode* RedundancyFly::XmlSave(wxXmlNode* node)
{
	auto itemNode = Item::XmlSave(node);

	itemNode->AddAttribute(L"type", L"redundancyfly");

	return itemNode;
}