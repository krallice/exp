#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct rpnnode {
	int value;
	struct rpnnode *next;
} rpnnode;

typedef struct rpnstack {
	struct rpnnode *top;
	int size;
} rpnstack;

rpnstack *rpnstack_create() {
	rpnstack *mystack = (rpnstack*)malloc(sizeof(rpnstack));
	memset(mystack, 0, sizeof(rpnstack));
	mystack->size = 0;
	mystack->top = NULL;
	return mystack;
}

int rpnstack_push(rpnstack *mystack, int value) {

	// Attempt to create new node:
	rpnnode *mynode = (rpnnode*)malloc(sizeof(rpnnode));
	if (!mynode) {
		return 1;
	}
	memset(mynode, 0, sizeof(rpnnode));

	// Pop it onto the "top" of the stack by linking
	// the lstack->top pointer to this node, and by linking the 
	// last top to this node via the lnode->next pointer:
	mynode->value = value;

	mynode->next = mystack->top;
	mystack->top = mynode;
	mystack->size++;

	return 0;
}

int rpnstack_pop(rpnstack *mystack, int *value) {

	if (mystack->top != NULL) {

		// Get our current top:
		rpnnode *curtop = mystack->top;

		// Return our value param:
		*value = curtop->value;

		// Unlink the current top, and delete from memory:
		mystack->top = curtop->next;
		free(curtop);

		mystack->size--;

		return 0;

	// We're at the end of the stack:
	} else {
		return 1;
	}
}

int rpnstack_delete(rpnstack *mystack) {

	rpnnode *curtop;

	while (mystack->top != NULL) {
		curtop = mystack->top;
		mystack->top = curtop->next;
		free(curtop);
	}
	return 0;
}

int exec_addition(rpnstack *mystack) {
	
	int r1 = 0;
	int r2 = 0;

	rpnstack_pop(mystack, &r2);
	rpnstack_pop(mystack, &r1);
	return (r1 + r2);
}

int exec_subtraction(rpnstack *mystack) {
	
	int r1 = 0;
	int r2 = 0;

	rpnstack_pop(mystack, &r2);
	rpnstack_pop(mystack, &r1);
	return (r1 - r2);
}

int exec_multiplication(rpnstack *mystack) {
	
	int r1 = 0;
	int r2 = 0;

	rpnstack_pop(mystack, &r2);
	rpnstack_pop(mystack, &r1);
	return (r1 * r2);
}

int main(int argc, char **argv) {

	// Init our stack:
	rpnstack *mystack = rpnstack_create();

	// User String Reading:
	char *ibuf = NULL;
	int read = 0;
	size_t len;

	// Expression Result:
	int r = 0;

	// Expression Count:
	int ec = 0;

	// Token variables:
	char *t;
	const char s[2] = " ";

	while (1) {

		r = 0;

		printf("(%d) >> ", ec);
		read = getline(&ibuf, &len, stdin);

		strtok(ibuf, "\n");
		printf("(%d) >>>> INPUT EXPRESSION: %s\n", ec, ibuf);

		// Tokenize and iterate:
		t = strtok(ibuf, s);
		while ( t != NULL ) {
			switch (*t) {
				case '+':
					printf("(%d) >>>> PARSED OPERATOR: %s\n", ec, t);
					rpnstack_push(mystack, exec_addition(mystack));
					break;
				case '-':
					printf("(%d) >>>> PARSED OPERATOR: %s\n", ec, t);
					rpnstack_push(mystack, exec_subtraction(mystack));
					break;
				case '*':
					printf("(%d) >>>> PARSED OPERATOR: %s\n", ec, t);
					rpnstack_push(mystack, exec_multiplication(mystack));
					break;
				default:
					printf("(%d) >>>> PARSED OPERAND: %s\n", ec, t);
					rpnstack_push(mystack, atoi(t));
					break;
			}
			// Next token:
			t = strtok(NULL, s);
		}

		rpnstack_pop(mystack, &r);
		if ( mystack->size == 0 ) {
			printf("(%d) >>>> TOTAL RESULT: %d\n\n", ec, r);
		} else {
			// Syntax error, clear stack:
			printf("(%d) >>>> RPN SYNTAX ERROR!\n\n", ec);
			while ( rpnstack_pop(mystack, &r) != 1) {
				rpnstack_pop(mystack, &r);
			}
		}
		ec++;
	}

	rpnstack_delete(mystack);
	return 0;
}
