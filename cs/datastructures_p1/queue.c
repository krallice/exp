#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define Q_SIZE 8

// For our queue to have items in it, head != tail (including roll over)
typedef struct q {
	int queue[Q_SIZE];
	int head;
	int tail;
	int size;
	int used;
} q;

void dump_array(int ar[], int size) {
	for (int i = 0; i < size; i++) {
		printf("%d ", ar[i]);
	}
	printf("\n");
}

q *init_new_queue(void) {

	// Allocate on Heap and Initialise:
	q *myq = (q*)malloc(sizeof(q));
	memset(myq, 0, sizeof(q));

	myq->size = Q_SIZE;
	myq->head = myq->tail = 0;
	myq->used = 0;

	return myq;
}

int enqueue(q *myq, int key) {

	// If we have NOT ran out of room:
	if ( myq->used != myq->size ) {
		
		// Assign:
		myq->queue[myq->tail] = key;

		// If tail is at the end, wrap around, otherwise increment:
		myq->tail = (myq->tail + 1) % (myq->size);
		myq->used++;
		return 1;

	} else {
		// Overflow:
		return 0;
	}
}

int dequeue(q *myq, int *key) {

	// If head and tail are the same, we are out of elements:
	if ( myq->used != 0 ) { 

		// Return our key:
		*key = (myq->queue[myq->head]);

		//Increment the key towards the tail, wrap if nessesary:
		myq->head = (myq->head + 1) % (myq->size);
		myq->used--;
		return 1;

	} else {
		// Underflow:
		return 0;
	}

}

int main(void) {

	q *myq = init_new_queue();

	int rp = NULL;

	for (int i = 1; i < 18; i++){
		if (enqueue(myq, i*200)) {
			printf("Enqueued Key: %d\n", i*200);
		} else {
			printf("Overflow\n");
		}
		dump_array(myq->queue, myq->size);
	}

	printf("DEQUEUE TIME\n");
	printf("DEQUEUE TIME\n");
	printf("DEQUEUE TIME\n");

	for (int i = 1; i < 17; i++){
		if (dequeue(myq, &rp)) {
			printf("Dequeued Key: %d\n", rp);
		} else {
			printf("Underflow .. Nothing Left\n");
		}
		dump_array(myq->queue, myq->size);
	}

	dump_array(myq->queue, myq->size);
	return 0;
}
