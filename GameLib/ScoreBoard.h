/**
 * @file ScoreBoard.h
 * @author Joanna Rodriguez
 * @author Kaijia Zhan
 *
 * Initializes the scoreboard for the game
 */

#ifndef PROJECT1_GAMELIB_SCOREBOARD_H
#define PROJECT1_GAMELIB_SCOREBOARD_H

class ScoreBoard
{
private:
	///Bug fixed header for the game
	int mFixed = 0;

	///Bug oops header for the game
	int mOops = 0;

	///Bug missed header for the game
	int mMissed = 0;

	/// Game area in virtual pixels
	const static int Width = 1250;

	/// Game area height in virtual pixels
	const static int Height = 1000;

	/// Scale to shrink to when in shrink mode
	const double ShrinkScale = 0.75;

	/// boolean that sets window size
	bool mShrinked = true;

	/// The x offset for virtual pixels
	double mXOffset = 0;

	/// The y offset for virtual pixels
	double mYOffset = 0;

	/// The scaling for virtual pixels
	double mScale = 0;

	/// Lable for score font size to use
	const int LabelSize = 40;

	/// The font color to use
	const wxColour FontColor = wxColour(0, 200, 200);

	/// Left score X location. The right score is
	/// the width minus this value.
	const int LeftScoreX = 150;

	/// Score Y location
	const int ScoreY = 20;

	/// Score label Y location
	const int ScoreLabelY = 100;

public:
	/**
	 * Get fixed score
	 * @return fixed the fixed score
	 */
	double GetFixed() const { return mFixed; }

	/**
	 * Set fixed score
	 * @param fixed the fixed score
	 */
	void SetFixed(double fixed) {mFixed = fixed;}

	/**
	 * Get oops
	 * @return oops score
	 */
	double GetOops() const { return mOops; }

	/**
	 * Set oops score
	 * @param oops the oops score
	 */
	void SetOops(double oops) {mOops = oops;}

	/**
	 * Get missed
	 * @return missed score
	 */
	double GetMissed() const { return mMissed; }

	/**
	 * Set missed score
	 * @param missed The missed score
	 */
	void SetMissed(double missed) {mMissed = missed;}

	/**
	 * Draw the fixed area for scoreboard
	 * @param graphics Graphics context to draw on
	 * @param width The width
	 * @param height The height
	 */
	void OnDraw(std::shared_ptr<wxGraphicsContext> graphics, int width, int height);

	/**
	 * Resets the member variables to 0
	 */
	void Reset();

	/**
	 * Getting the scores
	 * @return (mFixed - mOops)
	 */
	int GetScore() {return (mFixed - mOops);}

};

#endif //PROJECT1_GAMELIB_SCOREBOARD_H
