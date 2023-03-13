/**
 * @file Feature.cpp
 * @author Courtney Thang
 * @author Parker Morgan
 */

#include "pch.h"
#include "Feature.h"
#include <string>

using namespace std;

class Game;

/// Feature filenames
const wstring FeatureImage = L"images/feature.png";
const wstring FeatureSplat = L"feature-splat.png";

/**
 * Constructor
 * @param game Game this bug is a member of
 */
Feature::Feature(Game *game) : Item(game, FeatureImage)
{
	mFeatureImage = make_unique<wxImage>(FeatureImage, wxBITMAP_TYPE_ANY);
	mFeatureBitmap = make_unique<wxBitmap>(*mFeatureImage);
}

/**
 * Draw this feature
 * @param dc Device context to draw on
 */
void Feature::Draw(wxDC *dc)
{
	double wid = mFeatureBitmap->GetWidth();
	double hit = mFeatureBitmap->GetHeight();

	dc->DrawBitmap(*mFeatureBitmap,
				   int(GetX() - wid / 2),
				   int(GetY() - hit / 2));


}
