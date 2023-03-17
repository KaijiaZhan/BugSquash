/**
 * @file Level.cpp
 * @author Courtney Thang
 */

#include "pch.h"
#include "Level.h"
#include "RedundancyFly.h"

using namespace std;

Level::Level()
{

}

/**
 * Load the game level from an XML file.
 *
 * Opens the XML file and reads the nodes, creating items as appropriate.
 *
 * @param filename The filename of the file to load the game level from.
 */
void Level::Load(const wxString &filename, Game * game)
{
	mGame = game;

	wxXmlDocument xmlDoc;
	if(!xmlDoc.Load(filename))
	{
		wxMessageBox(L"Unable to load level file.");
		return;
	}

	auto root = xmlDoc.GetRoot();


	auto child = root->GetChildren();

	for( ; child; child=child->GetNext())
	{
		auto name = child->GetName();
		if(name == L"bug")
		{
			XmlItem(child, game);
		}
	}
}

/**
 * Handle a node of type item.
 * @param node XML node
 */
void Level::XmlItem(wxXmlNode *node, Game * game)
{

	shared_ptr<Item> item;

	auto type = node->GetAttribute(L"type");
	auto xLocation = node->GetAttribute(L"x");
	auto yLocation = node->GetAttribute(L"y");

	if (type == L"redundancy")
	{
		item = make_shared<RedundancyFly>(mGame);
//		item->SetLocation(xLocation, yLocation);
	}


	if (item != nullptr)
	{
		mLevelItems.push_back(item);
		item->XmlLoad(node);
	}
}
