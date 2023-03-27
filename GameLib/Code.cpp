/**
 * @file Code.cpp
 * @author Flora Pieters
 */

#include "pch.h"
#include <wx/string.h>
#include "Code.h"
#include "Game.h"
#include "GameView.h"


bool Code::CompareCodes()
{
    return mCodeInput == mCodeValid;
}

