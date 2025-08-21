#include <algorithm>
#include <chrono>
#include <iostream>
#include <random>
#include <vector>

#include "countsort.h"

//uses mt19937 to generate arraySize of random numbers between min and max
std::vector<int> randomGenerator(int arraySize, int min, int max)
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(min, max);

	std::vector<int> randomNums(arraySize);

	for (int i = 0; i < arraySize; ++i) {
		randomNums[i] = dis(gen);
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

	std::vector<int> data1 = testingNumbers;

	//countsort call
	auto start = std::chrono::high_resolution_clock::now();

	countSort(data1);

	auto end = std::chrono::high_resolution_clock::now();

	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

	std::cout << duration.count();

	return 0;
}