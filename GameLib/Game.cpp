/**
 * @file Game.cpp
 * @author rmpal
 * @author Courtney Thang
 * @author Kaijia Zhan
 * @author Parker Morgan
 * @author Joanna Rodriguez
 */

#include "pch.h"
#include "Game.h"
#include "Laptop.h"
#include "wx/xml/xml.h"
#include <wx/graphics.h>
#include "RedundancyFly.h"

using namespace std;

/// level start time
const int levelStartDuration = 2;

/// time duration between the when one level is completed and starting the next
const int levelBetweenTime = 3;

/**
* Game Constructor
*/
Game::Game()
{
	LoadLevel(0);
}

/**
 * Set the directory the images are stored in
 * @param dir the directory
 */
void Game::SetImagesDirectory(const std::wstring &dir) {
	mResourcesDirectory = dir;
}

/**
 * Sets the images for all items and caches them
 * @param imageName the name of the image
 * @return a wxImage pointer of the item image
 */
std::shared_ptr<wxImage> Game::SetImage(std::wstring imageName)
{
	auto image = mImage.find(imageName);
	if (image != mImage.end())
	{
		return image->second;
	}
	else
	{
		auto path =  imageName;
		auto newImage = make_shared<wxImage>(path);
		mImage[imageName] = newImage;
		return newImage;
	}
}

/**
 * Draw the game
 * @param graphics Graphics context to draw on
 * @param width The width o the game
 * @param height The height of the game
 */
void Game::OnDraw(std::shared_ptr<wxGraphicsContext> graphics, int width, int height)
{
	//
	// Automatic Scaling
	//
	auto scaleX = double(width) / double(Width);
	auto scaleY = double(height) / double(Height);
	mScale = std::min(scaleX, scaleY);

	if(mShrinked)
	{
		mScale *= ShrinkScale;
	}
	mXOffset = (width - Width * mScale) / 2;
	mYOffset = (height - Height * mScale) / 2;

	graphics->PushState();

	graphics->Translate(mXOffset, mYOffset);
	graphics->Scale(mScale, mScale);

	if(!mShrinked)
	{
		graphics->Clip(0, 0, Game::Width, Game::Height);
	}

	// From here on you are drawing virtual pixels
	graphics->SetBrush(*wxWHITE_BRUSH);
	graphics->DrawRectangle(0,0,Width,Height);


	for (auto item : mItems)
	{
		item->Draw(graphics);
	}
	mScoreBoard.OnDraw(graphics);


	if (mState == State::Start)
	{
		if (mWhatLevel == 0)
		{
			mLevel0.DrawTitle(graphics, Width, Height);
		}
		if (mWhatLevel == 1)
		{
			mLevel1.DrawTitle(graphics, Width, Height);
		}
		if (mWhatLevel == 2)
		{
			mLevel2.DrawTitle(graphics, Width, Height);
		}
		if (mWhatLevel == 3)
		{
			mLevel3.DrawTitle(graphics, Width, Height);
		}
	}

	if (mState == State::End)
	{
		wxFont font(wxSize(0, 130),
					wxFONTFAMILY_SWISS,
					wxFONTSTYLE_NORMAL,
					wxFONTWEIGHT_NORMAL);
		double textwid;
		double textheight;
		std::wstring levelCompleted = L"Level Completed";
		graphics->SetFont(font, *wxRED);
		graphics->GetTextExtent(wxString(levelCompleted), &textwid, &textheight);
		graphics->DrawText(wxString(levelCompleted),
						   (Width-textwid)/2,
						   (Height-textheight)/2);
		if (mWhatLevel == 3)
		{
			mLeaderboard.OnDraw(graphics, width, height);
		}
	}

	graphics->PopState();
}


/**
 * Handle game animation
 * @param elapsed The elapsed time
 * @param totalTime The total time of the game
 */
