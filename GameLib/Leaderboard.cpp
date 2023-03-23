/**
 * @file Leaderboard.cpp
 * @author rmpal
 */

#include "pch.h"
#include "Leaderboard.h"
#include <wx/graphics.h>

/**
 * Draw the game
 * @param dc The device context to draw on
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
					   100,     // x coordinate for the left size of the text
					   HeaderLabelY);    // y coordinate for the top of the text


   ///Draw rest of leaderboard
	wxFont font(HeaderSize,
				wxFONTFAMILY_SWISS,
				wxFONTSTYLE_NORMAL,
				wxFONTWEIGHT_NORMAL);
	graphics->SetFont(font, wxColour(0,200,200));

	Player p1;
	p1.SetName("ABB");
	p1.SetScore(20);
	Player p2;
	Player p3;
	p3.SetName("HHH");
	p3.SetScore(30);
	mPlayerScores.push_back(p1);
	mPlayerScores.push_back(p2);
	mPlayerScores.push_back(p3);
	///Sort Leaderboard
	sort(mPlayerScores.begin(), mPlayerScores.end(), [](Player p1, Player p2)
	{
		return (p1.GetScore() < p2.GetScore());
	});

	for(Player player : mPlayerScores)
	{
		graphics->DrawText(player.GetName(),  // Text to draw
						   ScoreLableX,     // x coordinate for the left size of the text
						   mScoreY);    // y coordinate for the top of the text

		graphics->DrawText(wxString::Format(wxT("%i"),player.GetScore()),  // Text to draw
						   ScoreX,     // x coordinate for the left size of the text
						   mScoreY);    // y coordinate for the top of the text

	    mScoreY += 60;
	}

	mScoreY = 40;


}


void Leaderboard::Reset()
{

}

bool Compare(Player p1, Player p2)
{
	return (p1.GetScore() < p2.GetScore());
}