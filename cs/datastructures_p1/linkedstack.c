#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct lnode {
	int key;
	struct lnode *next;
} lnode;

typedef struct lstack {
	struct lnode *top;
	int size;
} lstack;


lstack *create_lstack() {

	lstack *mystack = (lstack*)malloc(sizeof(lstack));
	memset(mystack, 0, sizeof(lstack));

	mystack->top = NULL;

	return mystack;
}

int push_on_lstack(lstack *mystack, int key) {

	lnode *newnode = (lnode*)malloc(sizeof(lnode));
	memset(newnode, 0, sizeof(lnode));

	newnode->key = key;
	newnode->next = mystack->top;
	
	mystack->top = newnode;

	return 1;
}

int pop_off_lstack(lstack *mystack, int *retkey) {

	if ( mystack->top != NULL ) {

		// Return our top key into retkey:
		*retkey = mystack->top->key;

		// Save our top node address, ready to delete:
		lnode *popped_node = mystack->top;

		// Unlink top node:
		mystack->top = mystack->top->next;

		// Blow away the old top node:
		free(popped_node);

		// We good:
		return 1;
	} else {
		return 0;
	}
}

int main(void) {

	lstack *mystack = create_lstack();

	for (int i = 1; i < 65; i++) {
		if ( ! push_on_lstack(mystack, i) ) {
			printf("Error Pushing\n");
			return 1;
		}
	}

	int retkey;
	while (pop_off_lstack(mystack, &retkey)) {
		printf("Popped off %d the Stack\n", retkey);
	}

	return 0;
}
