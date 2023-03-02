/**
 * @file NullBug.h
 * @author Kaijia
 *
 *
 */

#ifndef PROJECT1_COPY_GAMELIB_NULLBUG_H
#define PROJECT1_COPY_GAMELIB_NULLBUG_H

//#include "BugCollection.h"
/// : public BugCollection
/**
 * Class for bug type NullBug
 */
class NullBug
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
