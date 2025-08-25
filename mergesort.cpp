#include "mergesort.h"

void merge(std::vector<int>& data, int left, int mid, int right)
{
	int n1 = mid - left + 1;
	int n2 = right - mid;

	std::vector<int> L(n1), R(n2);

	for (int i = 0; i < n1; ++i) {
		L[i] = data[left + i];
	}
	for (int i = 0; i < n2; ++i) {
		R[i] = data[mid + 1 + i];
	}

	int i = 0;
	int j = 0;
	int k = left;

	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			data[k] = L[i];
			++j;
		}
		else {
			data[k] = R[j];
			++j;
		}
		++k;
	}

	while (i < n1) {
		data[k] = L[i];
		++i;
		++k;
	}

	while (j < n2) {
		data[k] = R[j];
		++j;
		++k;
	}
}

void mergeSort(std::vector<int>& data, int left, int right)
{
	if (left >= right) {
		return;
	}

	int mid = left + (right - left) / 2;
	mergeSort(data, left, mid);
	mergeSort(data, mid + 1, right);
	merge(data, left, mid, right);
}