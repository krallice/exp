#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>

#include <math.h>

int *init_random_array(const int asize) {

	srand(time(NULL));
	int *array = (int *)malloc(asize * sizeof(int*));
	for (int i = 0; i < asize; i++) {
		array[i] = (rand() % 100);
	};

	return array;
}

void print_array(const int *array, const int asize) {

	printf("Array: ");
	for (int i = 0; i < asize; i++) {
		printf("%d ", array[i]);
	}
	printf("\n");
}

void swap(int *a, int *b) {
	int t = *a;
	*a = *b;
	*b = t;
}

int get_right(const int i){
	return ((2*i) + 2);
}

int get_left(const int i){
	return ((2*i) + 1);
}

int get_parent(const int i){
	return floor((i - 1) / 2);
}

void do_siftdown(int *array, int start, int end) {

	// end is the limit of how far down the heap to sift values
	// This progressively shrinks down during the progressive loop in do_heapsort
	int root = start;
	int child;

	// While the root has atleast one child (left child):
	while (get_left(root) <= end) {
		child = get_left(root);
		// If child has a sibling (+1 points to right) && the child's value is less than its sibling:
		if ( ((child + 1) <= end) && (array[child] < array[child + 1])) {
			// Then look at the right child instead:
			child++;
		}
		// If the root is smaller than the child:
		if (array[root] < array[child]) {
			swap(&array[root], &array[child]);
			root = child;
		} else {
			return;
		}
	}
}

void heapify(int *array, const int asize) {

	/*
	  Start at last parent node:
	                0
	              /   \
	             0     0
	            / \   / \
	       --> 0   0 0   0
	          / \
	         0   0
	*/
	int start = (asize) / 2;

	while (start >= 0) {
		// Sift down:
		do_siftdown(array, start, asize - 1);
		start--;
	}
}

void do_heapsort(int *array, const int asize) {

	// Build an initial Max Heap:
	heapify(array, asize);

	// i represents the terminal index of the heap
	// items >= i represent the sorted list
	// items <  i represent the heap/max-heap
	for (int i = (asize - 1); i > 0; i--) {

		// Swap the root (maximum value) of the max heap with 
		// the last element of the heap
		swap(&array[0], &array[i]);

		// Put the heap back into a max-heap order:
		do_siftdown(array, 0, (i-1));
	}
}

int main(int argc, char** argv) {

	int *array = NULL;
	const int asize = 8;

		printf("\n");
		array = init_random_array(asize);
		print_array(array, asize);
		do_heapsort(array, asize);
		printf("Complete:\n");
		print_array(array, asize);
		free(array);
		printf("\n");

	return 0;
}