void Game::Update(double elapsed, long totalTime)
{

	mElapsed += elapsed;
	for (auto item : mItems)
	{
		item->Update(elapsed, mElapsed);
	}
	DeleteItem();

	if (mElapsed < levelStartDuration)
	{
		mState = State::Start;
	}
	if (mLeaderboard.GetActive())
	{
		if (mElapsed >= levelStartDuration && GetBugsLeft() != 0)
		{
			mState = State::Playing;
		}
		if (mState != State::End && GetBugsLeft() == 0)
		{
			mState = State::End;
			int score = mScoreBoard.GetScore();
			mLeaderboard.AssessPlayerScore(score);
		}
	}
	else
	{
		if (GetBugsLeft() == 0)
		{
			if(mState != State::End)
			{
				mState = State::End;
				mLevelEnd = mElapsed;
			}
			else
			{
				if(mElapsed > (levelBetweenTime + mLevelEnd))
				{
					int level = mWhatLevel + 1;
					LoadLevel(level);
				}
			}

		}
		else if (mElapsed >= levelStartDuration)
		{
			mState = State::Playing;
		}

	}

	if (mWhatLevel == 0)
	{
		mLevel0.Update(elapsed);
	}
	else if (mWhatLevel == 1)
	{
		mLevel1.Update(elapsed);
	}
	if (mWhatLevel == 2)
	{
		mLevel2.Update(elapsed);
	}
	if (mWhatLevel == 3)
	{
		mLevel3.Update(elapsed);
	}
	DeleteItem();
}

/**
 * Keeps track of how many bugs are left in the level
 * @return double of how many bugs are left
 */
double Game::GetBugsLeft()
{
	double total = mItems.size();
	for (auto item : mItems)
	{
		if(item->GetSquashed())
		{
			total -= 1;
		}
		if(item->GetType() == "Item")
		{
			total -= 1;
		}
	}
	return total;
}

/**
 * Test an x,y click location to see if it clicked
 * on some item in the game.
 * @param x X location in pixels
 * @param y Y location in pixels
 * @returns Pointer to item we clicked on or nullptr if none.
*/
std::shared_ptr<Item> Game::HitTest(int x, int y)
{
	for (auto i = mItems.rbegin(); i != mItems.rend();  i++)
	{
		if ((*i)->HitTest(x, y))
		{
			return *i;
		}
	}

	return  nullptr;
}

/**
 * Load level that is clicked on in menu bar
 * @param level the level number
 */
void Game::LoadLevel(int level)
{
	Clear();

	mWhatLevel = level;
	if (level == 0)
	{
		mElapsed = 0;
		mLevel0.Clear();
		mLevel0.Load(L"levels/level0.xml", this);
		SetLevel(mLevel0.GetLevel());
		mScoreBoard.Reset();
		mLeaderboard.SetActive(false);
	}
	if (level == 1)
	{
		mElapsed = 0;
		mLevel1.Clear();
		mLevel1.Load(L"levels/level1.xml", this);
		SetLevel(mLevel1.GetLevel());
		mScoreBoard.Reset();
		mLeaderboard.SetActive(false);
	}
	if (level == 2)
	{
		mElapsed = 0;
		mLevel2.Clear();
		mLevel2.Load(L"levels/level2.xml", this);
		SetLevel(mLevel2.GetLevel());
		mScoreBoard.Reset();
		mLeaderboard.SetActive(false);
	}
	if (level == 3)
	{
		mElapsed = 0;
		mLevel3.Clear();
		mLevel3.Load(L"levels/level3.xml", this);
		SetLevel(mLevel3.GetLevel());
		mScoreBoard.Reset();
		mLeaderboard.SetActive(true);

	}

}

/**
 * Clear the game data
 * Deletes all known items in the game
*/
void Game::Clear()
{
	mItems.erase(mItems.begin(), mItems.end());
}

/**
 * Save the game
 * @param filename The filename to save the game to
 */
void Game::Save(const wxString &filename)
{
	wxXmlDocument xmlDoc;

	auto root = new wxXmlNode(wxXML_ELEMENT_NODE, L"game");
	xmlDoc.SetRoot(root);

	for (auto item : mItems)
	{
		item->XmlSave(root);
	}

	if(!xmlDoc.Save(filename, wxXML_NO_INDENTATION))
	{
		wxMessageBox(L"Write to XML failed");
		return;
	}
}


