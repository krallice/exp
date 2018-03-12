#include <stdio.h>
#include <stdlib.h>

void dump_array(int ar[], int size) {
	for (int i = 0; i < size; i++) {
		printf("%d ", ar[i]);
	}
	printf("\n");
}

int partition(int ar[], int low, int high) {

	// Pivot on highest index value:
	int pivot_value = ar[high];

	// Start our index just below low index:
	int i = low - 1;

	// Loop through our array slice:
	for (int j = low; j < high; j++) {
		
		// If our array slice element is less than our pivot value,
		// slam it down the start of the array (i will always
		// be lesser or equal to j):
		if (ar[j] < pivot_value) {
			i++;
			int tmp = ar[i];
			ar[i] = ar[j];
			ar[j] = tmp;
		}
	}

	// At this stage:
	// a[0..i] < pivot_value;
	// Now set a[i+1] = pivot_value, and return this index
	int tmp = ar[i+1];
	ar[i+1] = pivot_value;
	ar[high] = tmp;

	return i+1;
}

void quick_sort(int ar[], int low, int high) {

	if (low < high) {

		int p = partition(ar, low, high);
		quick_sort(ar, low, p - 1);
		quick_sort(ar, p + 1, high);
	}
}

int main(void) {

	int ar[] = { 1, 254, 19, 88, 11, 25, 43, 12, 3, 12, 55, 165, 33, 12, 42, 777, 4 };
	int arsize = (sizeof(ar)/sizeof(ar[0]));

	dump_array(ar, arsize);

	quick_sort(ar, 0, arsize);
	printf("\n");
	dump_array(ar, arsize);

	return 0;
}
