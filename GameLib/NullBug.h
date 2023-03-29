/**
 * @file NullBug.h
 * @author Kaijia Joanna Zhan
 * @author Flora Pieters
 * @author Courtney Thang
 *
 * Creates our Null bug in the game
 */

#ifndef PROJECT1_COPY_GAMELIB_NULLBUG_H
#define PROJECT1_COPY_GAMELIB_NULLBUG_H

#include "BugCollection.h"

/**
 * Creates our Null bug in the game derived from BugCollection class
 */
class NullBug : public BugCollection
{
private:


public:
	/// Default constructor (disabled)
	NullBug() = delete;

	/// Copy constructor (disabled)
	NullBug(const NullBug &) = delete;

	/// Assignment operator
	void operator=(const NullBug &) = delete;

	NullBug(Game *game);

	bool HitTest(int x, int y) override;

	void SingleClick(int x, int y) override;

};

#endif //PROJECT1_COPY_GAMELIB_NULLBUG_H
