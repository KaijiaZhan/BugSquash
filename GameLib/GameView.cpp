/**
 * @file GameView.cpp
 * @author Joanna Rodriguez
 * @author Courtney Thang
 * @author Flora Pieters
 * @author Kaijia Zhan
 */

#include "pch.h"
#include "GameView.h"
#include "Item.h"
#include "RedundancyFly.h"
#include "Laptop.h"
#include "ids.h"
#include "Code.h"

#include <sstream>
#include <wx/stdpaths.h>
#include <wx/dcbuffer.h>
#include <wx/graphics.h>

using namespace std;


/// Frame duration in milliseconds, this will be changed
const int FrameDuration = 30;

/**
 * Initializing game view
 * @param mainFrame
 */
void GameView::Initialize(wxFrame* mainFrame)
{
	Create(mainFrame, wxID_ANY,
		   wxDefaultPosition, wxDefaultSize,
		   wxFULL_REPAINT_ON_RESIZE);
	SetBackgroundColour(*wxBLACK);
	SetBackgroundStyle(wxBG_STYLE_PAINT);

	wxStandardPaths& standardPaths = wxStandardPaths::Get();
	std::wstring resourcesDir = standardPaths.GetResourcesDir().ToStdWstring();
	mGame.SetImagesDirectory(resourcesDir);

	Bind(wxEVT_PAINT, &GameView::OnPaint, this);

	Bind(wxEVT_LEFT_DOWN, &GameView::OnLeftDown, this);
	Bind(wxEVT_LEFT_DCLICK, &GameView::OnMouseDoubleClick, this);
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
	mGame.OnDraw(gc, rect.GetWidth(), rect.GetHeight());

	if (mFrozen)
	{
		mFrozenElapsed = mStopWatch.Time() - mTime;
	}
	else
	{
		auto newTime = mStopWatch.Time();
		auto elapsed = (double)(newTime - mTime - mFrozenElapsed) * 0.001;
		mTime = newTime;

		mGame.Update(elapsed, mTime);
		mFrozenElapsed = 0;
	}

	mGame.OnDraw(gc, rect.GetWidth(), rect.GetHeight());

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
}

/**
 * Level>Level 1 menu handler
 * @param event Menu event
 */
void GameView::OnLevel1(wxCommandEvent& event)
{
	mGame.LoadLevel(1);
}

/**
 * Level>Level 2 menu handler
 * @param event Menu event
 */
void GameView::OnLevel2(wxCommandEvent& event)
{
	mGame.LoadLevel(2);
}

/**
 * Level>Level 3 menu handler
 * @param event Menu event
 */
void GameView::OnLevel3(wxCommandEvent& event)
{
	mGame.LoadLevel(3);

}

/**
 * Shrink function
 * @param event Menu event
 */
void GameView::OnShrink(wxCommandEvent& event)
{
	bool shrink = mGame.GetShrink();
	mGame.SetShrink(!shrink);
	wxWindow::Refresh();
}

/**
 * Updates the shrink
 * @param event Update UI event
 */
void GameView::OnShrinkUpdate(wxUpdateUIEvent& event)
{
	event.Check(mGame.GetShrink());
}

/**
 * Handle a left-mouse double-click event
 * @param event Mouse event
 */
void GameView::OnMouseDoubleClick(wxMouseEvent& event)
{
	mFrozen = true;
	mGame.OnDoubleClick(this, event.GetX(), event.GetY());
	mFrozen = false;
}

/**
 * Handle the left mouse button down event
 * @param event The mouse click event
 */
void GameView::OnLeftDown(wxMouseEvent &event)
{
	mGame.OnLeftDown(event.GetX(), event.GetY());
}

