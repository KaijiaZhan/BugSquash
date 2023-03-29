/**
 * @file FatBugTest.cpp
 * @author Kaijia Zhan
 * @author Joanna Rodriguez Zamarron
 */

#include <pch.h>
#include <FatBug.h>
#include <Game.h>

#include "gtest/gtest.h"

TEST(FatBugTest, Construct){
	Game game;

	wxXmlNode node;

	FatBug fatBug(&game, L"garbage", &node);
}

TEST(FatBugTest, HitTest) {
// Create a bug to test
	Game game;
	game.Clear();

	wxXmlNode node;

	std::shared_ptr<Item> fatBug = std::make_shared<FatBug>(&game, L"garbage", &node);
	fatBug->SetLocation(100, 200);
	game.Add(fatBug);

	// Center of the bug should be a true
	ASSERT_TRUE(fatBug->HitTest(100, 200));

	// Left of the bug
	ASSERT_FALSE(fatBug->HitTest(10, 200));

	// Right of the bug
	ASSERT_FALSE(fatBug->HitTest(200, 200));

	// Above the bug
	ASSERT_FALSE(fatBug->HitTest(100, 0));

	// Below the bug
	ASSERT_FALSE(fatBug->HitTest(100, 300));

	// On a bug transparent pixel
	ASSERT_FALSE(fatBug->HitTest(100 - 125/2 + 17, 200 - 117/2 + 16));

}

TEST(FatBugTest, DoubleClickTest1)
{
// Create a bug to test
	Game game;
	game.Clear();

	wxXmlNode node;

	auto fatBug = std::make_shared<FatBug>(&game, L"garbage", &node);

	game.Add(fatBug);

	// Set some locations
	fatBug->SetLocation(200, 250);

}