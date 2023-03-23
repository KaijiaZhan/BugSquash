/**
 * @file Player.h
 * @author Parker Morgan
 *
 *
 */

#ifndef PROJECT1_GAMELIB_PLAYER_H
#define PROJECT1_GAMELIB_PLAYER_H

#include <string>

/**
 * Class that is our Player
 */
class Player
{
private:
	std::string mName = "AAA";
	double mScore = 0;

public:
//	/// Default constructor (disabled)
//	Player() = delete;

//	/// Copy constructor (disabled)
//	Player(const Player &) = delete;

//	/// Assignment operator
//	void operator=(const Player &) = delete;

	void SetName(std::string name) {mName = name;}

	std::string GetName() {return mName;}

	void SetScore(double score) {mScore = score;}

	double GetScore() {return mScore;}

};

#endif //PROJECT1_GAMELIB_PLAYER_H
