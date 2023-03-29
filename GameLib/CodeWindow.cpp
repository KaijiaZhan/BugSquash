/**
 * @file CodeWindow.cpp
 * @author Parker Morgan
 * @author Flora Pieters
 */

#include "pch.h"
#include "CodeWindow.h"
#include "Code.h"
#include <string>

using namespace std;

/**
 * Constructor
 * @param parent the window
 * @param code the code from the xml
 */
CodeWindow::CodeWindow(wxWindow *parent, shared_ptr<Code> code) :
	wxDialog(parent, wxID_ANY, L"Bug Squash IDE", wxDefaultPosition, wxSize(600, 600), wxDEFAULT_DIALOG_STYLE)
{
	mCodeOutput = code;
	Initialize();
}

/**
 * Initialize the dialog box.
 */
void CodeWindow::Initialize()
{
	this->SetSizeHints(wxDefaultSize, wxDefaultSize);
	auto sizer = new wxBoxSizer( wxVERTICAL );
	mText = new wxTextCtrl(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE);
	mText->AppendText(mCodeOutput->GetCodeInput());
	sizer->Add(mText, 1, wxALIGN_LEFT | wxALL | wxEXPAND, 6);
	mButton = new wxButton(this, wxID_ANY,L"OK", wxDefaultPosition, wxDefaultSize, 0);
	sizer->Add(mButton, 1, wxALIGN_CENTER_HORIZONTAL | wxALL, 6);
	this->SetSizer(sizer);
	this->Layout();
	mButton->Bind(wxEVT_BUTTON, &CodeWindow::OnOk, this);

}

/**
 * Ok menu option handler
 * @param event button event
 */
void CodeWindow::OnOk(wxCommandEvent& event)
{
	mCodeOutput->SetCode(mText->GetValue().ToStdWstring());
	Close();
}
