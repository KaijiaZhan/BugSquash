/**
 * @file BugCollection.cpp
 * @author Rossi Palomba
 * @author Flora Pieters
 * @author Courtney Thang
 */

#include "pch.h"
#include "BugCollection.h"

/*
 * Constructor
 */
BugCollection::BugCollection(Game *game, const std::wstring &filename) :
	Item(game)
{

}

/**
 * Handle updates in time of our bug
 *
 * This is called before we draw and allows us to
 * move our bug. We add our speed times the amount
 * of time that has elapsed.
 * @param elapsed Time elapsed since the class call
 */
void BugCollection::Update(double elapsed, long totalTime)
{

	double angle = atan2(500-GetY(), 625-GetX());
	if (totalTime >= GetStartTime())
	{
		SetLocation(GetX() + mSpeedX * (elapsed) * cos(angle),
					GetY() + mSpeedY * (elapsed) * sin(angle));

	}

	if(625 - GetX() < 50 && 500 - GetY() < 50)
	{
		SetDel(true);
	}

}

/**
 * Load the attributes for an item node.
 *
 * This is the  base class version that loads the attributes
 * common to all items. Override this to load custom attributes
 * for specific items.
 *
 * @param node The Xml node we are loading the item from
 */
void BugCollection::XmlLoad(wxXmlNode *node)
{
	Item::XmlLoad(node);

//	node->GetAttribute(L"speedx", L"0").ToDouble(&mSpeedX);
//	node->GetAttribute(L"speedy", L"0").ToDouble(&mSpeedY);
}
