#include <stdlib.h>
#include <stdio.h>

#define HCHAIN_SIZE 2

// Linked List that we are storing in hchain:
typedef struct hnode {
	int data;
	struct hnode *next;
} hnode;

// Array of Linkedlists:
typedef struct hchain {
	struct hnode *keys[HCHAIN_SIZE];
	int size;
} hchain;

hchain *init_hchain() {
	
	// Init and set to 0/NULL:
	hchain *table = (hchain*)malloc(sizeof(hchain));
	table->size = HCHAIN_SIZE;
	for (int i = 0; i < table->size; i++) {
		table->keys[i] = NULL;
	}
	return table;
}

void insert_hchain(hchain *table, int value) {

	hnode *newnode = (hnode*)malloc(sizeof(hnode));
	newnode->data = value;
	newnode->next = NULL;

	int insertkey = value % table->size;

	// If we're empty, insert straight in:
	if ( table->keys[insertkey] == NULL ) {
		table->keys[insertkey] = newnode;

	} else {
		printf("Collision on key %d\n", insertkey);
		// Ffwd straight to the end:
		hnode *curnode = table->keys[insertkey];
		hnode *lastnode = curnode;
		while ( curnode != NULL ) {
			lastnode = curnode;
			curnode = curnode->next;
		}

		// Link them up:
		lastnode->next = newnode;
	}
}

void dump_hchain(hchain *table) {

	for (int i = 0; i < table->size; i++) {
		if ( table->keys[i] != NULL ) {
			printf("Table Key: %d Value: ", i);

			hnode *curnode = table->keys[i];
			while ( curnode != NULL ) {
				       printf("%d ", curnode->data);
				       curnode = curnode->next;
			}
			printf("\n");
		} else {
			printf("Table Key: %d Value: %d\n", i, 0);
		}
	}
}

hnode *find_hnode_by_data(hchain *table, int value) {

	int insertkey = value % table->size;

	hnode *curnode = table->keys[insertkey];
	while ( curnode != NULL ) {
		if ( curnode->data == value ) {
			printf("Found Value %d at address %p\n", value, curnode);
			return curnode;
		}
		curnode = curnode->next;
	}
	printf("Not able to find %d\n", value);
	return NULL;
}

int main(void) {

	hchain *table = init_hchain();

	insert_hchain(table, 5);
	insert_hchain(table, 9);
	insert_hchain(table, 8);
	insert_hchain(table, 24);
	
	// No Longer Clobbers, as we are chaining with a linked list:
	insert_hchain(table, 13);
	insert_hchain(table, 21);

	dump_hchain(table);

	find_hnode_by_data(table, 64);
	find_hnode_by_data(table, 13);
	find_hnode_by_data(table, 5);
	find_hnode_by_data(table, 21);
	find_hnode_by_data(table, 8);

	return 0;
}
