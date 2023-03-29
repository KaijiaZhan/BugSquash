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

	/**
	 * Constructor
	 * @param parent the parent game view
	 * @param code the pointer to the code
	 */
	CodeWindow(wxWindow *parent, std::shared_ptr<Code> code);

	/// Initializes CodeWindow
	void Initialize();

	void OnOk(wxCommandEvent& event);

};

#endif //PROJECT1_GAMELIB_CODEWINDOW_H
