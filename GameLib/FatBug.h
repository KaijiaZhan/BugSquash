/**
 * @file FatBug.h
 * @author Courtney Thang
 * @author Kaijia Joanna Zhan
 * @author Parker Morgan
 * @author Joanna Rodriguez
 *
 * Initialize our fat bug
 */

#ifndef PROJECT1_GAMELIB_FATBUG_H
#define PROJECT1_GAMELIB_FATBUG_H

#include "GameView.h"
#include "BugCollection.h"

class FatBug : public BugCollection
{
private:

	wxXmlNode mFatBugCode;

	std::shared_ptr<Code> mCodeFatBug;

public:
	/// Default constructor (disabled)
	FatBug() = delete;

	/// Copy constructor (disabled)
	FatBug(const FatBug &) = delete;

	/// Assignment operator
	void operator=(const FatBug &) = delete;

	/// Constructor 
	FatBug(Game *game, std::wstring bugType, wxXmlNode *node);

	bool HitTest(int x, int y) override;

	void OpenWindow(int x);

	void DoubleClick(wxWindow * view, int x, int y) override;

	std::string GetType() override {return "FatBug";}

};

#endif //PROJECT1_GAMELIB_FATBUG_H
