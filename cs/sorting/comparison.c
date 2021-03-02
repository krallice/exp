#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>

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

void array_insertion_sort(int *array, const int asize) {

	// O(n2)

	int j = 0;
	int key = 0;

	printf(".: Insertion Sort :.\n");
	for (int i = 1; i < asize; i++) {
		printf("Insertion Sort: i = %d\n", i);
		// Select value:
		key = array[i];
		j = i - 1;
		while ((j >= 0) && (array[j] > key)) {
			// Shift elements up:
			array[j + 1] = array[j];
			j--;
		}
		// emplace back our orignal selected value:
		array[j+1] = key;
		print_array(array, asize);
	}
}

void array_bubble_sort(int *array, const int asize) {

	// O(n2)

	printf(".: Bubble Sort :.\n");
	for (int i = asize - 1; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			if (array[j] > array[j+1]) {
				swap(&array[j], &array[j+1]);
			}
		}
	}
}

void array_selection_sort(int *array, const int asize) {

	// O(n2)

	int minpos;

	printf(".: Selection Sort :.\n");
	for (int i = 0; i < asize; i++) {
		minpos = i;
		for (int j = i; j < asize; j++) {
			if (array[j] < array[minpos]) {
				minpos = j;
			}
		}
		swap(&(array[i]),&(array[minpos]));
	}
}

int main(int argc, char** argv) {

	int *array = NULL;
	const int asize = 8;

	void (*comparison_sort[])() = {array_insertion_sort, array_bubble_sort, array_selection_sort};

	for (int i = 0; i < (sizeof(comparison_sort) / sizeof(void*)); i++) {
		printf("\n");
		array = init_random_array(asize);
		print_array(array, asize);
		comparison_sort[i](array, asize);
		printf("Complete:\n");
		print_array(array, asize);
		free(array);
		printf("\n");
	}

	return 0;
}
