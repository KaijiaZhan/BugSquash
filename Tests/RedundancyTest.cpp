/**
 * @file RedundancyTest.cpp
 * @author Kaijia Zhan
 */



#include <pch.h>
#include "gtest/gtest.h"
#include <Game.h>
#include <RedundancyFly.h>

using namespace std;

TEST(RedundancyFlyTest, Construct){
	Game game;
	RedundancyFly item(&game);
}

TEST(RedundancyFlyTest, HitTest) {
	// Create a fly
	Game game;
	game.Clear();

	shared_ptr<Item> rfly = std::make_shared<RedundancyFly>(&game);
	rfly->SetLocation(100, 200);
	game.Add(rfly);

	ASSERT_TRUE(rfly->HitTest(100, 200));

	ASSERT_FALSE(rfly->HitTest(10, 200));

	ASSERT_FALSE(rfly->HitTest(200, 200));

	ASSERT_FALSE(rfly->HitTest(100, 0));

	ASSERT_FALSE(rfly->HitTest(100, 300));

	ASSERT_FALSE(rfly->HitTest(100 - 125/2 + 17, 200 - 117/2 + 16));
}