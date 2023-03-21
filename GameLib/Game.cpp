/**
 * @file Game.cpp
 * @author rmpal
 * @author Courtney Thang
 * @author Kaijia Joanna Zhan
 * @author Parker Morgan
 */

#include "pch.h"
#include "Game.h"
#include "Laptop.h"
#include "Feature.h"
#include "RedundancyFly.h"
#include "wx/xml/xml.h"
#include <wx/graphics.h>


using namespace std;

/**
* Game Constructor
*/
Game::Game()
{
	mLevel0.Load(L"levels/level0.xml", this);
	mLevel1.Load(L"levels/level1.xml", this);
	mLevel2.Load(L"levels/level2.xml", this);
	mLevel3.Load(L"levels/level3.xml", this);

	LoadLevel(0);

}

/**
 * Draw the game
 * @param dc The device context to draw on
 */
void Game::OnDraw(wxDC *dc, std::shared_ptr<wxGraphicsContext> graphics, int width, int height)
{
	//
	// Automatic Scaling
	//
	auto scaleX = double(width) / double(Width);
	auto scaleY = double(height) / double(Height);
	mScale = std::min(scaleX, scaleY);

	if(mShrinked)
	{
		mScale *= ShrinkScale;
	}
	mXOffset = (width - Width * mScale) / 2;
	mYOffset = (height - Height * mScale) / 2;

	graphics->PushState();

	graphics->Translate(mXOffset, mYOffset);
	graphics->Scale(mScale, mScale);

	if(!mShrinked)
	{
		graphics->Clip(0, 0, Game::Width, Game::Height);
	}

	// From here on you are drawing virtual pixels
	graphics->SetBrush(*wxWHITE_BRUSH);
	graphics->DrawRectangle(0,0,Width,Height);

	for (auto item : mItems)
	{
		item->Draw(graphics);
	}
	// need to draw white rectangle, items, then scoreboard

	wxFont font(LabelSize,
				wxFONTFAMILY_SWISS,
				wxFONTSTYLE_NORMAL,
				wxFONTWEIGHT_NORMAL);
	graphics->SetFont(font, wxColour(0,200,200));
	//graphics->SetTextForeground(FontColor);

	graphics->DrawText(L"Fixed",  // Text to draw
				50,     // x coordinate for the left size of the text
				ScoreLabelY);    // y coordinate for the top of the text

	graphics->DrawText(L"0",  // Text to draw
				90,     // x coordinate for the left size of the text
				ScoreLabelY - 50);    // y coordinate for the top of the text

	graphics->DrawText(L"Missed",  // Text to draw
				450,     // x coordinate for the left size of the text
				ScoreLabelY);    // y coordinate for the top of the text

	graphics->DrawText(L"0",  // Text to draw
				490,     // x coordinate for the left size of the text
				ScoreLabelY - 50);    // y coordinate for the top of the text

	graphics->DrawText(L"Oops",  // Text to draw
				875,     // x coordinate for the left size of the text
				ScoreLabelY);    // y coordinate for the top of the text

	graphics->DrawText(L"0",  // Text to draw
				915,     // x coordinate for the left size of the text
				ScoreLabelY - 50);    // y coordinate for the top of the text

				// need laptop and bug scaled
	graphics->PopState();
}


/**
 * Handle updates for animation
 * @param elapsed The time since the last update
 */
void Game::Update(double elapsed, long totalTime)
{
	for (auto item : mItems)
	{
		item->Update(elapsed, totalTime);
		if (item->GetDel())
		{
//			auto loc = find(begin(mItems), end(mItems), item);
//			if (loc != end(mItems))
//			{
//				mItems.erase(loc);
//			}
			item->SetLocation(-1000,-1000);
			item->SetSpeed(0);
		}
	}
}

/**
 * Test an x,y click location to see if it clicked
 * on some item in the game.
 * @param x X location in pixels
 * @param y Y location in pixels
 * @returns Pointer to item we clicked on or nullptr if none.
*/
std::shared_ptr<Item> Game::HitTest(int x, int y)
{
	for (auto i = mItems.rbegin(); i != mItems.rend();  i++)
	{
		if ((*i)->HitTest(x, y))
		{
			return *i;
		}
	}

	return  nullptr;
}

/**
 * Load level
 * @param level the level number
 */
void Game::LoadLevel(int level)
{
	Clear();

	if (level == 0)
	{
		SetLevel(mLevel0.GetLevel());
	}
	if (level == 1)
	{
		SetLevel(mLevel1.GetLevel());
	}
	if (level == 2)
	{
		SetLevel(mLevel2.GetLevel());
	}
	if (level == 3)
	{
		SetLevel(mLevel3.GetLevel());
	}

}

/**
 * Clear the game data
 * Deletes all known items in the game
*/
void Game::Clear()
{
	mItems.erase(mItems.begin(), mItems.end());
}

/**
* @param filename The filename of the file to save the game to
*/
void Game::Save(const wxString &filename)
{
	wxXmlDocument xmlDoc;

	auto root = new wxXmlNode(wxXML_ELEMENT_NODE, L"game");
	xmlDoc.SetRoot(root);

	for (auto item : mItems)
	{
		item->XmlSave(root);
	}

	if(!xmlDoc.Save(filename, wxXML_NO_INDENTATION))
	{
		wxMessageBox(L"Write to XML failed");
		return;
	}
}


/**
 * Add an item to the game
 * @param item New item to add
 */
void Game::Add(std::shared_ptr<Item> item)
{
//    auto nextBug = 50;
//    item->SetLocation(10, 10);
//
//    for (auto bugs : mItems)
//    {
//        for (auto bug : mItems)
//        {
//            item->SetLocation(item->GetX() + nextBug, item->GetY() + nextBug);
//        }
//    }
    mItems.push_back(item);
}

/**
* Handle a mouse click
* @param x X location clicked on
* @param y Y location clicked on
*/
void Game::OnLeftDown(int x, int y)
{
	double oX = (x - mXOffset) / mScale;
	double oY = (y - mYOffset) / mScale;
}
