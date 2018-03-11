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

int main(void) {

	int ar[ARRAY_SIZE] = { 1, 19, 254, 11, 25, 11, 12, 3 };
	int arsize = sizeof(ar)/sizeof(int);

	int sorted[arsize];
	int maxvalue = 254;

	dump_array(ar, arsize);
	counting_sort(ar, arsize, sorted, maxvalue);
	printf("\n");
	dump_array(sorted, arsize);

	return 0;
}
