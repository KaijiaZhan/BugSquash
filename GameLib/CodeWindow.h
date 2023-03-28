/**
 * @file CodeWindow.h
 * @author Parker Morgan
 * @author Flora Pieters
 *
 */

#include <wx/string.h>

#ifndef PROJECT1_GAMELIB_CODEWINDOW_H
#define PROJECT1_GAMELIB_CODEWINDOW_H

/**
 * Class that is our CodeWindow
 */
class CodeWindow: public wxDialog
{
private:
	wxString mCodeOutput;

    wxTextCtrl *mText = nullptr;

public:
	/// Default constructor (disabled)
	CodeWindow() = delete;

	/// Copy constructor (disabled)
	CodeWindow(const CodeWindow &) = delete;

	/// Assignment operator
	void operator=(const CodeWindow &) = delete;

	CodeWindow(wxWindow *parent, const wxString &title, const wxString &code);

	void Initialize();

    void OnClose(wxCloseEvent& event);

    void OnOk(wxCommandEvent& event);

};

#endif //PROJECT1_GAMELIB_CODEWINDOW_H
