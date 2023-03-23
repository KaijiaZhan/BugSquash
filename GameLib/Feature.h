/**
 * @file Feature.h
 * @author Courtney Thang
 * @author Parker Morgan
 * @author Flora Pieters
 */

#ifndef PROJECT1_GAMELIB_FEATURE_H
#define PROJECT1_GAMELIB_FEATURE_H

#include "BugCollection.h"

/**
 * Initializes the feature item
 */
class Feature : public BugCollection
{
private:


public:
	/// Default constructor (disabled)
	Feature() = delete;

	/// Copy constructor (disabled)
	Feature(const Feature &) = delete;

	/// Assignment operator
	void operator=(const Feature &) = delete;

	/// Constructor
	Feature(Game* game);

	bool HitTest(int x, int y) override;

};

#endif //PROJECT1_GAMELIB_FEATURE_H
