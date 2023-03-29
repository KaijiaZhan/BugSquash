/**
 * @file Code.cpp
 * @author Flora Pieters
 */

#include "pch.h"
#include "Code.h"
#include "Game.h"
#include "GameView.h"

#include <wx/string.h>
#include <wx/regex.h>

/*
 * Determines if code is valid based on mPass
 */
bool Code::CompareCodes()
{
	return wxRegEx(mPass, wxRE_NEWLINE).Matches(mCodeValid);
}

/*
 * Constructor
 */
Code::Code(wxXmlNode *codeTag) 
{
	mPass = codeTag->GetAttribute("pass");
	mCodeInput = codeTag->GetNodeContent();
}

