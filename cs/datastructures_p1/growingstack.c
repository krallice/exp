#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STACK_SIZE 1 

typedef struct stack {
	int *data; // our dynamically allocated data array; doubles in size with realloc() when required
	int size; // actual size of stack, how many n items in stack
	int top; // our stackpointer, points to the "top" of the stack's array index
} stack;

stack *create_stack(void) {

	stack *newstack = (stack*)malloc(sizeof(stack));
	memset(newstack, 0, sizeof(stack));

	newstack->data = (int *)malloc(sizeof(int) * STACK_SIZE); // initial stack size of STACK_SIZE
	memset(newstack->data, 0, (sizeof(int) * STACK_SIZE));

	newstack->size = STACK_SIZE;
	newstack->top = 0; // pointer to the very start of array

	return newstack;
}

int get_stack_size(stack *mystack) {

	return mystack->size;
}

int grow_stack_size(stack *mystack) {

	int newsize = (((get_stack_size(mystack) * 2) + 1); // Double, ie (7 * 2) = 14, + 1 == 15 (16 elements)
	printf("Resizing to %d (Actual: %d)\n", newsize, newsize + 1);
	mystack->size = newsize;
	mystack->data = (int *)realloc(mystack->data, newsize * sizeof(int)); // Resize
	return 1;
}

int stack_empty(stack *mystack) {

	if (mystack->top == 0){
		return 1;
	}
	return 0;
}

int stack_push(stack *mystack, int value) {

	if ( mystack->top <= mystack->size ) { // If our pointer is within the bounds of the size:
		mystack->top++;
		mystack->data[mystack->top - 1] = value;
		return 1;
	} else {
		// Not enough room, try to grow and try again:
		if (grow_stack_size(mystack)) {
			mystack->top++;
			mystack->data[mystack->top - 1] = value;
			return 1;
		} else {
			// Couldn't be done :(
			return 0;
		}
	}
}

int stack_pop(stack *mystack, int *value) {

	if (stack_empty(mystack)) {
		return 0;
	} else {
		*value = mystack->data[mystack->top - 1];
		mystack->top--;
		return 1;
	}
}

int stack_peek(stack *mystack, int *value) {

	if (stack_empty(mystack)) {
		return 0;
	} else {
		*value = mystack->data[mystack->top - 1];
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
	printf("Stack Size: %d\n", get_stack_size(mystack));

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

	int i = 0;
	while ( i < 50000 ) {
		if ( ! stack_push(mystack, 2) ) {
			printf("Stack Full, Unable to Push\n");
		} else {
			//printf("Pushed %d onto Stack\n", 2);
		}
		i++;
	}
	
	getchar();

	return 0;
}
