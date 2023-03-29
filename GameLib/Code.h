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

    /**
     * Constructor
     * @param pNode the node for the code
     */
    Code(wxXmlNode *pNode);

    /// Copy constructor (disabled)
    Code(const Code &) = delete;

    /// Assignment operator
    void operator=(const Code &) = delete;
    
    /**
     * Compares the input code with the correct answer
     * @return a boolean to indicate if they match
     */
    bool CompareCodes();

	/**
	 * Set the user code
	 * @param code the code inputted
	 */
    virtual void SetCode(wxString code) { mCodeValid = code; };

    /**
     * Getter to get the input code
     * @return mCodeInput the input code
     */
    wxString GetCodeInput() { return mCodeInput; };


};


#endif //PROJECT1_CODE_H
