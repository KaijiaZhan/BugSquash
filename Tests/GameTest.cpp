/**
 * @file GameTest.cpp
 * @author joann
 * @author Courtney Thang
 */

#include <pch.h>
#include <Game.h>
#include <RedundancyFly.h>
#include <FatBug.h>
#include <Feature.h>
#include <GarbageBug.h>
#include <NullBug.h>
#include <regex>
#include <string>
#include <fstream>
#include <streambuf>
#include <wx/filename.h>

#include "gtest/gtest.h"

using namespace std;

const unsigned int RandomSeed = 1238197374;

class GameTest : public ::testing::Test
{
protected:
	/**
	 * Create a path to a place to put temporary files
	 */
	 wxString TempPath()
	{
		 // Create a temporary filename we can use
		auto path = wxFileName::GetTempDir() + L"/game";
		if(!wxFileName::DirExists(path))
		{
			wxFileName::Mkdir(path);
		}

		return path;
	}
	/**
	* Read a file into a wstring and return it.
	* @param filename Name of the file to read
	* @return File contents
	*/
	wstring ReadFile(const wxString &filename)
	{
		ifstream t(filename.ToStdString());
		wstring str((istreambuf_iterator<char>(t)),
					istreambuf_iterator<char>());

		return str;
	}

	/**
	* Test to ensure a game level xml file is empty
	*/
	void TestEmpty(wxString filename)
	{
		cout << "Temp file: " << filename << endl;

		auto xml = ReadFile(filename);
		cout << xml << endl;

		ASSERT_TRUE(regex_search(xml, wregex(L"<\\?xml.*\\?>")));
		//not sure if the next like is correct because no aqua files
		ASSERT_TRUE(regex_search(xml, wregex(L"<item/>")));

	}

	/**
	*  Populate a game with three redundancy flies
	*/
	void PopulateThreeFlies(Game *game)
	{
		auto fly1 = make_shared<RedundancyFly>(game);

		/// Add functions have not been made yet, uncomment when Flora makes
		game->Add(fly1);
		fly1->SetLocation(100, 200);

		auto fly2 = make_shared<RedundancyFly>(game);
		game->Add(fly2);
		fly2->SetLocation(400, 400);

		auto fly3 = make_shared<RedundancyFly>(game);
		game->Add(fly3);
		fly3->SetLocation(600, 100);
	}

//	void TestThreeFlies(wxString filename)
//	{
//		cout << "Temp file: " << filename << endl;
//
//		auto xml = ReadFile(filename);
//		cout << xml << endl;
//
//		// Ensure three items
//		/// aqua?
//		//ASSERT_TRUE(regex_search(xml, wregex(L"<aqua><item.*<item.*<item.*</aqua>")));
//
//		// Ensure the positions are correct
//		ASSERT_TRUE(regex_search(xml, wregex(L"<item x=\"100\" y=\"200\"")));
//		ASSERT_TRUE(regex_search(xml, wregex(L"<item x=\"400\" y=\"400\"")));
//		ASSERT_TRUE(regex_search(xml, wregex(L"<item x=\"600\" y=\"100\"")));
//
//		// Ensure the types are correct
//		ASSERT_TRUE(regex_search(xml,
//								 wregex(
//									 L"<aqua><item.* type=\"beta\"/><item.* type=\"beta\"/><item.* type=\"beta\"/></aqua>")));
//	}
};

TEST_F(GameTest, Construct){
	Game game;
}

//TEST_F(BugTest, HitTest) {
////	// Create a bug to test
////	Game game;
////
////	ASSERT_EQ(game.HitTest(100, 200), nullptr) <<
////												   L"Testing empty game";
////
////	shared_ptr <RedundancyFly> bug = make_shared<RedundancyFly>(&game);
////
////	///game.Add(bug); NEEDS ADD FUNCTION
////	bug->SetLocation(100, 200);
////
////	// Center of the bug should be a true
////	ASSERT_TRUE(bug->HitTest(100, 200));
////
////	// Left of the bug
////	ASSERT_FALSE(bug->HitTest(10, 200));
////
////	// Right of the bug
////	ASSERT_FALSE(bug->HitTest(200, 200));
////
////	// Above the bug
////	ASSERT_FALSE(bug->HitTest(100, 0));
////
////	// Below the bug
////	ASSERT_FALSE(bug->HitTest(100, 300));
////
////	// On a bug transparent pixel
////	ASSERT_FALSE(bug->HitTest(100 - 125/2 + 17, 200 - 117/2 + 16));
//}

TEST_F(GameTest, Clear)
{
	// Create a path to temporary files
	auto path = TempPath();

	// Create a game
	Game game;

	// Populate it
	PopulateThreeFlies(&game);

	// Clear the items in the game
	game.Clear();

	// First test, saving an empty game
	auto file1 = path + L"/test1.item";

	// Save the file
	game.Save(file1);

	// Test to see if it is empty
	TestEmpty(file1);

}

//TEST_F(GameTest, Load)
//{
//	auto path = TempPath();
//
//	Game game;
//	game.GetRandom().seed(RandomSeed);
//	Game game2;
//	game2.GetRandom().seed(RandomSeed);
//
//	auto file1 = path + L"/test1.game";
//	game.Save(file1);
//
//	TestEmpty(file1);
//
//	game2.Load(file1);
//	game2.Save(file1);
//	TestEmpty(file1);
//
//	PopulateThreeFlies(&game);
//
//	auto file2 = path + L"/test2.game";
//	game.Save(file2);
//
//	///TestThreeFlies(file2);
//
//	//Need to test all types once we populate all types of bugs
//}
