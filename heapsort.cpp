#include "heapsort.h"

void heapify(std::vector<int>& data, int index, int size)
{
	int max = index;
	int left = 2 * index + 1;
	int right = 2 * index + 2;

	if (left < size && data[left] > data[max]) {
		max = left;
	}

	if (right < size && data[right] > data[max]) {
		max = right;
	}

	if (max != index) {
		std::swap(data[index], data[max]);
		heapify(data, max, size);
	}
}

void heapSort(std::vector<int>& data)
{
	if (data.size() <= 1)
		return;

	int last_parent = (data.size() / 2) - 1;
	for (int i = last_parent; i >= 0; --i) {
		heapify(data, i, data.size());
	}

	for (int i = data.size() - 1; i > 0; --i) {
		int root = 0;
		std::swap(data[root], data[i]);

		int reduced_size = i;
		heapify(data, root, reduced_size);
	}
}