/**
 * @file GarbageBug.h
 * @author Kaijia
 *
 * Header for bug type Garbage Bug
 */

#ifndef PROJECT1_COPY_GAMELIB_GARBAGEBUG_H
#define PROJECT1_COPY_GAMELIB_GARBAGEBUG_H

//#include "BugCollection.h"

/**
 * Class for type GarbageBug
 */

///: public BugCollection
class GarbageBug
{
private:

public:
	/// Default constructor (disabled)
	GarbageBug() = delete;

	/// Copy constructor (disabled)
	GarbageBug(const GarbageBug &) = delete;

	/// Assignment operator
	void operator=(const GarbageBug &) = delete;

};

#endif //PROJECT1_COPY_GAMELIB_GARBAGEBUG_H
