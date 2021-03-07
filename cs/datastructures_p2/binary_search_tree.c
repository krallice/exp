#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdint.h>

typedef struct node {

	int data;
	struct node *left;
	struct node *right;
} node;

typedef struct bst {
	int size;
	int* tree;
} bst;

node *new_node(const int data) {

	node *p;
	p = (node *)calloc(1, sizeof(node));
	// p = (node *)malloc(sizeof(node));

	p->data = data;
	p->left = NULL;
	p->right = NULL;

	return p;
}

void destroy_tree(node *r) {
	if (r != NULL) {
		destroy_tree(r->left);
		destroy_tree(r->right);
		free(r);
	}
}


node *init_basic_tree(void) {

	node *root = new_node(10);

	root->left = new_node(20);
	root->right = new_node(30);

	root->left->left = new_node(40);
	root->left->right = new_node(50);

	root->right->left = new_node(60);
	root->right->right = new_node(70);

	root->left->left->left = new_node(80);
	root->left->left->right = new_node(90);

	root->left->right->left = new_node(100);
	root->left->right->right = new_node(110);

	root->right->left->left = new_node(120);
	root->right->left->right = new_node(130);

	root->right->right->left = new_node(140);
	root->right->right->right = new_node(150);

	return root;
}

void traversal_preorder(node *r) {

	if (r != NULL) {
		printf("%d ", r->data);
		traversal_preorder(r->left);
		traversal_preorder(r->right);
	}
}

void traversal_inorder(node *r) {

	if (r != NULL) {
		traversal_preorder(r->left);
		printf("%d ", r->data);
		traversal_preorder(r->right);
	}
}

node *insert_bst_value(node *root, const int val) {

	if (root == NULL) {
		return new_node(val);
	}
	if (root->data < val) {
		printf("Traversing down Right\n");
		root->right = insert_bst_value(root->right, val);
	} else {
		printf("Traversing down Left\n");
		root->left = insert_bst_value(root->left, val);
	}
	return root;
}

node *build_binary_search_tree(const int n, const int range) {

	if (n < 1) {
		return NULL;
	}

	srand(time(NULL));
	int val = rand() % range; 

	node *root = new_node(val);
	printf("Root: %d\n", val);

	for (int i = 1; i < n; i++) {
		int val = rand() % range;
		printf("Inserting val: %d\n", val);
		insert_bst_value(root, val);
	}
	return root;
};

int bst_left(const int i) {
	return ((2 * i) + 1);
}

int bst_right(const int i) {
	return ((2 * i) + 2);
}

bst *bst_build_binary_search_tree(const int n, const int range) {

	if (n < 1) {
		return NULL;
	}

	srand(time(NULL));

	bst *b = (bst *)calloc(1,sizeof(bst));
	b->size = n;
	b->tree = calloc(n, sizeof(int));

	for (int i = 0; i < b->size; i++) {
		int val = rand() % range; 
		b->tree[i] = val;
	}

	for (int i = 0; i < b->size; i++) {
		printf("%d : ", b->tree[i]);
	}

	return b;

};

void bst_destroy(bst *b) {

	free(&(b->tree[0]));
	free(b);
}

int main(void) {

	// Linked List:
	// node *root = build_binary_search_tree(9, 100);

	// traversal_preorder(root);
	// printf("\n");
	// traversal_inorder(root);
	// printf("\n");

	// destroy_tree(root);
	//
	bst *b = bst_build_binary_search_tree(8, 10);

	bst_destroy(b);
	return 0;
}
