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
	shared_ptr<Item> feature = make_shared<Feature>(this);

	// Set the location
	laptop->SetLocation(500, 400);

	//temp
	feature->SetLocation(500, 400);

	// Add to the list of laptop.
	mItems.push_back(laptop);

	//temp
	mItems.push_back(feature);

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