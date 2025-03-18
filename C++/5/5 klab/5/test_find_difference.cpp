#include "pch.h"
#include "../task1/find_difference.cpp"
#include "../task1/find_intersection.h"
#include <set>
#include <array>

TEST(findAminusB, nonEmptySet) {
	std::multiset<int> a = { 2, 4, 6, 8, 10 };
	std::multiset<int> b = { 5, 10, 15 };
	std::multiset<int> intersection = findIntersectionOfSets(a, b);
	std::multiset<int> expectedResult = { 2, 4, 6, 8 };
	std::array<std::multiset<int>, 2> result = findDifferenceOfSets(a, b,
		intersection);
	EXPECT_EQ(expectedResult, result[0]);

	a = { 99, 100, 101 };
	b = {  };
	intersection = findIntersectionOfSets(a, b);
	expectedResult = { 99, 100, 101 };
	result = findDifferenceOfSets(a, b, intersection);
	EXPECT_EQ(expectedResult, result[0]);
}

TEST(findAminusB, emptySet) {
	std::multiset<int> a = { 10, 15, 33 };
	std::multiset<int> b = { 10, 15, 33 };
	std::multiset<int> intersection = findIntersectionOfSets(a, b);
	std::multiset<int> expectedResult = {  };
	std::array<std::multiset<int>, 2> result = findDifferenceOfSets(a, b,
		intersection);
	EXPECT_EQ(expectedResult, result[0]);

	a = {  };
	b = { 52 };
	intersection = findIntersectionOfSets(a, b);
	expectedResult = {  };
	result = findDifferenceOfSets(a, b, intersection);
	EXPECT_EQ(expectedResult, result[0]);
}

TEST(findBminusA, nonEmptySet) {
	std::multiset<int> a = { 8, 9, 10, 20 };
	std::multiset<int> b = { 10, 20, 40, 1000 };
	std::multiset<int> intersection = findIntersectionOfSets(a, b);
	std::multiset<int> expectedResult = { 40, 1000 };
	std::array<std::multiset<int>, 2> result = findDifferenceOfSets(a, b,
		intersection);
	EXPECT_EQ(expectedResult, result[1]);

	a = {  };
	b = { 11, 12, 13 };
	intersection = findIntersectionOfSets(a, b);
	expectedResult = { 11, 12, 13 };
	result = findDifferenceOfSets(a, b, intersection);
	EXPECT_EQ(expectedResult, result[1]);
}

TEST(findBminusA, emptySet) {
	std::multiset<int> a = { 1, 2, 3 };
	std::multiset<int> b = { 1, 2, 3 };
	std::multiset<int> intersection = findIntersectionOfSets(a, b);
	std::multiset<int> expectedResult = {  };
	std::array<std::multiset<int>, 2> result = findDifferenceOfSets(a, b,
		intersection);
	EXPECT_EQ(expectedResult, result[1]);

	a = { 10, 100, 1000 };
	b = {  };
	intersection = findIntersectionOfSets(a, b);
	expectedResult = {  };
	result = findDifferenceOfSets(a, b, intersection);
	EXPECT_EQ(expectedResult, result[1]);
}