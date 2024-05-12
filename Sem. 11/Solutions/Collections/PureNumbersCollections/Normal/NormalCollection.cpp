#include "NormalCollection.h"
#include <utility>

void NormalCollection::add(int n) {
	if (size == capacity) {
		resize(2 * size);
	}

	data[size++] = n;
}

void NormalCollection::remove(int n) {
	int index = -1;
	for (size_t i = 0; i < size; i++) {
		if (data[i] == n) {
			index = i;
			break;
		}
	}

	if (index == -1) {
		return;
	}

	for (size_t i = index; i < size - 1; i++) {
		data[i] = data[i + 1];
	}
	size--;
	if (size * 4 <= capacity) {
		resize(capacity / 2);
	}
}

size_t NormalCollection::count(int n) const {
	size_t counter = 0;
	for (size_t i = 0; i < size; i++) {
		if (data[i] == n) {
			counter++;
		}
	}

	return counter;
}

bool NormalCollection::contains(int n) const {
	for (size_t i = 0; i < size; i++) {
		if (data[i] == n) {
			return true;
		}
	}

	return false;
}
