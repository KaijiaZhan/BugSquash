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
void BugCollection::Update(double elapsed)
{

	double angle = atan2(400-GetY(), 500-GetX());
	if (elapsed > mStartTime)
	{
//		SetLocation(GetX() + mSpeedX * (elapsed - mStartTime) * cos(angle),
//					GetY() + mSpeedY * (elapsed - mStartTime) * sin(angle));

	}
	SetLocation(GetX() + mSpeedX * elapsed,
				GetY() + mSpeedY * elapsed);


}

void BugCollection::XmlLoad(wxXmlNode *node)
{
	//Item::XmlLoad(node);

	node->GetAttribute(L"speedx", L"0").ToDouble(&mSpeedX);
	node->GetAttribute(L"speedy", L"0").ToDouble(&mSpeedY);
}

