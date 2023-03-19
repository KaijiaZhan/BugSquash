/**
 * @file Level.cpp
 * @author Courtney Thang
 */

#include "pch.h"
#include "Level.h"
#include "RedundancyFly.h"
#include "GarbageBug.h"
#include "Laptop.h"

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

	auto rootName = root->GetName();

	auto firstChild = root->GetChildren();

	auto child = firstChild->GetChildren();

	shared_ptr<Item> laptop = make_shared<Laptop>(game);
	mLevelItems.push_back(laptop);

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

	double x;
	double y;
	node->GetAttribute(L"x").ToDouble(&x);
	node->GetAttribute(L"y").ToDouble(&y);

	double speed;
	node->GetAttribute(L"speed").ToDouble(&speed);

	if (type == L"redundancy")
	{
		item = make_shared<RedundancyFly>(mGame);
		item->SetLocation(x,y);
		item->SetSpeed(speed);
	}
	if (type == L"garbage")
	{
		item = make_shared<GarbageBug>(mGame);
		item->SetLocation(x,y);
		item->SetSpeed(speed);
	}
	if (item != nullptr)
	{
		mLevelItems.push_back(item);
		item->XmlLoad(node);
	}
}

