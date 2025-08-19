#include <algorithm>
#include <iostream>
#include <random>
#include <vector>

//uses mt19937 to generate arraySize of random numbers between min and max
std::vector<int> randomGenerator(int arraySize, int min, int max)
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(min, max);

	std::vector<int> randomNums;

	for (int i = 0; i < arraySize; ++i) {
		int randomNum = dis(gen);
		randomNums.emplace_back(randomNum);
	}

	return randomNums;
}


int main()
{
	std::cout << "Sorting Algorithm Benchmarker\n";

	std::cout << "Enter the length of testing array: ";
	int testingSize = 0;
	std::cin >> testingSize;

	std::cout << "Enter minimum number size: ";
	int minNum = 0;
	std::cin >> minNum;

	std::cout << "Enter maximum number size: ";
	int maxNum = 0;
	std::cin >> maxNum;

	std::cout << "Generating array!\n";

	std::vector<int> testingNumbers = randomGenerator(testingSize, minNum, maxNum);

	for (int num : testingNumbers) {
		std::cout << num << ' ';
	}

	std::cout << '\n';
	std::cout << std::endl;

	std::sort(testingNumbers.begin(), testingNumbers.end());

	for (int num : testingNumbers) {
		std::cout << num << ' ';
	}

	return 0;
}