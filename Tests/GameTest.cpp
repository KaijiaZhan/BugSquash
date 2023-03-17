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
		ASSERT_TRUE(regex_search(xml, wregex(L"<game/>")));

	}

	/**
	*  Populate a game with three redundancy flies
	*/
	void PopulateThreeFlies(Game *game)
	{
		game->GetRandom().seed(RandomSeed);

		auto fly1 = make_shared<RedundancyFly>(game);
		game->Add(fly1);
		fly1->SetLocation(100, 200);

		auto fly2 = make_shared<RedundancyFly>(game);
		game->Add(fly2);
		fly2->SetLocation(400, 400);

		auto fly3 = make_shared<RedundancyFly>(game);
		game->Add(fly3);
		fly3->SetLocation(600, 100);
	}

	void TestThreeFlies(wxString filename)
	{
		cout << "Temp file: " << filename << endl;

		auto xml = ReadFile(filename);
		cout << xml << endl;

		// Ensure three items
		ASSERT_TRUE(regex_search(xml, wregex(L"<game><item.*<item.*<item.*</game>")));

		// Ensure the positions are correct
		ASSERT_TRUE(regex_search(xml, wregex(L"<item x=\"100\" y=\"200\"")));
		ASSERT_TRUE(regex_search(xml, wregex(L"<item x=\"400\" y=\"400\"")));
		ASSERT_TRUE(regex_search(xml, wregex(L"<item x=\"600\" y=\"100\"")));

		// Ensure the types are correct
		ASSERT_TRUE(regex_search(xml,
								 wregex(
									 L"<game><item.* type=\"redundancyfly\"/><item.* type=\"redundancyfly\"/><item.* type=\"redundancyfly\"/></game>")));
	}
};

TEST_F(GameTest, Construct)
{
	Game game;
}

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
	auto file1 = path + L"/test1.game";

	// Save the file
	game.Save(file1);

	// Test to see if it is empty
	TestEmpty(file1);

}

TEST_F(GameTest, Load)
{
	Game game;

	auto path = TempPath();

	Level level;
	level.GetRandom().seed(RandomSeed);
	Level level2;
	level2.GetRandom().seed(RandomSeed);

	auto file1 = path + L"/test1.game";

	TestEmpty(file1);

	level2.Load(file1,&game);
	TestEmpty(file1);

	PopulateThreeFlies(&game);

	auto file2 = path + L"/test2.game";

	TestThreeFlies(file2);

	game2.Load(file2);
	game2.Save(file2);
	TestThreeFlies(file2);

	//Need to test all types once we populate all types of bugs
}

TEST_F(GameTest, Save) {
	// Create a path to temporary files
	auto path = TempPath();

	// Create a game
	Game game;

	//
	// First test, saving an empty game
	//
	auto file1 = path + L"/test1.game";
	game.Save(file1);

	TestEmpty(file1);

	PopulateThreeFlies(&game);

	auto file2 = path + L"/test2.game";
	game.Save(file2);

	TestThreeFlies(file2);
}