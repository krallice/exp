#include <stdio.h>
#include <stdlib.h>

void dump_array(int ar[], int size) {
	for (int i = 0; i < size; i++) {
		printf("%d ", ar[i]);
	}
	printf("\n");
}

void merge_sort(int ar[], int size) {

	if ( size > 1 ) {

		printf("Start: ");
		dump_array(ar, size);
		
		// Calculate our midpoint:
		int mid_point = size / 2;

		int left_subset[mid_point];
		int right_subset[size - mid_point];

		// Build our left and right arrays:
		for ( int i = 0; i < mid_point; i++) {
			left_subset[i] = ar[i];
		}

		int j = 0;
		for ( int i = mid_point; i < size; i++) {
			right_subset[j] = ar[i];
			j++;
		}

		printf("Left Slice: ");
		dump_array(left_subset, (sizeof(left_subset)/sizeof(left_subset[0])));
		printf("Right Slice: ");
		dump_array(right_subset, (sizeof(right_subset)/sizeof(right_subset[0])));

		merge_sort(left_subset, (sizeof(left_subset)/sizeof(left_subset[0])));
		merge_sort(right_subset, (sizeof(right_subset)/sizeof(right_subset[0])));

		int left_i = 0;
		int right_i = 0;
		int ar_i = 0;

		while ( (left_i < (sizeof(left_subset)/sizeof(left_subset[0]))) && (right_i < (sizeof(right_subset)/sizeof(right_subset[0])))) {
			if ( left_subset[left_i] < right_subset[right_i] ) {
				ar[ar_i] = left_subset[left_i];
				left_i++;
			} else {
				ar[ar_i] = right_subset[right_i];
				right_i++;
			}
			ar_i++;
		}

		while ( left_i < (sizeof(left_subset)/sizeof(left_subset[0])) ) {
			ar[ar_i] = left_subset[left_i];
			left_i++;
			ar_i++;
		}

		while ( right_i < (sizeof(right_subset)/sizeof(right_subset[0])) ) {
			ar[ar_i] = right_subset[right_i];
			right_i++;
			ar_i++;
		}

		//printf("Copied : ");
		//dump_array(ar, size);
	}
	//printf("\n");
}

int main(void) {

	int ar[] = { 1, 254, 19, 88, 11, 25, 43, 12, 3, 12, 55, 165, 33, 12, 42, 777, 4 };
	int arsize = (sizeof(ar)/sizeof(ar[0]));

	dump_array(ar, arsize);
	printf("\n");
	merge_sort(ar, arsize);
	printf("\n\n");
	dump_array(ar, arsize);

	return 0;
}
