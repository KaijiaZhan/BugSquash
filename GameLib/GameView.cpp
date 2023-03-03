/**
 * @file GameView.cpp
 * @author joann
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
 * @param mainFrame Pointer to wxFrame object, the main frame for the application
 */
void GameView::Initialize(wxFrame* mainFrame)
{
	Create(mainFrame, wxID_ANY);

	// Determine where the images are stored
	//auto standardPaths = wxStandardPaths::Get();
	wxStandardPaths& standardPaths = wxStandardPaths::Get();
	std::wstring resourcesDir = standardPaths.GetResourcesDir().ToStdWstring();

	SetBackgroundStyle(wxBG_STYLE_PAINT);

	Bind(wxEVT_PAINT, &GameView::OnPaint, this);
	Bind(wxEVT_LEFT_DOWN, &GameView::OnLeftDown, this);
	Bind(wxEVT_LEFT_UP, &GameView::OnLeftUp, this);
	Bind(wxEVT_TIMER, &GameView::OnTimer, this);


	mTimer.SetOwner(this);
	mTimer.Start(FrameDuration);
	mStopWatch.Start();
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
 * Handle timer events
 * @param event timer event
 */
void GameView::OnTimer(wxTimerEvent& event)
{
	Refresh();
}