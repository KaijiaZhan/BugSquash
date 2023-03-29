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


public:
    /// Default constructor (disabled)
    Code() = default;

    Code(wxXmlNode *pNode);

    /// Copy constructor (disabled)
    Code(const Code &) = delete;

    /// Assignment operator
    void operator=(const Code &) = delete;
    
    bool CompareCodes();

    virtual void SetCode(wxString code) { mCodeValid = code; };

    wxString GetCodeValid() { return mCodeValid; };

    wxString GetCodeInput() { return mCodeInput; };


};


#endif //PROJECT1_CODE_H
