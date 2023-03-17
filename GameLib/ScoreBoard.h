/**
 * @file ScoreBoard.h
 * @author joann
 *
 * Initializes the score board for the game
 */

#ifndef PROJECT1_GAMELIB_SCOREBOARD_H
#define PROJECT1_GAMELIB_SCOREBOARD_H

/**
* Initializes the score board for the game
*/
class ScoreBoard
{
private:
	///Bug fixed header for the game
	int mFixed = 0;

	///Bug oops header for the game
	int mOops = 0;

	///Bug missed header for the game
	int mMissed = 0;

public:
    /**
	 * Get fixed score
	 * @return fixed score
	 */
    double GetFixed() const { return mFixed; }

    /**
	 * Get oops
	 * @return oops number
	 */
    double GetOops() const { return mOops; }

    /**
	 * Get missed
	 * @return missed number
	 */
    double GetMissed() const { return mMissed; }

};

#endif //PROJECT1_GAMELIB_SCOREBOARD_H
