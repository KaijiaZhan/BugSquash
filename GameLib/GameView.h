/**
 * @file GameView.h
 * @author Joanna Rodriguez
 * @author Courtney Thang
 * @author Kaijia Zhan
 *
 * Creates the game view of our game
 */

#ifndef PROJECT1_GAMELIB_GAMEVIEW_H
#define PROJECT1_GAMELIB_GAMEVIEW_H

#include <wx/wx.h>
#include "Game.h"
#include "ScoreBoard.h"
#include "CodeWindow.h"
#include <wx/string.h>

/**
 * Create the game view of our game derived from wxWindow
 */
class GameView : public wxWindow {
private:
	void OnTimer(wxTimerEvent& event);
	void OnLevel0(wxCommandEvent& event);
	void OnLevel1(wxCommandEvent& event);
	void OnLevel2(wxCommandEvent& event);
	void OnLevel3(wxCommandEvent& event);
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

	/// Boolean to check if game is frozen
	bool mFrozen = false;

	/// The elapsed froze
	long mFrozenElapsed = 0;

public:
	void Initialize(wxFrame *mainFrame);

	void OnShrink(wxCommandEvent& event);

	void OnShrinkUpdate(wxUpdateUIEvent& event);

	void OnMouseDoubleClick(wxMouseEvent& event);

	void OnLeftDown(wxMouseEvent& event);

	/**
	 * Sets the freeze boolean to pause the game
	 * @param freeze The boolean that pauses the game
	 */
	void SetFrozen(bool freeze) { mFrozen = freeze; };
};

#endif //PROJECT1_GAMELIB_GAMEVIEW_H
