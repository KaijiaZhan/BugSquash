/**
 * @file GarbageBugTest.cpp
 * @author Kaijia
 * @author Courtney Thang
 */

#include <pch.h>
#include <GarbageBug.h>
#include <Game.h>

#include "gtest/gtest.h"

TEST(GarbageBugTest, Construct){
	Game game;
	GarbageBug bug(&game);
}

TEST(GarbageBugTest, HitTest) {
// Create a fish to test
	Game game;
	GarbageBug bug(&game);

// Give it a location
// Always make the numbers different, in case they are mixed up
	bug.SetLocation(100, 200);

// Center of the bug should be a true
	ASSERT_TRUE(bug.HitTest(100, 200));

// Left of the bug
//	ASSERT_FALSE(bug.HitTest(10, 200));

// Right of the bug
//	ASSERT_FALSE(bug.HitTest(200, 200));

// Above the bug
//	ASSERT_FALSE(bug.HitTest(100, 0));

// Below the bug
//	ASSERT_FALSE(bug.HitTest(100, 300));

// On a bug transparent pixel
//	ASSERT_FALSE(bug.HitTest(100 - 125/2 + 17, 200 - 117/2 + 16));


}