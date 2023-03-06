/**
 * @file MainFrame.cpp
 * @author joann
 */

#include "pch.h"
#include "MainFrame.h"

#include "GameView.h"

/**
 * Initialize the MainFrame window.
 */
void MainFrame::Initialize()
{
	//Creates the frame
	Create(nullptr,wxID_ANY, L"Project1",wxDefaultPosition, wxSize( 1000,800 ));

	// Create a sizer that will lay out child windows vertically
	// one above each other
//	auto sizer = new wxBoxSizer( wxVERTICAL );
//
//	// Create the view class object as a child of MainFrame
//	mGameView = new GameView();
//	mGameView->Initialize(this);

//
//	// Add it to the sizer
//	sizer->Add(mGameView,1, wxEXPAND | wxALL );
//
//	// Set the sizer for this frame
//	SetSizer( sizer );
//
//	auto menuBar = new wxMenuBar( );
//
//	auto fileMenu = new wxMenu();
//	auto helpMenu = new wxMenu();
//
//	// Bug menu option is to test if populating the bugs work to see if they draw
//	auto bugMenu = new wxMenu();
//
//	menuBar->Append(fileMenu, L"&File" );
//
//	// Delete bugMenu when done testing populating bugs
//	menuBar->Append(bugMenu, L"&Add Bug");
//	menuBar->Append(helpMenu, L"&Help");
//
//	fileMenu->Append(wxID_EXIT, "E&xit\tAlt-X", "Quit this program");
//	helpMenu->Append(wxID_ABOUT, "&About\tF1", "Show about dialog");
//
//	SetMenuBar( menuBar );
//
//	CreateStatusBar( 1, wxSTB_SIZEGRIP, wxID_ANY );
//
//	Bind(wxEVT_COMMAND_MENU_SELECTED, &MainFrame::OnExit, this, wxID_EXIT);
//	Bind(wxEVT_COMMAND_MENU_SELECTED, &MainFrame::OnAbout, this, wxID_ABOUT);
//
//	//Layout (place) the child windows
//	Layout();

}

/**
 * Exit menu option handlers
 * @param event
 */
void MainFrame::OnExit(wxCommandEvent& event)
{
	Close(true);
}


//do we need this?
void OnMinimize(wxCommandEvent& event)
{
}

/**
 * About menu option handler
 * @param event
 */
void MainFrame::OnAbout(wxCommandEvent& event)
{
	wxMessageBox(L"Welcome to BugSquash! Squash all the bugs before they reach your program!",
				 L"About Aquarium",
				 wxOK,
				 this);
}