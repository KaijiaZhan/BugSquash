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
Item::Item(Game *game, const std::wstring image) : mGame(game)
{
//	mItemImage = make_unique<wxImage>(filename, wxBITMAP_TYPE_ANY);
//	mItemBitmap = make_unique<wxBitmap>(*mItemImage);
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

/**
 * Test to see if we hit this object with a mouse.
 * @param x X position to test
 * @param y Y position to test
 * @return true if hit.
 */
bool Item::HitTest(int x, int y)
{
	double width = mItemBitmap->GetWidth();
	double height = mItemBitmap->GetHeight();

	double testX = x - GetX() + width / 2;
	double testY = y - GetY() + height / 2;

	if (testX < 0 || testY < 0 || testX >= width || testY >= height)
	{
		return false;
	}

	return !mItemImage->IsTransparent((int)testX, (int)testY);
}