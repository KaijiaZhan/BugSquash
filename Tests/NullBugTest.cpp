/**
 * @file NullBugTest.cpp
 * @author Kaijia Zhan
 */

#include <pch.h>
#include <NullBug.h>
#include <Game.h>

#include "gtest/gtest.h"

TEST(NullBugTest, Construct){
	Game game;

	NullBug nbug(&game);
}

TEST(NullBugTest, HitTest) {
// Create a nullbug to test
	Game game;
	game.Clear();

	std::shared_ptr<Item> nbug = std::make_shared<NullBug>(&game);
	nbug->SetLocation(100, 200);
	game.Add(nbug);


	// Center of the nullbug should be a true
	ASSERT_TRUE(nbug->HitTest(100, 200));

	// Left of the nullbug
	ASSERT_FALSE(nbug->HitTest(10, 200));

	// Right of the nullbug
	ASSERT_FALSE(nbug->HitTest(200, 200));

	// Above the nullbug
	ASSERT_FALSE(nbug->HitTest(100, 0));

	// Below the nullbug
	ASSERT_FALSE(nbug->HitTest(100, 300));

	// On a nullbug transparent pixel
	ASSERT_FALSE(nbug->HitTest(100 - 125/2 + 17, 200 - 117/2 + 16));

}
