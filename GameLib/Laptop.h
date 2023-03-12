/**
 * @file Laptop.h
 * @author Kaijia
 *
 *
 */

#ifndef PROJECT1_GAMELIB_LAPTOP_H
#define PROJECT1_GAMELIB_LAPTOP_H

class Game;

class Laptop
{
private:
	/// The game the item is contained in
	Game *mGame;

	/// Underlying Image
	std::unique_ptr<wxImage> mLaptopImage;

	/// The bitmap that can be displayed for the item
	std::unique_ptr<wxImage> mLaptopBitmap;

	// Item location in the game
	double  mX = 0;     ///< X location for the center of the item
	double  mY = 0;     ///< Y location for the center of the item


protected:
	Laptop(Game *game);
public:
	virtual ~Laptop();

	/// Default constructor (disabled)
	Laptop() = delete;

	/// Copy constructor (disabled)
	Laptop(const Laptop &) = delete;

	/// Assignment operator
	void operator=(const Laptop &) = delete;

	/**
	 * The X location of the item
	 * @return X location in pixels
	 */
	double GetX() const { return mX; }

	/**
	 * The Y location of the item
	 * @return Y location in pixels
	 */
	double GetY() const { return mY; }

	/**
	 * Set the item location
	 * @param x X location in pixels
	 * @param y Y location in pixels
	 */
	void SetLocation(double x, double y) { mX = x; mY = y; }

	/**
	 * Draw this item
	 * @param dc Device context to draw on
	 */
	virtual void Draw(wxDC *dc) = 0;

};

#endif //PROJECT1_GAMELIB_LAPTOP_H
