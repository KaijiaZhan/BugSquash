/**
 * @file ScoreBoard.cpp
 * @author joann
 */

#include "pch.h"
#include "ScoreBoard.h"

/**
 * Draw the game
 * @param dc The device context to draw on
 */
void ScoreBoard::OnDraw(wxDC *dc, std::shared_ptr<wxGraphicsContext> graphics, int width, int height)
{
    //
    // Automatic Scaling
    //
    auto scaleX = double(width) / double(Width);
    auto scaleY = double(height) / double(Height);
    mScale = std::min(scaleX, scaleY);

    if(mShrinked)
    {
        mScale *= ShrinkScale;
    }

    mXOffset = (width - Width * mScale) / 2;
    mYOffset = (height - Height * mScale) / 2;

    graphics->PushState();

    graphics->Translate(mXOffset, mYOffset);
    graphics->Scale(mScale, mScale);

    wxFont font(LabelSize,
                wxFONTFAMILY_SWISS,
                wxFONTSTYLE_NORMAL,
                wxFONTWEIGHT_NORMAL);
    graphics->SetFont(font, wxColour(0,200,200));
    //graphics->SetTextForeground(FontColor);

    graphics->DrawText(L"Fixed",  // Text to draw
                       50,     // x coordinate for the left size of the text
                       ScoreLabelY);    // y coordinate for the top of the text

    graphics->DrawText(L"0",  // Text to draw
                       90,     // x coordinate for the left size of the text
                       ScoreLabelY - 50);    // y coordinate for the top of the text

    graphics->DrawText(L"Missed",  // Text to draw
                       450,     // x coordinate for the left size of the text
                       ScoreLabelY);    // y coordinate for the top of the text

    graphics->DrawText(L"0",  // Text to draw
                       490,     // x coordinate for the left size of the text
                       ScoreLabelY - 50);    // y coordinate for the top of the text

    graphics->DrawText(L"Oops",  // Text to draw
                       875,     // x coordinate for the left size of the text
                       ScoreLabelY);    // y coordinate for the top of the text

    graphics->DrawText(L"0",  // Text to draw
                       915,     // x coordinate for the left size of the text
                       ScoreLabelY - 50);    // y coordinate for the top of the text

    // need laptop and bug scaled
    graphics->PopState();
}
