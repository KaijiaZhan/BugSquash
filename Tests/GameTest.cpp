/**
 * @file GameTest.cpp
 * @author joann
 */

#include <pch.h>
#include "gtest/gtest.h"
#include <Game.h>

using namespace std;

TEST(GameTest, Construct){
	Game game;
}

TEST(BugTest, HitTest) {
//	// Create a bug to test
//	Game game;
//	FishBeta bug(&aquarium);
//
//	// Give it a location
//	// Always make the numbers different, in case they are mixed up
//	bug.SetLocation(100, 200);
//
//	// Center of the fish should be a true
//	ASSERT_TRUE(bug.HitTest(100, 200));
//
//	// Left of the fish
//	ASSERT_FALSE(bug.HitTest(10, 200));
//
//	// Right of the fish
//	ASSERT_FALSE(bug.HitTest(200, 200));
//
//	// Above the fish
//	ASSERT_FALSE(bug.HitTest(100, 0));
//
//	// Below the fish
//	ASSERT_FALSE(bug.HitTest(100, 300));
//
//	// On a fish transparent pixel
//	ASSERT_FALSE(bug.HitTest(100 - 125/2 + 17, 200 - 117/2 + 16));
}