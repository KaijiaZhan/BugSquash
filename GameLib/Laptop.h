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

class Laptop : public Item
{
private:

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
	virtual void Draw(wxDC *dc) = 0;

};

#endif //PROJECT1_GAMELIB_LAPTOP_H
