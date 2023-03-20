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
Feature::Feature(Game *game) : Item(game)
{
    mFeatureImage = make_unique<wxImage>(FeatureImage, wxBITMAP_TYPE_ANY);

    mFeatureSplat = make_unique<wxImage>(FeatureSplat, wxBITMAP_TYPE_ANY);

}

/**
 * Draw this fly
 * @param dc Device context to draw on
 */
void Feature::Draw(std::shared_ptr<wxGraphicsContext> graphics)
{
    if(mFeatureBitmap.IsNull())
    {
        mFeatureBitmap = graphics->CreateBitmapFromImage(*mFeatureImage);
    }
    int wid = mFeatureImage->GetWidth();
    int hit = mFeatureImage->GetHeight();
    graphics->DrawBitmap(mFeatureBitmap,
                         int(GetX() - wid / 2),
                         int(GetY() - hit / 2), wid, hit);
}

wxXmlNode* Feature::XmlSave(wxXmlNode* node)
{
    auto itemNode = Item::XmlSave(node);

    itemNode->AddAttribute(L"type", L"feature");

    return itemNode;
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
