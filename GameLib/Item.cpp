/**
 * @file Item.cpp
 * @author Parker Morgan
 * @author Courtney Thang
 */

#include "pch.h"
#include "Item.h"
#include "Game.h"

#include <string>


using namespace std;

/**
 * Constructor
 * @param game The game this item is a member of
 * @param filename that the item is taking the image of
 */
Item::Item(Game *game, const std::wstring &filename) : mGame(game)
{
	mItemImage = make_unique<wxImage>(filename, wxBITMAP_TYPE_ANY);
	mItemBitmap = make_unique<wxBitmap>(*mItemImage);
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