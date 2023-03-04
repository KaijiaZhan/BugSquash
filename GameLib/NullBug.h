/**
 * @file NullBug.h
 * @author Kaijia Joanna Zhan
 *
 *
 */

#ifndef PROJECT1_COPY_GAMELIB_NULLBUG_H
#define PROJECT1_COPY_GAMELIB_NULLBUG_H

#include "BugCollection.h"

/**
 * Class for bug type NullBug
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

};

#endif //PROJECT1_COPY_GAMELIB_NULLBUG_H
