#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINKED_LIST_SIZE 64

typedef struct node {
	int key;
	char *data;
	struct node *next;
} node;

node *create_linked_list(int size) {

	node *head = (node*)malloc(sizeof(node));

	head->key = 0;
	head->next = NULL;
	head->data = (char*)malloc(1024*1024);
	memset(head->data, 0, 1024*1024);

	node *prev = head;

	for (int i = 1; i < LINKED_LIST_SIZE; i++) {

		node *new = (node*)malloc(sizeof(node));
		new->key = i;
		new->data = (char*)malloc(1024*1024);
		memset(new->data, new->key, 1024*1024);

		prev->next = new;
		prev = new;
	}	

	return head;
}

void dump_linked_list(node *head) {

	node *cur = head;
	while ( cur != NULL ) {
		printf("Node: %p Key: %d\tNext: %p\n", cur, cur->key, cur->next);
		cur = cur->next;
	}
}

node *delete_by_key(node *head, int key) {

	if ( head->key == key ) {
		node *new_head = head->next;
		
		free(head->data);
		free(head);

		return new_head;
	}

	node *cur = head->next;
	node *prev = head;

	while (cur != NULL ) {
		if ( cur->key == key ) {

			prev->next = cur->next;

			free(cur->data);
			free(cur);
			return head;
		}
		prev = cur;
		cur = cur->next;
	}

	return head;
}

int main (void) {

	node *head = create_linked_list(LINKED_LIST_SIZE);
	
	int delkeys[] = {7, 0, 63, 20, 21, 22, 23, 2, 24};
	for (int i = 0; i < 9; i++) {
		printf("Delete Key %d\n", delkeys[i]);
		head = delete_by_key(head, delkeys[i]);
	}
	dump_linked_list(head);

	getchar();
	return 0;
}
