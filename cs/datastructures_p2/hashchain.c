#include <stdlib.h>
#include <stdio.h>

#define HCHAIN_SIZE 8

// Basic Clobbering Hash Table:
// Key = (Value Modulo HCHAIN_SIZE)
typedef struct hchain {
	int keys[HCHAIN_SIZE];
	int size;
} hchain;

hchain *init_hchain() {
	hchain *table = (hchain*)malloc(sizeof(hchain));
	table->size = HCHAIN_SIZE;
	return table;
}

void insert_hchain(hchain *table, int value) {
	table->keys[value % table->size] = value;
}

void dump_hchain(hchain *table) {

	for (int i = 0; i < table->size; i++) {
		printf("Table Key: %d Value: %d\n", i, table->keys[i]);

	}
}

int main(void) {

	hchain *table = init_hchain();

	insert_hchain(table, 5);
	insert_hchain(table, 9);
	insert_hchain(table, 8);
	
	// Clobbers 5:
	insert_hchain(table, 13);

	dump_hchain(table);

	return 0;
}
