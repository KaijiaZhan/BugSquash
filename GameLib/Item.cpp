/**
 * @file Item.cpp
 * @author Parker Morgan
 */

#include "pch.h"
#include "Item.h"

#include <string>

class Game;

/// Laptop Image
const std::wstring LaptopImage = L"laptop.png";

using namespace std;

/**
 * Constructor
 * @param game The game this item is a member of
 */
Item::Item(Game *game) : mGame(game)
{
}

/**
 * Destructor
 */
Item::~Item()
{

}


/**
 * Draw this item
 * @param dc Device context to draw on
 */
void Item::Draw(wxDC *dc)
{
	double wid = mItemBitmap->GetWidth();
	double hit = mItemBitmap->GetHeight();

	dc->DrawBitmap(*mItemBitmap,
				   int(GetX() - wid / 2),
				   int(GetY() - hit / 2));
}