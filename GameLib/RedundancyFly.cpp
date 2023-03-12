/**
 * @file RedundancyFly.cpp
 * @author Courtney Thang
 * @author Joanna Rodriguez
 */

#include "pch.h"
#include "RedundancyFly.h"
#include "Game.h"

#include <string>
using namespace std;

/// Redundancy fly filenames
const wstring FlyBaseImage = L"images/redundancy-fly-base.png";
const wstring FlyLeftWing = L"images/redundancy-fly-lwing.png";
const wstring FlyRightWing = L"images/redundancy-fly-rwing.png";
const wstring FlyTopImage = L"images/redundancy-fly-top.png";
const wstring FlySplat = L"images/redundancy-fly-splat.png";

/**
 * Constructor
 * @param game Game this fly is a member of
 */
RedundancyFly::RedundancyFly(Game *game) : Item(game)
{
	//loads the image of the flybase
	mFlyBaseImage = make_unique<wxImage>(FlyBaseImage, wxBITMAP_TYPE_ANY);
	mFlyBitmap = make_unique<wxBitmap>(*mFlyBaseImage);
}


/**
 * Draw this fly
 * @param dc Device context to draw on
 */
void RedundancyFly::Draw(wxDC *dc)
{
	double wid = mFlyBitmap->GetWidth();
	double hit = mFlyBitmap->GetHeight();
	dc->DrawBitmap(*mFlyBitmap,
				   int(GetX() - wid / 2),
				   int(GetY() - hit / 2));
}