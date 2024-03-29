#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STACK_SIZE 12

typedef struct stack {
	int data[STACK_SIZE];
	int size;
} stack;

stack *create_stack(void) {

	stack *newstack = (stack*)malloc(sizeof(stack));

	//for (int i = 0; i < STACK_SIZE; i++) {
		//newstack->data[i] = 0;
	//}
	//newstack->size = 0;

	memset(newstack, 0, sizeof(stack));
	return newstack;
}

int stack_empty(const stack *mystack) {

	if (mystack->size == 0){
		return 1;
	}
	return 0;
}

int stack_push(stack *mystack, int value) {

	if ( mystack->size < STACK_SIZE ) {
		mystack->size++;
		mystack->data[mystack->size - 1] = value;
		return 1;
	} else {
		return 0;
	}
}

int stack_pop(stack *mystack, int *value) {

	if (stack_empty(mystack)) {
		return 0;
	} else {
		*value = mystack->data[mystack->size - 1];
		mystack->size--;
		return 1;
	}
}

int stack_peek(const stack *mystack, int *value) {

	if (stack_empty(mystack)) {
		return 0;
	} else {
		*value = mystack->data[mystack->size - 1];
		return 1;
	}
}

int main(void) {

	stack *mystack = create_stack();

	for (int i = 1; i <= 16; i++) {
		if ( ! stack_push(mystack, i) ) {
			printf("Stack Full, Unable to Push\n");
		} else {
			printf("Pushed %d onto Stack\n", i);
		}
	}
	printf("Finishing Pushing\n");

	int v;
	if ( stack_peek(mystack, &v) ) {
		printf("Peek on Stack: %d\n", v);
	} else {
		printf("Stack Empty, Unable to Peek\n");
	}

	for (int i = 0; i < 13; i++) {
		if ( stack_pop(mystack, &v) ) {
			printf("Popped off Stack: %d\n", v);
		} else {
			printf("Stack Empty, Unable to Pop\n");
		}
	}

	if ( stack_peek(mystack, &v) ) {
		printf("Peek on Stack: %d\n", v);
	} else {
		printf("Stack Empty, Unable to Peek\n");
	}

	return 0;
}
