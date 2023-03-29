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

bool Code::CompareCodes()
{
	return wxRegEx(mPass, wxRE_NEWLINE).Matches(mCodeValid);
}

Code::Code(wxXmlNode *codeTag) {
	mPass = codeTag->GetAttribute("pass");
	mCodeInput = codeTag->GetNodeContent();
}

