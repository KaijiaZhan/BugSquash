/**
 * @file Laptop.h
 * @author Kaijia
 * @author Courtney Thang
 *
 */

#ifndef PROJECT1_GAMELIB_LAPTOP_H
#define PROJECT1_GAMELIB_LAPTOP_H

#include "Item.h"
class Game;

/**
 * Class that is our Laptop/program Item
 */
class Laptop : public Item
{
private:

	/// The laptop image
	std::unique_ptr<wxImage> mLaptopImage;
	/// The laptop bitmap
	std::unique_ptr<wxBitmap> mLaptopBitmap;

protected:

public:

	/// Default constructor (disabled)
	Laptop() = delete;

	/// Copy constructor (disabled)
	Laptop(const Laptop &) = delete;

	/// Assignment operator
	void operator=(const Laptop &) = delete;

	Laptop(Game* game);

	/**
	 * Draw this item
	 * @param dc Device context to draw on
	 */
	void Draw(wxDC *dc) override;

};

#endif //PROJECT1_GAMELIB_LAPTOP_H
