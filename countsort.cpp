#include "countsort.h"

void countSort(std::vector<int>& data)
{
	int max = *std::max_element(data.begin(), data.end());
	int min = *std::min_element(data.begin(), data.end());
	int range = max - min + 1;

	std::vector<int> count(range, 0);

	for (int num : data) {
		++count[num - min];
	}

	int index = 0;
	for (int i = 0; i < range; ++i) {
		while (count[i] > 0) {
			data[index] = i + min;
			++index;
			--count[i];
		}
	}
}