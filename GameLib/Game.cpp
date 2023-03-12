/**
 * @file Game.cpp
 * @author rmpal
 * @author Courtney Thang
 * @author Kaijia Joanna Zhan
 *
 */

#include "pch.h"
#include "Game.h"
#include "RedundancyFly.h"

using namespace std;

/**
* Game Constructor
*/
Game::Game()
{
	// Create a new fish.
	// This creates a shared pointer pointing at this fish
	shared_ptr<Item> redundancyFlyBase = make_shared<RedundancyFly>(this);

	// Set the location
	redundancyFlyBase->SetLocation(50, 150);

	// Add to the list of fish.
	mItems.push_back(redundancyFlyBase);

}

//**
// * Draw the game
// * @param dc The device context to draw on
// */
void Game::OnDraw(wxDC *dc)
{
	for (auto item : mItems)
	{
		item->Draw(dc);
	}
}