/**
 * @file Item.h
 * @author Parker Morgan
 *
 *
 */

#ifndef PROJECT1_GAMELIB_ITEM_H
#define PROJECT1_GAMELIB_ITEM_H

class Game;

class Item
{
private:

public:
	/// Default constructor (disabled)
	Item() = delete;

	/// Copy constructor (disabled)
	Item(const Item &) = delete;

	/// Assignment operator
	void operator=(const Item &) = delete;

};

#endif //PROJECT1_GAMELIB_ITEM_H
