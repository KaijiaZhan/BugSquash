/**
 * @file Game.cpp
 * @author rmpal
 * @author Courtney Thang
 * @author Kaijia Joanna Zhan
 *
 */

#include "pch.h"
#include "Game.h"
#include "Laptop.h"
#include "Feature.h"
#include "RedundancyFly.h"

using namespace std;

/**
* Game Constructor
*/
Game::Game()
{
	// Create a new laptop.
	// This creates a shared pointer pointing at this laptop
	shared_ptr<Item> laptop = make_shared<Laptop>(this);

	//temp
	shared_ptr<Item> rfly = make_shared<RedundancyFly>(this);

	// Set the location
	laptop->SetLocation(500, 400);

	//temp
	rfly->SetLocation(200, 100);

	// Add to the list of laptop.
	mItems.push_back(laptop);

	//temp
	mItems.push_back(rfly);

}

/**
 * Draw the game
 * @param dc The device context to draw on
 */
void Game::OnDraw(wxDC *dc)
{
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
//	for (auto i = mItems.rbegin(); i != mItems.rend();  i++)
//	{
//		if ((*i)->HitTest(x, y))
//		{
//			return *i;
//		}
//	}
//
	return  nullptr;
}

/**
 * Clear the game data
 * Deletes all known items in the game
*/
void Game::Clear()
{
	mItems.erase(mItems.begin(), mItems.end());
}