#include "bubblesort.h"

void bubbleSort(std::vector<int>& data)
{
	bool swap = false;

	for (int i = 0; i < data.size() - 1; ++i) {
		swap = false;

		for (int j = 0; j < data.size() - i - 1; ++j) {
			if (data[j] > data[j + 1]) {
				std::swap(data[j], data[j + 1]);
				swap = true;
			}
		}
		if (!swap)
			break;
	}
}