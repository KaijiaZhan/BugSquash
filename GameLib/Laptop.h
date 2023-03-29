/**
 * @file Laptop.h
 * @author Kaijia Zhan
 * @author Courtney Thang
 *
 * Initializes the laptop/program in the game
 */

#ifndef PROJECT1_GAMELIB_LAPTOP_H
#define PROJECT1_GAMELIB_LAPTOP_H

#include "Item.h"

/**
 * Initializes the laptop/program in the game derived from Item class
 */
class Laptop : public Item
{
private:

	/// The laptop image
	std::unique_ptr<wxImage> mLaptopImage;
	/// The laptop bitmap
	wxGraphicsBitmap mLaptopBitmap;
	/// The name of the laptop
	std::wstring mName;


protected:

public:

	/// Default constructor (disabled)
	Laptop() = delete;

	/// Copy constructor (disabled)
	Laptop(const Laptop &) = delete;

	/// Assignment operator
	void operator=(const Laptop &) = delete;

	Laptop(Game* game);

	void Draw(std::shared_ptr<wxGraphicsContext> graphics) override;

	void SetName(std::wstring name);

	bool HitTest(int x, int y) override;
};

#endif //PROJECT1_GAMELIB_LAPTOP_H
