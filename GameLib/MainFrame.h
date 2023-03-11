/**
 * @file MainFrame.h
 * @author joann
 * @author Courtney Thang
 *
 * The top-level (main) frame of the application
 */

#ifndef PROJECT1_GAMELIB_MAINFRAME_H
#define PROJECT1_GAMELIB_MAINFRAME_H

class GameView;

#include <wx/wx.h>

/**
* The top-level (main) frame of the application
*/
class MainFrame : public wxFrame
{
private:
	/// View class for our city
	GameView *mGameView;

	///Command event for when the user wants to exit the game
	void OnExit(wxCommandEvent& event);

	///Command event for when the user presses the minimize, as doing so, we must show the bugs position before
		///they appear on the main window, do we need this?
	void OnMinimize(wxCommandEvent& event);

public:
	///creates the frame for our game
	void Initialize();

	void OnAbout(wxCommandEvent& event);

};

#endif //PROJECT1_GAMELIB_MAINFRAME_H
