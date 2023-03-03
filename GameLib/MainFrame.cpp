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
	mGameView = new GameView();
	mGameView->Initialize(this);

}

/**
 * Exit menu option handlers
 * @param event
 */
void MainFrame::OnExit(wxCommandEvent& event)
{
	Close(true);
}

void OnMinimize(wxCommandEvent& event)
{
}