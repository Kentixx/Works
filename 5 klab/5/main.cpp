#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <cmath>
#include <vector>

std::multiset<int> readNumbers(std::string filePath);
std::vector<std::string> readRequests(std::string filePath);
std::string makeRequests(std::multiset<int>&, const std::vector<std::string>&);
void consoleOutput(std::string);

int convertToDigit(std::string numberString) {
	int num = 0;
	for (int i = 0; i < numberString.size(); ++i) {
		num += ((int)numberString[i] - 48) * pow(10, numberString.size() - 1 - i);
	}
	return num;
}

std::multiset<int> readNumbers(std::string filePath) {
	std::ifstream data(filePath);
	std::multiset<int> numbers;
	std::string numberString;
	int num;
	while (getline(data, numberString, ' ')) { // >> 
		num = convertToDigit(numberString);
		numbers.emplace(num);
	}
	return numbers;
}

std::vector<std::string> readRequests(std::string filePath) {
	std::ifstream data(filePath);
	std::vector<std::string> requests;
	std::string request;
	while (getline(data, request)) {
		requests.push_back(request);
	}
	return requests;
}

void addElement(std::multiset<int>& numbers, int& number) {
	numbers.emplace(number);
}

void deleteElement(std::multiset<int>& numbers, int& number) {
	auto it = numbers.find(number);
	if (it != numbers.end()) {
		numbers.erase(*it);
	}
}

int findMinElement(const std::multiset<int>& numbers) {
	return *numbers.begin();
}

bool isExist(const std::multiset<int>& numbers, const int& number) {
	return numbers.count(number);
}

std::string makeRequests(std::multiset<int>& numbers, 
	const std::vector<std::string>& requests) {
	std::string summary;
	int i;
	int number;

	for (std::string request : requests) {
		std::string action;
		std::string s; // digit
		for (i = 0; request[i] != ' ' && i != request.size(); ++i) {
			action.insert(action.end(), request[i]);
		}
		for (++i, number = 0; i < request.size(); ++i) {
			s = request[i];
			int digit = convertToDigit(s);
			number += digit * pow(10, request.size() - 1 - i);
		}

		if (action == "add") {
			addElement(numbers, number);
		}
		else if (action == "delete") {
			deleteElement(numbers, number);
		}
		else if (action == "find_min") {
			summary += "The minimal element is " + 
				std::to_string(findMinElement(numbers)) + '\n';
		}
		else if (action == "is_exist") {
			summary += std::to_string(number) + " is ";
			if (!(isExist(numbers, number))) {
				summary += "not ";
			}
			summary += "in the container\n";
		}

		summary += "Intermediate container version: ";
		for (int i : numbers) {
			summary += std::to_string(i) + ' ';
		}
		summary += '\n';
	}
	return summary;
}

void consoleOutput(std::string message) {
	std::cout << message;
}
int main() {
	std::multiset<int> numbers = readNumbers("data/numbers");
	std::vector<std::string> requests = readRequests("data/requests");
	std::string summary = makeRequests(numbers, requests);
	consoleOutput(summary);
	return 0;
}
