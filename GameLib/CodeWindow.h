/**
 * @file CodeWindow.h
 * @author Parker Morgan
 * @author Flora Pieters
 *
 */

#include <wx/string.h>

#ifndef PROJECT1_GAMELIB_CODEWINDOW_H
#define PROJECT1_GAMELIB_CODEWINDOW_H

class Code;

/**
 * Class that is our CodeWindow
 */
class CodeWindow: public wxDialog
{
private:
	/// Code displayed on CodeWindow
	std::shared_ptr<Code> mCodeOutput;

	/// Text Control for Code 
	wxTextCtrl *mText = nullptr;

	/// Ok Button for CodeWindow
	wxButton *mButton = nullptr;

public:
	/// Default constructor (disabled)
	CodeWindow() = delete;

	/// Copy constructor (disabled)
	CodeWindow(const CodeWindow &) = delete;

	/// Assignment operator
	void operator=(const CodeWindow &) = delete;

	/// Constructor
	CodeWindow(wxWindow *parent, std::shared_ptr<Code> text);

	/// Initializes CodeWindow
	void Initialize();

	/// Ok Button used to check user Code
	void OnOk(wxCommandEvent& event);

};

#endif //PROJECT1_GAMELIB_CODEWINDOW_H
