/**
 * @file Player.h
 * @author Parker Morgan
 *
 * Creates our player
 */

#ifndef PROJECT1_GAMELIB_PLAYER_H
#define PROJECT1_GAMELIB_PLAYER_H

#include <wx/graphics.h>

class Player
{
private:
	/// The initials of the player
	wxString mName = "AAA";

	/// The players score
	int mScore = 0;

public:
	/**
	 * Function that sets name
	 * @param name the name of the player
	 */
	void SetName(wxString name) {mName = name;}

	/**
	 * Getter that returns name
	 * @return mName the name of the player
	 */
	wxString GetName() {return mName;}

	/**
	 * Setter that sets score
	 * @param score the score
	 */
	void SetScore(int score) {mScore = score;}

	/**
	 * Getter that gets score
	 * @return mScore the score
	 */
	int GetScore() {return mScore;}

};

#endif //PROJECT1_GAMELIB_PLAYER_H
