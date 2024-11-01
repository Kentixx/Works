#include "pch.h"
#include "../task1/find_intersection.cpp"
#include <set>

TEST(findIntersectionTest, isIntersection) {
  std::multiset<int> a = { 1, 2, 4, 5, 7, 8 };
  std::multiset<int> b = { 0, 2, 3, 6, 8, 9 };
  std::multiset<int> expectedResult = { 2, 8 };
  EXPECT_EQ (expectedResult, findIntersectionOfSets(a, b));

  a = { 10, 11, 22, 52 };
  b = { 9, 10, 11, 12 };
  expectedResult = { 10, 11 };
  EXPECT_EQ (expectedResult, findIntersectionOfSets(a, b));

  a = { 51, 52, 53 };
  b = { 52 };
  expectedResult = { 52 };
  EXPECT_EQ(expectedResult, findIntersectionOfSets(a, b));
}

TEST(findIntersectionTest, noIntersection) {
	std::multiset<int> a = { 1, 2, 3, 4, 5 };
	std::multiset<int> b = { 7, 8 };
	std::multiset<int> expectedResult = {  };
	EXPECT_EQ(expectedResult, findIntersectionOfSets(a, b));

	a = { 1, 2, 3 };
	b = {  };
	expectedResult = {  };
	EXPECT_EQ(expectedResult, findIntersectionOfSets(a, b));

	a = {  };
	b = { 10, 11 };
	expectedResult = {  };
	EXPECT_EQ(expectedResult, findIntersectionOfSets(a, b));
}