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

using namespace std;

/**
* Game Constructor
*/
Game::Game()
{
//	// Create a new laptop.
//	// This creates a shared pointer pointing at this laptop
//	shared_ptr<Item> Laptop = make_shared<Laptop>(this);
//
//	// Set the location
//	Laptop->SetLocation(50, 150);
//
//	// Add to the list of laptop.
//	mItems.push_back(Laptop);

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