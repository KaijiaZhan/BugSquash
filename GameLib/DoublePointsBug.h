/**
 * @file DoublePointsBug.h
 * @author rmpal
 *
 * Initialize our double point bug
 */

#ifndef PROJECT1_GAMELIB_DOUBLEPOINTSBUG_H
#define PROJECT1_GAMELIB_DOUBLEPOINTSBUG_H

#include "BugCollection.h"

class DoublePointsBug : public BugCollection
{
private:

public:
	/// Default constructor (disabled)
	DoublePointsBug() = delete;

	/// Copy constructor (disabled)
	DoublePointsBug(const DoublePointsBug &) = delete;

	/// Assignment operator
	void operator=(const DoublePointsBug &) = delete;

	DoublePointsBug(Game *game);

	bool HitTest(int x, int y) override;

	/**
	 * Gets the type of bug
	 * @return The DoublePointsBug type
	 */
	std::string GetType() override {return "DoublePointsBug";}

};

#endif //PROJECT1_GAMELIB_DOUBLEPOINTSBUG_H
