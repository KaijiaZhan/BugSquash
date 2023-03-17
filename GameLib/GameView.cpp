/**
 * @file GameView.cpp
 * @author joann
 * @author Courtney Thang
 * @author Flora Pieters
 */

#include "pch.h"
#include "GameView.h"

#include <sstream>
#include <wx/stdpaths.h>
#include <wx/dcbuffer.h>


/// Frame duration in milliseconds, this will be changed
const int FrameDuration = 30;

/**
 * Constructor
 * @param parent Pointer to wxFrame object, the main frame for the application
 */
void GameView::Initialize(wxFrame* parent)
{
	Create(parent, wxID_ANY);
	SetBackgroundColour(*wxWHITE);
	SetBackgroundStyle(wxBG_STYLE_PAINT);
	Bind(wxEVT_PAINT, &GameView::OnPaint, this);

	Bind(wxEVT_LEFT_DOWN, &GameView::OnLeftDown, this);
	Bind(wxEVT_LEFT_UP, &GameView::OnLeftUp, this);
	Bind(wxEVT_LEFT_DCLICK, &GameView::OnLeftDoubleClick, this);
	Bind(wxEVT_TIMER, &GameView::OnTimer, this);
	parent->Bind(wxEVT_COMMAND_MENU_SELECTED, &GameView::OnFileOpen, this, wxID_OPEN);

	mTimer.SetOwner(this);
	mTimer.Start(FrameDuration);
	mStopWatch.Start();
}

/**
 * Paint event, draws the window.
 * @param event Paint event object
 */
void GameView::OnPaint(wxPaintEvent& event)
{

	auto newTime = mStopWatch.Time();
	auto elapsed = (double)(newTime - mTime) * 0.001;
	mTime = newTime;

	mGame.Update(elapsed, mTime);


	wxAutoBufferedPaintDC dc(this);

	wxBrush background(*wxWHITE);
	dc.SetBackground(background);
	dc.Clear();

	wxFont font(LabelSize,
				wxFONTFAMILY_SWISS,
				wxFONTSTYLE_NORMAL,
				wxFONTWEIGHT_NORMAL);
	dc.SetFont(font);
	dc.SetTextForeground(FontColor);

	dc.DrawText(L"Fixed",  // Text to draw
				50,     // x coordinate for the left size of the text
				ScoreLabelY);    // y coordinate for the top of the text

	dc.DrawText(L"0",  // Text to draw
                90,     // x coordinate for the left size of the text
                ScoreLabelY - 50);    // y coordinate for the top of the text

	dc.DrawText(L"Missed",  // Text to draw
				450,     // x coordinate for the left size of the text
				ScoreLabelY);    // y coordinate for the top of the text

	dc.DrawText(L"0",  // Text to draw
                490,     // x coordinate for the left size of the text
                ScoreLabelY - 50);    // y coordinate for the top of the text

	dc.DrawText(L"Oops",  // Text to draw
				875,     // x coordinate for the left size of the text
				ScoreLabelY);    // y coordinate for the top of the text

	dc.DrawText(L"0",  // Text to draw
                915,     // x coordinate for the left size of the text
                ScoreLabelY - 50);    // y coordinate for the top of the text

	mGame.OnDraw(&dc);

}

/**
 * Handle the left mouse button down event
 * @param event
 */
void GameView::OnLeftDown(wxMouseEvent &event)
{
}

/**
* Handle the left mouse button down event
* @param event
*/
void GameView::OnLeftUp(wxMouseEvent &event)
{
}

/**
* Handle the left mouse double click event
* @param event
*/
void GameView::OnLeftDoubleClick(wxMouseEvent &event)
{
}

/**
 * Handle timer events
 * @param event timer event
 */
void GameView::OnTimer(wxTimerEvent& event)
{
	Refresh();
}

/**
 * File>Open menu handler
 * @param event Menu event
 */
void GameView::OnFileOpen(wxCommandEvent& event)
{
	wxFileDialog loadFileDialog(this, L"Load game level file", L"", L"",
								L"Level Files (*.xml)|*.xml", wxFD_OPEN);
	if (loadFileDialog.ShowModal() == wxID_CANCEL)
	{
		return;
	}

	auto filename = loadFileDialog.GetPath();
	mGame.Load(filename);
	Refresh();

}


