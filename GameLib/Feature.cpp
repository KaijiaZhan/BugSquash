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

/// Feature filename
const wstring FeatureImage = L"images/feature.png";

/// Feature filenames
const wstring FeatureSplat = L"images/feature-splat.png";

/**
 * Constructor
 * @param game Game this bug is a member of
 */
Feature::Feature(Game *game) : Item(game, FeatureImage)
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
