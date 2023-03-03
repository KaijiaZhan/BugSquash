/**
 * @file GameView.h
 * @author joann
 *
 *
 */

#ifndef PROJECT1_GAMELIB_GAMEVIEW_H
#define PROJECT1_GAMELIB_GAMEVIEW_H

#include <wx/wx.h>
#include "Game.h"


class GameView : public wxWindow {
private:
	void OnTimer(wxTimerEvent& event);
	void OnLeftDown(wxMouseEvent &event);
	void OnLeftUp(wxMouseEvent& event);

	/// the game
	Game mGame;

	/// Any item we are currently dragging
	std::shared_ptr<Item> mGrabbedItem;

	/// The timer that allows for animation
	wxTimer mTimer;

	/// Stopwatch used to measure elapsed time
	wxStopWatch mStopWatch;

	/// The last stopwatch time
	long mTime = 0;

public:
	void Initialize(wxFrame *mainFrame);

	void Stop() {mTimer.Stop();}

};

#endif //PROJECT1_GAMELIB_GAMEVIEW_H
