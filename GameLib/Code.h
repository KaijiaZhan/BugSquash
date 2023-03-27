/**
 * @file Code.h
 * @author Flora Pieters
 */

#ifndef PROJECT1_CODE_H
#define PROJECT1_CODE_H

#include "Game.h"

class Code {
private:
    wxString mCodeInput;

    wxString mCodeValid;

    Game mGame;


public:
    bool CompareCodes();

    virtual void SetCode(wxString code) { mCodeValid = code; };


};


#endif //PROJECT1_CODE_H
