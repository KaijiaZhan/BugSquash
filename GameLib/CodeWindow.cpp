/**
 * @file CodeWindow.cpp
 * @author Parker Morgan
 */

#include "pch.h"
#include "CodeWindow.h"

#include <string>

using namespace std;

CodeWindow::CodeWindow(wxWindow *parent, const wxString &title, const wxString &code) :
wxDialog(parent, -1, title)
{
	mCode = code;
}

/**
 * Initialize the Dialog.
 */
void CodeWindow::Initialize()
{
    Create(nullptr,wxID_ANY, L"Bug Squash IDE",wxDefaultPosition, wxSize(600,600 ));
    auto sizer = new wxBoxSizer( wxVERTICAL );
    mText = new wxTextCtrl(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(20,20), wxTE_MULTILINE);
    sizer->Add(mText, 1, wxALIGN_CENTER, 6);
    SetSizerAndFit(sizer);
    Layout();

    Bind(wxEVT_CLOSE_WINDOW, &CodeWindow::OnClose, this);
    auto okbutton = new wxButton(this, wxID_ANY,L"Ok", wxPoint(200, 300));
    okbutton->Bind(wxEVT_BUTTON, &CodeWindow::OnOk, this);

}

/**
 * Close menu option handlers
 * @param event
 */
void CodeWindow::OnClose(wxCloseEvent& event)
{

}

/**
 * Ok menu option handler
 * @param event
 */
void CodeWindow::OnOk(wxCommandEvent& event)
{

}
