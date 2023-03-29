/**
 * @file ScoreBoard.cpp
 * @author Joanna Rodriguez
 * @author Kaijia Zhan
 */

#include "pch.h"
#include "ScoreBoard.h"
#include <wx/graphics.h>

/**
 * Draw the ScoreBoard
 * @param graphics
 */
void ScoreBoard::OnDraw(std::shared_ptr<wxGraphicsContext> graphics)
{

    wxFont font(LabelSize,
                wxFONTFAMILY_SWISS,
                wxFONTSTYLE_NORMAL,
                wxFONTWEIGHT_NORMAL);
    graphics->SetFont(font, wxColour(0,200,200));

    graphics->DrawText(L"Fixed",  // Text to draw
					   LeftScoreX,     // x coordinate for the left size of the text
                       ScoreLabelY);    // y coordinate for the top of the text

    graphics->DrawText(wxString::Format(wxT("%i"),mFixed),  // Text to draw
					   LeftScoreX + 50,     // x coordinate for the left size of the text
                       ScoreY);    // y coordinate for the top of the text

    graphics->DrawText(L"Missed",  // Text to draw
                       Width/2 - 60,     // x coordinate for the left size of the text
                       ScoreLabelY);    // y coordinate for the top of the text

    graphics->DrawText(wxString::Format(wxT("%i"),mMissed),  // Text to draw
                       Width/2 - 10,     // x coordinate for the left size of the text
                       ScoreY);    // y coordinate for the top of the text

    graphics->DrawText(L"Oops",  // Text to draw
                       Width - (LeftScoreX * 2),     // x coordinate for the left size of the text
                       ScoreLabelY);    // y coordinate for the top of the text

    graphics->DrawText(wxString::Format(wxT("%i"),mOops),  // Text to draw
					   Width - (LeftScoreX * 2) + 50,     // x coordinate for the left size of the text
                       ScoreY);    // y coordinate for the top of the text

}

/**
 * Reset the numbers for scoreboard
 */
void ScoreBoard::Reset()
{
	mFixed = 0;
	mOops = 0;
	mMissed = 0;
}
