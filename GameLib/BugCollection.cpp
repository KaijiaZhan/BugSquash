/**
 * @file BugCollection.cpp
 * @author rmpal
 * @author Flora Pieters
 * @author Courtney Thang
 */

#include "pch.h"
#include "BugCollection.h"

/*
 * Constructor
 */
BugCollection::BugCollection(Game *game, const std::wstring &filename) :
	Item(game, filename)
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

	double angle = atan2(400-GetY(), 500-GetX());
	if (totalTime > mStartTime*1000)
	{
		SetLocation(GetX() + mSpeedX * (elapsed) * cos(angle),
					GetY() + mSpeedY * (elapsed) * sin(angle));

	}



}

void BugCollection::XmlLoad(wxXmlNode *node)
{
	Item::XmlLoad(node);

	node->GetAttribute(L"speedx", L"0").ToDouble(&mSpeedX);
	node->GetAttribute(L"speedy", L"0").ToDouble(&mSpeedY);
}

/**
 * Save the game as a .game XML file.
 *
 * Open an XML file and stream the game data to it.
 *
 * @param filename The filename of the file to save the game to
 */
void BugCollection::Save(const wxString &filename)
{

}
