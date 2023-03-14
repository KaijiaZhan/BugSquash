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
//BugCollection::BugCollection(Game *pGame) {
//
//}



void BugCollection::XmlLoad(wxXmlNode *node)
{
	//Item::XmlLoad(node);

	node->GetAttribute(L"speedx", L"0").ToDouble(&mSpeedX);
	node->GetAttribute(L"speedy", L"0").ToDouble(&mSpeedY);
}

