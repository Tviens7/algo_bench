#include "radixsort.h"

void countForRadix(std::vector<int>& data, int place)
{
	int size = data.size();
	std::vector<int> output(size);
	int count[10] = { 0 };

	for (int i = 0; i < size; ++i) {
		count[(data[i] / place) % 10]++;
	}

	for (int i = 1; i < 10; ++i) {
		count[i] += count[i - 1];
	}

	for (int i = size - 1; i >= 0; --i) {
		output[count[(data[i] / place) % 10] - 1] = data[i];
		--count[(data[i] / place) % 10];
	}

	for (int i = 0; i < size; ++i) {
		data[i] = output[i];
	}
}

void radixSort(std::vector<int>& data)
{
	int max = *std::max_element(data.begin(), data.end());

	for (int place = 1; max / place > 0; place *= 10) {
		countForRadix(data, place);
	}
}