/**
 * @file Code.h
 * @author Flora Pieters
 *
 * Class for the code loaded from the xml
 */

#ifndef PROJECT1_CODE_H
#define PROJECT1_CODE_H

#include "Game.h"

/**
 * Class for the code loaded from the xml
 */
class Code
{
private:

	/// The code from the xml file that needs to be fixed by user
	wxString mCodeInput;

	/// Finalized user input code
	wxString mCodeValid;

	/// The regular expression from xml file tha will determine correct Code
	wxString mPass;


public:
    /// Default constructor (disabled)
    Code() = default;

    /// Constructor
    Code(wxXmlNode *pNode);

    /// Copy constructor (disabled)
    Code(const Code &) = delete;

    /// Assignment operator
    void operator=(const Code &) = delete;
    
    /// Determines if Code is valid based on regular expression
    bool CompareCodes();

	/**
	 * Set the user code
	 * @param code the code inputted
	 */
    virtual void SetCode(wxString code) { mCodeValid = code; };

    /// Getter for mCodeValid
    wxString GetCodeValid() { return mCodeValid; };

    /// Getter for mCodeInput
    wxString GetCodeInput() { return mCodeInput; };


};


#endif //PROJECT1_CODE_H
