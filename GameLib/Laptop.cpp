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
	mLaptopBitmap = make_unique<wxBitmap>(*mLaptopImage);
}

/**
 * Draw this item
 * @param dc Device context to draw on
 */
void Laptop::Draw(wxDC *dc)
{
	double wid = mLaptopBitmap->GetWidth();
	double hit = mLaptopBitmap->GetHeight();

	dc->DrawBitmap(*mLaptopBitmap,
	int(GetX() - wid / 2),
	int(GetY() - hit / 2));
	wxFont font(wxSize(0, 20),
				wxFONTFAMILY_SWISS,
				wxFONTSTYLE_NORMAL,
				wxFONTWEIGHT_NORMAL);
	dc->SetFont(font);
	dc->SetTextForeground(wxColour(120, 0, 120));
	dc->DrawText(L"BugSquash", int(GetX() - wid / 2), int(GetY() - hit / 2));
}