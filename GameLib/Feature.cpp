/**
 * @file Feature.cpp
 * @author Courtney Thang
 * @author Parker Morgan
 * @author Flora Pieters
 * @author Joanna Rodriguez
 * @author Kaijia Zhan
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

/// Number of sprite images
const int FeatureNumSpriteImages = 6;

/**
 * Constructor
 * @param game Game this bug is a member of
 */
Feature::Feature(Game *game) : BugCollection(game,FeatureImage)
{
	BugCollection::BugSetImage(FeatureImage, FeatureNumSpriteImages, FeatureSplat);

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

/**
 * Sets the bug to squash when clicked on
 * @param x the x location
 * @param y the y location
 */
void Feature::SingleClick(int x, int y)
{
    SetSplat(true);
    BugCollection::SetSpeed(0);
}

