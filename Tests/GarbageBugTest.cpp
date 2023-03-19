/**
 * @file GarbageBugTest.cpp
 * @author Kaijia Joanna Zhan
 * @author Courtney Thang
 */

#include <pch.h>
#include <GarbageBug.h>
#include <Game.h>

#include "gtest/gtest.h"

TEST(GarbageBugTest, Construct){
	Game game;

	GarbageBug gbug(&game);
}

TEST(GarbageBugTest, HitTest) {
// Create a fish to test
	Game game;
	game.Clear();

	std::shared_ptr<Item> gbug = std::make_shared<GarbageBug>(&game);
	gbug->SetLocation(100, 200);
	game.Add(gbug);

	// Center of the fish should be a true
	ASSERT_TRUE(gbug->HitTest(100, 200));

	// Left of the fish
	ASSERT_FALSE(gbug->HitTest(10, 200));

	// Right of the fish
	ASSERT_FALSE(gbug->HitTest(200, 200));

	// Above the fish
	ASSERT_FALSE(gbug->HitTest(100, 0));

	// Below the fish
	ASSERT_FALSE(gbug->HitTest(100, 300));

	// On a fish transparent pixel
	ASSERT_FALSE(gbug->HitTest(100 - 125/2 + 17, 200 - 117/2 + 16));

}