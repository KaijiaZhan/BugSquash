/**
 * @file GameView.cpp
 * @author joann
 * @author Courtney Thang
 * @author Flora Pieters
 */

#include "pch.h"
#include "GameView.h"
#include "Item.h"
#include "RedundancyFly.h"
#include "Laptop.h"
#include "ids.h"

#include <sstream>
#include <wx/stdpaths.h>
#include <wx/dcbuffer.h>
#include <wx/graphics.h>

using namespace std;


/// Frame duration in milliseconds, this will be changed
const int FrameDuration = 30;

/**
 * Constructor
 * @param parent Pointer to wxFrame object, the main frame for the application
 */
void GameView::Initialize(wxFrame* mainFrame)
{
	Create(mainFrame, wxID_ANY,
		   wxDefaultPosition, wxDefaultSize,
		   wxFULL_REPAINT_ON_RESIZE);
	SetBackgroundColour(*wxBLACK);
	SetBackgroundStyle(wxBG_STYLE_PAINT);

	Bind(wxEVT_PAINT, &GameView::OnPaint, this);

	Bind(wxEVT_LEFT_DOWN, &GameView::OnLeftDown, this);
	Bind(wxEVT_LEFT_UP, &GameView::OnLeftUp, this);
	Bind(wxEVT_LEFT_DCLICK, &GameView::OnLeftDoubleClick, this);
	Bind(wxEVT_TIMER, &GameView::OnTimer, this);
	mainFrame->Bind(wxEVT_COMMAND_MENU_SELECTED, &GameView::OnLevel0, this, IDM_LEVEL0);
	mainFrame->Bind(wxEVT_COMMAND_MENU_SELECTED, &GameView::OnLevel1, this, IDM_LEVEL1);
	mainFrame->Bind(wxEVT_COMMAND_MENU_SELECTED, &GameView::OnLevel2, this, IDM_LEVEL2);
	mainFrame->Bind(wxEVT_COMMAND_MENU_SELECTED, &GameView::OnLevel3, this, IDM_LEVEL3);

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

	// Create a double-buffered display context
	wxAutoBufferedPaintDC dc(this);

	// Clear the image to black
	wxBrush background(*wxBLACK);
	dc.SetBackground(background);
	dc.Clear();

	// Create a graphics context
	auto gc = std::shared_ptr<wxGraphicsContext>(wxGraphicsContext::Create(dc));

	// Tell the game class to draw
	wxRect rect = GetRect();
	mGame.OnDraw(&dc, gc, rect.GetWidth(), rect.GetHeight());

	auto newTime = mStopWatch.Time();
	auto elapsed = (double)(newTime - mTime) * 0.001;
	mTime = newTime;

	mGame.Update(elapsed, mTime);

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

	mGame.OnDraw(&dc, gc, rect.GetWidth(), rect.GetHeight());

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
 * Level>Level 0 menu handler
 * @param event Menu event
 */
void GameView::OnLevel0(wxCommandEvent& event)
{
	mGame.LoadLevel(0);
	Refresh();

}

/**
 * Level>Level 1 menu handler
 * @param event Menu event
 */
void GameView::OnLevel1(wxCommandEvent& event)
{
	mGame.LoadLevel(1);
	Refresh();

}

/**
 * Level>Level 2 menu handler
 * @param event Menu event
 */
void GameView::OnLevel2(wxCommandEvent& event)
{
	mGame.LoadLevel(2);
	Refresh();

}

/**
 * Level>Level 3 menu handler
 * @param event Menu event
 */
void GameView::OnLevel3(wxCommandEvent& event)
{
	mGame.LoadLevel(3);
	Refresh();

}


