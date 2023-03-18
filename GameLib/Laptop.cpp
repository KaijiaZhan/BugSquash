/**
 * @file Laptop.cpp
 * @author Kaijia Joanna Zhan
 */

#include "pch.h"
#include "Laptop.h"
#include <string>

using namespace std;

class Game;

/// Laptop Image
const std::wstring LaptopImage = L"images/laptop.png";

/**
 * Constructor
 * @param game The game this item is a member of
 */
Laptop::Laptop(Game *game) : Item(game, LaptopImage)
{
	mLaptopImage = make_unique<wxImage>(LaptopImage, wxBITMAP_TYPE_ANY);

	SetLocation(game->GetWidth()/2,game->GetHeight()/2);
}

/**
 * Draw this item
 * @param dc Device context to draw on
 */
void Laptop::Draw(std::shared_ptr<wxGraphicsContext> graphics)
{
	int wid = mLaptopImage->GetWidth();
	int hit = mLaptopImage->GetHeight();

	if(mLaptopBitmap.IsNull())
	{
		mLaptopBitmap = graphics->CreateBitmapFromImage(*mLaptopImage);
	}

	graphics->DrawBitmap(mLaptopBitmap,
						 int(GetX() - wid / 2),
						 int(GetY() - hit / 2), wid, hit);
	wxFont font(wxSize(0, 20),
				wxFONTFAMILY_SWISS,
				wxFONTSTYLE_NORMAL,
				wxFONTWEIGHT_NORMAL);
	graphics->SetFont(font, *wxWHITE);
	graphics->DrawText(L"BugSquash", int(GetX() - wid / 2) + 50, int(GetY() - hit / 2) + 40);
}
