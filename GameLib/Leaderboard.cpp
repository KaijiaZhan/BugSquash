/**
 * @file Leaderboard.cpp
 * @author rmpal
 */

#include "pch.h"
#include "Leaderboard.h"
#include <wx/graphics.h>
#include <wx/textdlg.h>

/**
 * Draw the game
 * @param graphics The graphics context to draw on
 * @param width The width
 * @param height The height
 */
void Leaderboard::OnDraw(std::shared_ptr<wxGraphicsContext> graphics, int width, int height)
{
	graphics->SetBrush(*wxGREY_BRUSH);
	graphics->DrawRectangle((Width/7)*2,100,(Width/7)*3,800);

	///Draw Leaderboard header
	wxFont headfont(HeaderSize,
				wxFONTFAMILY_SWISS,
				wxFONTSTYLE_NORMAL,
				wxFONTWEIGHT_NORMAL);
	graphics->SetFont(headfont, wxColour(0,200,200));

	graphics->DrawText(L"Leaderboard",  // Text to draw
					   (Width/7)*2 + HeaderLableX,     // x coordinate for the left size of the text
					   HeaderLabelY);    // y coordinate for the top of the text


   ///Draw rest of leaderboard
	wxFont font(HeaderSize,
				wxFONTFAMILY_SWISS,
				wxFONTSTYLE_NORMAL,
				wxFONTWEIGHT_NORMAL);
	graphics->SetFont(font, wxColour(0,200,200));

	for(Player player : mPlayerScores)
	{
		graphics->DrawText(player.GetName(),  // Text to draw
						   (Width/7)*2 + ScoreLableX,     // x coordinate for the left size of the text
						   mScoreY);    // y coordinate for the top of the text

		graphics->DrawText(wxString::Format(wxT("%i"),player.GetScore()),  // Text to draw
						   (Width/7)*2 + ScoreX,     // x coordinate for the left size of the text
						   mScoreY);    // y coordinate for the top of the text

	    mScoreY += 120;
	}

	mScoreY = 300;


}

/**
 * Reset the players scores
 */
void Leaderboard::Reset()
{
	mPlayerScores.clear();
}

/**
 * Sets player name and scores on scoreboard
 * @param score the score for the level
 */
void Leaderboard::AssessPlayerScore(int score)
{
	///Prompt for user name
	wxString name = wxGetTextFromUser(L"Max 3 Letters", L"Input Name", L"AAA");
	if(name.length() > 3)
	{
		name = name.substr(0,3);
	}


	///Make new player
	Player player;
	player.SetName(name);
	player.SetScore(score);


	///Add to leaderboard
	if(static_cast<int>(mPlayerScores.size()) > 5)
	{
		Player low_player = mPlayerScores[4];
		int low_score = low_player.GetScore();

		if(score > low_score)
		{
			mPlayerScores.pop_back();
			mPlayerScores.push_back(player);
		}
	}
	else
	{
		mPlayerScores.push_back(player);
	}


	///Sort Leaderboard
	sort(mPlayerScores.begin(), mPlayerScores.end(), [](Player p1, Player p2)
	{
		return (p1.GetScore() > p2.GetScore());
	});
}