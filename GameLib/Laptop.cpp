/**
 * @file Laptop.cpp
 * @author Kaijia
 */

#include "pch.h"
#include "Laptop.h"
#include <string>

class Game;

/// Laptop Image
const std::wstring LaptopImage = L"laptop.png";

/**
 * Constructor
 * @param game The game this item is a member of
 */
Laptop::Laptop(Game *game) : mGame(game)
{
}

/**
 * Destructor
 */
Laptop::~Laptop()
{

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
}