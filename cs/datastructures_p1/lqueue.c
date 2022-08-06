#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define Q_SIZE 8

// Linked List Queue Node:
typedef struct lqnode {
	int key;
	struct lqnode *next;
} lqnode;

// Linked List Queue:
typedef struct lq {
	struct lqnode *head;
	struct lqnode *tail;
} lq;

lq *init_new_queue(void) {

	// Allocate on Heap and Initialise:
	lq *mylq = (lq*)malloc(sizeof(lq));
	memset(mylq, 0, sizeof(lq));

	mylq->head = NULL;
	mylq->tail = NULL;

	return mylq;
}

int is_queue_empty(lq *mylq) {
	
	if ( mylq->head == NULL )
		return 1;
	return 0;
}

lqnode *init_new_node(int key) {

	lqnode *newnode = (lqnode*)malloc(sizeof(lqnode));
	memset(newnode, 0, sizeof(lqnode));

	newnode->key = key;
	newnode->next = NULL;

	return newnode;
}

void enqueue(lq *mylq, int key) {

	lqnode *newnode = init_new_node(key);

	if ( is_queue_empty(mylq) ) {
		mylq->head = newnode;
		mylq->tail = newnode;
	} else {
		mylq->tail->next = newnode;
		mylq->tail = newnode;
	}
}

int dequeue(lq *mylq, int *key) {

	if ( mylq->head != NULL ) {
		//printf("Head Node: %p\t Next to Head Node: %p\n", mylq->head, mylq->head->next);
		*key = mylq->head->key;
		lqnode *dequeued = mylq->head;
		mylq->head = mylq->head->next;
		free(dequeued);
		return 1;

	} else {
		return 0;
	}
}

int main(void) {

	lq *mylq = init_new_queue();
	int rp = 0;

	for (int i = 0; i < 16; i++){
		enqueue(mylq, i);
		printf("Enqueued Value: %d\n", i);
	}
	for (int i = 0; i < 32; i++){
		if (dequeue(mylq, &rp)) {
			printf("\t\tDequeued Value: %d\n", rp);
		} else {
			printf("\t\tUnderflow\n");
		}
	}
	for (int i = 0; i < 16; i++){
		enqueue(mylq, i * 10);
		printf("Enqueued Value: %d\n", i * 10);
	}
	for (int i = 0; i < 16; i++){
		if (dequeue(mylq, &rp)) {
			printf("\t\tDequeued Value: %d\n", rp);
		} else {
			printf("\t\tUnderflow\n");
		}
	}

	return 0;
}
