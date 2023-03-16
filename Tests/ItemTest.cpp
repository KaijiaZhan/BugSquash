/**
 * @file ItemTest.cpp
 * @author Courtney Thang
 */

#include <pch.h>
#include "gtest/gtest.h"
#include <Item.h>
#include <Game.h>

/// Bug filename
const std::wstring FlyImageName = L"images/redundancy-fly-base.png";

/** Mock class for testing the class Item */
class ItemMock : public Item {
public:
	ItemMock(Game *game) : Item(game, FlyImageName) {}

	void Draw(wxDC *dc) override {}
};

TEST(ItemTest, Construct) {
	Game game;
	ItemMock item(&game);

	// Test SetLocation, GetX, and GetY
	item.SetLocation(10.5, 17.2);
	ASSERT_NEAR(10.5, item.GetX(), 0.0001);
	ASSERT_NEAR(17.2, item.GetY(), 0.0001);
}

TEST(ItemTest, GettersSetters){
	Game game;
	ItemMock item(&game);

	// Test initial values
	ASSERT_NEAR(0, item.GetX(), 0.0001);
	ASSERT_NEAR(0, item.GetY(), 0.0001);

	// Test SetLocation, GetX, and GetY
	item.SetLocation(10.5, 17.2);
	ASSERT_NEAR(10.5, item.GetX(), 0.0001);
	ASSERT_NEAR(17.2, item.GetY(), 0.0001);

	// Test a second with different values
	item.SetLocation(-72, -107);
	ASSERT_NEAR(-72, item.GetX(), 0.0001);
	ASSERT_NEAR(-107, item.GetY(), 0.0001);
}

//TEST(FeatureTest, HitTest) {
//	// Create a bug to test
//	Game game;
//	ItemMock bug(&game);
//
//	// Give it a location
//	// Always make the numbers different, in case they are mixed up
//	bug.SetLocation(100, 200);
//
//	// Center of the bug should be a true
//	ASSERT_TRUE(bug.HitTest(100, 200));
//
//	// Left of the bug
//	ASSERT_FALSE(bug.HitTest(10, 200));
//
//	// Right of the bug
//	ASSERT_FALSE(bug.HitTest(200, 200));
//
//	// Above the bug
//	ASSERT_FALSE(bug.HitTest(100, 0));
//
//	// Below the bug
//	ASSERT_FALSE(bug.HitTest(100, 300));
//
//	// On a bug transparent pixel
//	ASSERT_FALSE(bug.HitTest(100 - 125/2 + 17, 200 - 117/2 + 16));
//
//
//}