/**
 * Add an item to the game
 * @param item New item to add
 */
void Game::Add(std::shared_ptr<Item> item)
{
    mItems.push_back(item);
}


/**
* Handle a mouse click
* @param x X location clicked on
* @param y Y location clicked on
*/
void Game::OnLeftDown(int x, int y)
{
	double oX = (x - mXOffset) / mScale;
	double oY = (y - mYOffset) / mScale;

	auto item = Game::HitTest(oX, oY);
	if(item != nullptr)
	{
		std::string what_item = item->GetType();
		if (!item->GetSquashed())
		{
			if(what_item == "Bug")
			{
				int add = 1;
				IncreaseFix(add);
			}

			if(what_item == "Feature")
			{
				int add = 1;
				IncreaseOops(add);
			}
			if(what_item == "DoublePointsBug")
			{
				int add = 2;
				IncreaseFix(add);
			}

			item->SingleClick(oX, oY);
			MoveItemFirst(item);
		}
	}

}

/**
 * Moves the item to the front of the mItems vector
 * @param item The item
 */
void Game::MoveItemFirst(std::shared_ptr<Item> item){
	auto loc = find(begin(mItems), end(mItems), item);
	if (loc != end(mItems))
	{
		mItems.erase(loc);
	}
	mItems.insert(mItems.begin(), item);
}

/**
 * Adds to the fixed score
 * @param add The number to add to the fixed score
 */
void Game::IncreaseFix(int add)
{
	double fixed = mScoreBoard.GetFixed();
	fixed += add;
	mScoreBoard.SetFixed(fixed);
}

/**
 * Adds to the oops score
 * @param add The number to add to the oops score
 */
void Game::IncreaseOops(int add)
{
	double oops = mScoreBoard.GetOops();
	oops += add;
	mScoreBoard.SetOops(oops);
}

/**
 * Adds to the missed score
 * @param add The number to add to the missed score
 */
void Game::IncreaseMissed(int add)
{
	double miss = mScoreBoard.GetMissed();
	miss += add;
	mScoreBoard.SetMissed(miss);
}

/**
 * Multiplies the redundancy flies
 * @param fly A fly
 */
void Game::RedundancyFlySplit(RedundancyFly* fly)
{
	// Amount of flies to appear after clicking bug
	int flyMultiplier = rand() % 3 + 3;

	double xPos = fly->GetX();
	double yPos = fly->GetY();


	for (int i = 0; i < flyMultiplier; i++)
	{
		// New fly positions that are +- 200 x/y location from originally clicked bug
		int flyLocationX = xPos + (rand() % 200);
		int flyLocationY = yPos + (rand() % 200);

		auto item = make_shared<RedundancyFly>(this);
		item->SetLocation(flyLocationX,flyLocationY);
		item->SetSpeed(120);
		item->SetStartTime(1);
		item->setInit(false);
		item->SetLaptop(mLaptop);
		Add(item);
	}
}

/**
 * Set the laptop in game
 * @param laptop The laptop
 */
void Game::SetLaptop(std::shared_ptr<Laptop> laptop)
{
	mLaptop = laptop;
}

/**
 * Pushes back items that are o be deleted into vector
 * @param item The items pending delete
 */
void Game::ToDelete(Item* item)
{
	mDeleteItems.push_back(item);
}

/**
 * Delete the to be deleted item from the mItems
 */
void Game::DeleteItem()
{
	for (auto item : mDeleteItems)
	{
		for (auto i = mItems.begin(); i != mItems.end(); i++){
			if (i->get() == item)
			{
				mItems.erase(i);
				break;
			}
		}
	}
	mDeleteItems.clear();
}

/**
 * Implements the double click functionality when the bug is double clicked on
 * @param view The game view
 * @param x The x location
 * @param y The y location
 */
void Game::OnDoubleClick(wxWindow *view, int x, int y)
{
	double oX = (x - mXOffset) / mScale;
	double oY = (y - mYOffset) / mScale;

	auto item = Game::HitTest(oX, oY);

	if (item != nullptr)
	{
		item->DoubleClick(view, oX, oY);
	}

}

