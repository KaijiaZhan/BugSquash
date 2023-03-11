/**
 * @file GameView.h
 * @author joann
 * @author Courtney Thang
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

	void OnPaint(wxPaintEvent& event);

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

	/// Score font size to use
	const int ScoreSize = 85;

/// Lable for score font size to use
	const int LabelSize = 40;

/// The font color to use
	const wxColour FontColor = wxColour(0, 200, 200);

/// Left score X location. The right score is
/// the width minus this value.
	const int LeftScoreX = 150;

/// Score Y location
	const int ScoreY = 20;

/// Score label Y location
	const int ScoreLabelY = 100;

public:
	void Initialize(wxFrame *mainFrame);

	void Stop() {mTimer.Stop();}

};

#endif //PROJECT1_GAMELIB_GAMEVIEW_H
