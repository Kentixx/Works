#include "pch.h"
#include "../task1/find_union.cpp"
#include <set>

TEST(findUnion, isUnion) {
	std::multiset<int> a = { 0, 2, 4 };
	std::multiset<int> b = { 1, 3 };
	std::multiset<int> expectedResult = { 0, 1, 2, 3, 4 };
	EXPECT_EQ(expectedResult, findUnionOfSets(a, b));

	a = { 1, 2, 4, 5};
	b = { 1, 2, 4, 5 };
	expectedResult = { 1, 2, 4, 5 };
	EXPECT_EQ(expectedResult, findUnionOfSets(a, b));

	a = {  };
	b = { 8 };
	expectedResult = { 8 };
	EXPECT_EQ(expectedResult, findUnionOfSets(a, b));

	a = { 10 };
	b = { };
	expectedResult = { 10 };
	EXPECT_EQ(expectedResult, findUnionOfSets(a, b));
}

TEST(findUnion, noUnion) {
	std::multiset<int> a = {  };
	std::multiset<int> b = {  };
	std::multiset<int> expectedResult = {  };
	EXPECT_EQ(expectedResult, findUnionOfSets(a, b));
}