/**
 * @file BugCounter.h
 * @author Kaijia Zhan
 */

#ifndef PROJECT1_GAMELIB_BUGCOUNTER_H
#define PROJECT1_GAMELIB_BUGCOUNTER_H
class BugCollection;

class BugCounter
{
private:
	/// Bug counter
	int mNumBugs = 0;
public:
	int GetNumbBugs() const {return mNumBugs;}

	/**
     * Visit a TileBuilding object
     * @param bugCollection Building we are visiting
     */
	void VisitBugCollection(BugCollection* bugCollection)
	{
		mNumBugs++;
	}
};

#endif //PROJECT1_GAMELIB_BUGCOUNTER_H
