/**
 * @file MainFrame.h
 * @author Joanna Rodriguez
 * @author Courtney Thang
 * @author Kaijia Zhan
 *
 * The top-level (main) frame of the application
 */

#ifndef PROJECT1_GAMELIB_MAINFRAME_H
#define PROJECT1_GAMELIB_MAINFRAME_H

#include <wx/wx.h>

class GameView;
class Game;

class MainFrame : public wxFrame
{
private:

	///Command event for when the user wants to exit the game
	void OnExit(wxCommandEvent& event);

	///Command event for when the user wants to read about the game
	void OnAbout(wxCommandEvent& event);

public:
	///creates the frame for our game
	void Initialize();
};

#endif //PROJECT1_GAMELIB_MAINFRAME_H
