#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 8

#define NELEMS(x)  (sizeof(x) / sizeof((x)[0]))

#define INSERTION_ASCENDING_MODE 0
#define INSERTION_DESCENDING_MODE 0

void insertion_sort(int ar[], int size, int mode) {

	// Outer loop:
	for (int i = 1; i < size; i++) {

		// Check to see that 1) we are still in bounds, and that
		// our neighbours is out of order:
		int j = i;
		while ((j > 0) && (ar[j - 1] > ar[j])) {
			
			// Swap:
			int tmp = ar[j - 1];
			ar[j - 1] = ar[j];
			ar[j] = tmp;

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

	insertion_sort(ar, ARRAY_SIZE, INSERTION_ASCENDING_MODE);
	dump_array(ar, ARRAY_SIZE);

	//insertion_sort(ar, ARRAY_SIZE, INSERTION_DESCENDING_MODE);
	//dump_array(ar, ARRAY_SIZE);

	return 0;
}
