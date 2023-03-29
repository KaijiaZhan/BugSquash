/**
 * @file Code.h
 * @author Flora Pieters
 *
 * Class for the code loaded from the xml
 */

#ifndef PROJECT1_CODE_H
#define PROJECT1_CODE_H

#include "Game.h"

class Code {
private:

	/// the code to fix from xml
	wxString mCodeInput;

	/// finalized user input code
	wxString mCodeValid;

	/// the correct code needed to pass from xml
	wxString mPass;


public:
    /// Default constructor (disabled)
    Code() = default;

    Code(wxXmlNode *pNode);

    /// Copy constructor (disabled)
    Code(const Code &) = delete;

    /// Assignment operator
    void operator=(const Code &) = delete;
    
    bool CompareCodes();

	/**
	 * Set the user code
	 * @param code the code inputted
	 */
    virtual void SetCode(wxString code) { mCodeValid = code; };

    wxString GetCodeInput() { return mCodeInput; };


};


#endif //PROJECT1_CODE_H
