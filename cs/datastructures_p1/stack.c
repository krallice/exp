#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STACK_SIZE 64

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

int stack_empty(stack *mystack) {

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

int stack_peek(stack *mystack, int *value) {

	if (stack_empty(mystack)) {
		return 0;
	} else {
		*value = mystack->data[mystack->size - 1];
		return 1;
	}
}

int main(void) {

	stack *mystack = create_stack();

	if ( ! stack_push(mystack, 3) ) {
		printf("Stack Full\n");
		return 1;
	}

	if ( ! stack_push(mystack, 5) ) {
		printf("Stack Full\n");
		return 1;
	}

	int *v;

	if ( stack_peek(mystack, v)) {
		printf("Peek on Stack: %d\n", *v);
	} else {
		printf("Stack Empty\n");
	}

	//if ( stack_pop(mystack, v)) {
		//printf("Peek on Stack: %d\n", *v);
	//} else {
		//printf("Stack Empty\n");
	//}








	return 0;
}
