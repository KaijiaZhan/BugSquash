/**
 * @file Game.cpp
 * @author rmpal
 * @author Courtney Thang
 * @author Kaijia Joanna Zhan
 * @author Parker Morgan
 */

#include "pch.h"
#include "Game.h"
#include "Laptop.h"
#include "Feature.h"
#include "RedundancyFly.h"
#include "wx/xml/xml.h"
#include <wx/graphics.h>

using namespace std;

/**
* Game Constructor
*/
Game::Game()
{
	shared_ptr<Item> laptop = make_shared<Laptop>(this);
	laptop->SetLocation(Width/2, Height/2);
	mItems.push_back(laptop);

	shared_ptr<Item> bug = make_shared<RedundancyFly>(this);
	bug->SetLocation(200, 500);
	mItems.push_back(bug);

	mLevel0.Load(L"levels/level0.xml", this);
	mLevel1.Load(L"levels/level1.xml", this);
	mLevel2.Load(L"levels/level2.xml", this);
	mLevel3.Load(L"levels/level3.xml", this);


}

/**
 * Draw the game
 * @param dc The device context to draw on
 */
void Game::OnDraw(wxDC *dc, std::shared_ptr<wxGraphicsContext> graphics, int width, int height)
{
	//
	// Automatic Scaling
	//
	auto scaleX = double(width) / double(Width);
	auto scaleY = double(height) / double(Height);
	mScale = std::min(scaleX, scaleY);

	if(mShrinked)
	{
		mScale *= ShrinkScale;
	}

	mXOffset = (width - Width * mScale) / 2;
	mYOffset = (height - Height * mScale) / 2;

	graphics->PushState();

	graphics->Translate(mXOffset, mYOffset);
	graphics->Scale(mScale, mScale);

	// From here on you are drawing virtual pixels

	//
	// Your drawing code goes here
	//

	graphics->PopState();

	for (auto item : mItems)
	{
		item->Draw(dc);
	}
}


/**
 * Handle updates for animation
 * @param elapsed The time since the last update
 */
void Game::Update(double elapsed, long totalTime)
{
	for (auto item : mItems)
	{
		item->Update(elapsed, totalTime);
	}
}

/**
 * Test an x,y click location to see if it clicked
 * on some item in the game.
 * @param x X location in pixels
 * @param y Y location in pixels
 * @returns Pointer to item we clicked on or nullptr if none.
*/
std::shared_ptr<Item> Game::HitTest(int x, int y)
{
	for (auto i = mItems.rbegin(); i != mItems.rend();  i++)
	{
		if ((*i)->HitTest(x, y))
		{
			return *i;
		}
	}

	return  nullptr;
}

/**
 * Load level
 * @param level the level number
 */
void Game::LoadLevel(int level)
{
	Clear();

	if (level == 0)
	{
		SetLevel(mLevel0.GetLevel());
	}
	if (level == 1)
	{
		SetLevel(mLevel1.GetLevel());
	}
	if (level == 2)
	{
		SetLevel(mLevel2.GetLevel());
	}
	if (level == 3)
	{
		SetLevel(mLevel3.GetLevel());
	}

	shared_ptr<Item> laptop = make_shared<Laptop>(this);
	laptop->SetLocation(Width/2, Height/2);
	mItems.push_back(laptop);

}

/**
 * Clear the game data
 * Deletes all known items in the game
*/
void Game::Clear()
{
	mItems.erase(mItems.begin(), mItems.end());
}

/**
 * Add an item to the game
 * @param item New item to add
 */
void Game::Add(std::shared_ptr<Item> item)
{
//    auto nextBug = 50;
//    item->SetLocation(10, 10);
//
//    for (auto bugs : mItems)
//    {
//        for (auto bug : mItems)
//        {
//            item->SetLocation(item->GetX() + nextBug, item->GetY() + nextBug);
//        }
//    }
    mItems.push_back(item);
}

