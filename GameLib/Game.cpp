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

using namespace std;

/**
* Game Constructor
*/
Game::Game()
{
	// Create a new laptop.
	// This creates a shared pointer pointing at this laptop
//	shared_ptr<Item> laptop = make_shared<Laptop>(this);

//	//temp
//	shared_ptr<Item> rfly = make_shared<RedundancyFly>(this);
//
//	// Set the location
//	laptop->SetLocation(500, 400);
//
//	//temp
//	rfly->SetLocation(200, 100);

	// Add to the list of laptop.
//	mItems.push_back(laptop);

	//temp
//	mItems.push_back(rfly);

}

/**
 * Draw the game
 * @param dc The device context to draw on
 */
void Game::OnDraw(wxDC *dc)
{
//	//
//	// Automatic Scaling
//	//
//	auto scaleX = double(width) / double(Width);
//	auto scaleY = double(height) / double(Height);
//	mScale = std::min(scaleX, scaleY);
//
//	if(mShrinked)
//	{
//		mScale *= ShrinkScale;
//	}
//
//	mXOffset = (width - Width * mScale) / 2;
//	mYOffset = (height - Height * mScale) / 2;
//
//	graphics->PushState();
//
//	graphics->Translate(mXOffset, mYOffset);
//	graphics->Scale(mScale, mScale);
//
//	// From here on you are drawing virtual pixels
//
//	//
//	// Your drawing code goes here
//	//
//
//	graphics->PopState();

	for (auto item : mItems)
	{
		item->Draw(dc);
	}
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
 * Load the game level from an XML file.
 *
 * Opens the XML file and reads the nodes, creating items as appropriate.
 *
 * @param filename The filename of the file to load the game level from.
 */
void Game::Load(const wxString &filename)
{
	wxXmlDocument xmlDoc;
	if(!xmlDoc.Load(filename))
	{
		wxMessageBox(L"Unable to load level file.");
		return;
	}

	Clear();

	auto root = xmlDoc.GetRoot();

	auto child = root->GetChildren();

	for( ; child; child=child->GetNext())
	{
		auto name = child->GetName();
		if(name == L"item")
		{
			 XmlItem(child);
		}
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
 * Handle a node of type item.
 * @param node XML node
 */
void Game::XmlItem(wxXmlNode *node)
{
	shared_ptr<Item> item;

	auto type = node->GetAttribute(L"type");

	if (type == L"redundancyfly")
	{
		item = make_shared<RedundancyFly>(this);
	}

	if (item != nullptr)
	{
		Add(item);
		item->XmlLoad(node);
	}
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
