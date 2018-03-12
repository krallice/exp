#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARRAY_SIZE 8

void dump_array(int ar[], int size) {
	for (int i = 0; i < size; i++) {
		printf("%d ", ar[i]);
	}
	printf("\n");
}

void counting_sort(int ar[], int size, int sorted[], int maxvalue) {

	// Init our counting index to 0;
	int c[maxvalue + 1];
	for (int i = 0; i <= maxvalue; i++) {
		c[i] = 0;
	}

	// Create a histogram, each value in ar,
	// increment the matching index value in the histogram array:
	for (int j = 0; j < size; j++) {
		c[ar[j]] = c[ar[j]] + 1;
	}

	dump_array(c, maxvalue + 1);
	printf("\n");

	// Loop through our histogram:
	int sorted_index = 0;
	for (int i = 0; i < maxvalue + 1; i++) {
		// A positive value in the histogram:
		while (c[i] > 0) {
			// Write this value to our sorted array, and increment the index:
			sorted[sorted_index++] = i;
			// Deplete the histogram's value:
			c[i]--;
		}
	}
}

// Our stable version which does not re-order similar valued items:
void stable_counting_sort(int ar[], int size, int sorted[], int maxvalue) {
	
	// Init our counting index to 0;
	int c[maxvalue + 1];
	for (int i = 0; i <= maxvalue; i++) {
		c[i] = 0;
	}

	// Create a histogram, each value in ar,
	// increment the matching index value in the histogram array:
	for (int j = 0; j < size; j++) {
		c[ar[j]] = c[ar[j]] + 1;
	}

	dump_array(c, maxvalue + 1);
	printf("\n");

	/*
	 * We transform C to an array where C[j] refers to how many elements are
	 * = j. We do this by iterating through C and adding the value at the previous index to the value at
	 * the current index, since the number of elements = j is equal to the number of elements = j - 1
	 * (i.e. the value at the previous index) plus the number of elements = j (i.e. the value at the current
	 * index). The final result is a matrix C where the value of C[j] is the number of elements = j in A.
	 */	
	for (int i = 0; i <= maxvalue; i++) {
		c[i] = c[i] + c[i - 1];
	}
	dump_array(c, maxvalue + 1);
	printf("\n");

	for (int j = size - 1; j >= 0; j--) {
		printf("%d\n", ar[j]);
		sorted[c[ar[j]] - 1] = ar[j];
		c[ar[j]] = c[ar[j]] - 1;
	}
}

int main(void) {

	int ar[ARRAY_SIZE] = { 4, 19, 254, 11, 25, 11, 12, 3 };
	int arsize = sizeof(ar)/sizeof(int);

	int sorted[arsize];
	int maxvalue = 254;

	dump_array(ar, arsize);
	stable_counting_sort(ar, arsize, sorted, maxvalue);
	printf("\n");
	dump_array(sorted, arsize);

	return 0;
}
