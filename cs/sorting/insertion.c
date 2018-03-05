#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 8

#define NELEMS(x)  (sizeof(x) / sizeof((x)[0]))

// Not yet:
#define INSERTION_ASCENDING_MODE 0
#define INSERTION_DESCENDING_MODE 0

void improved_insertion_sort(int ar[], int size) {

	// Outer loop:
	for (int i = 1; i < size; i++) {

		// Check to see that 1) we are still in bounds, and that
		// our neighbours is out of order:
		int j = i;
		int current_value = ar[i];

		while ((j > 0) && (ar[j - 1] > current_value)) {
			// Shift the out of order value in our subloop higher up:
			ar[j] = ar[j-1];
			j = j - 1;
		}

		// Slide back our selected value once once into the array!
		ar[j] = current_value;
	}
}

void insertion_sort(int ar[], int size) {

	// Outer loop:
	for (int i = 1; i < size; i++) {

		// Check to see that 1) we are still in bounds, and that
		// our neighbours is out of order:
		int j = i;

		while ((j > 0) && (ar[j - 1] > ar[j])) {
			// Shift the out of order value in our subloop higher up:
			int tmp = ar[j];
			ar[j] = ar[j-1];
			ar[j-1] = tmp;
			j = j - 1;
		}
	}
}

void dump_array(int ar[], int size) {
	for (int i = 0; i < size; i++) {
		printf("%d ", ar[i]);
	}
	printf("\n");
}

int main(void) {

	int ar[ARRAY_SIZE] = { 1, 19, 254, 11, 25, 43, 12, 3 };

	dump_array(ar, ARRAY_SIZE);

	improved_insertion_sort(ar, ARRAY_SIZE);
	dump_array(ar, ARRAY_SIZE);

	return 0;
}
