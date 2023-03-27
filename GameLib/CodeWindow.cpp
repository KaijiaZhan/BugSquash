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