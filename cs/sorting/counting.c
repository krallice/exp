#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 8

#define NELEMS(x)  (sizeof(x) / sizeof((x)[0]))

void dump_array(int ar[], int size) {
	for (int i = 0; i < size; i++) {
		printf("%d ", ar[i]);
	}
	printf("\n");
}

int main(void) {

	int ar[ARRAY_SIZE] = { 1, 19, 254, 11, 25, 43, 12, 3 };
	int arsize = sizeof(ar)/sizeof(int);

	dump_array(ar, arsize);

	return 0;
}
