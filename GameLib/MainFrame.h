/**
 * @file MainFrame.h
 * @author joann
 *
 *
 */

#ifndef PROJECT1_GAMELIB_MAINFRAME_H
#define PROJECT1_GAMELIB_MAINFRAME_H

class GameView;

#include <wx/wx.h>

class MainFrame : public wxFrame
{
private:
	/// View class for our city
	GameView *mGameView;

	void OnExit(wxCommandEvent& event);
	void OnMinimize(wxCommandEvent& event);

public:
	void Initialize();

	void OnAbout(wxCommandEvent& event);

};

#endif //PROJECT1_GAMELIB_MAINFRAME_H
