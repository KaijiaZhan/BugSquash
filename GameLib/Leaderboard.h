/**
 * @file Leaderboard.h
 * @author rmpal
 *
 *
 */

#ifndef PROJECT1_GAMELIB_LEADERBOARD_H
#define PROJECT1_GAMELIB_LEADERBOARD_H

#include <vector>
#include <string>
#include "Player.h"

class Leaderboard
{
private:
	/// Game area in virtual pixels
	const static int Width = 1250;

	/// Header lable size
	const int HeaderSize = 60;

	/// Score label Y location
	const int HeaderLabelY = 140;

	/// Score label X location
	const int HeaderLableX = 40;

	/// The font color to use
	const wxColour FontColor = wxColour(0, 200, 200);

	/// Left score X location. The right score is
	/// the width minus this value.
	const int ScoreX = 340;

	/// Score Y location
	int mScoreY = 300;

	/// The score label x
	const int ScoreLableX = 75;

	/// The players scores vector
	std::vector<Player> mPlayerScores = {};

	/// Bool to check if the game is still active
	bool mActive = false;

public:
	void OnDraw(std::shared_ptr<wxGraphicsContext> graphics, int width, int height);

	void Reset();

	void SetActive(bool active) {mActive = active;}

	bool GetActive() {return mActive;}

	void AssessPlayerScore(int score);

};

#endif //PROJECT1_GAMELIB_LEADERBOARD_H
