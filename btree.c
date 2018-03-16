#include <stdio.h>
#include <stdlib.h>
#include "btree.h"

void destroy_tree(struct node *leaf) {
	if (leaf != 0) {
		destroy_tree(leaf->left);
		destroy_tree(leaf->right);
		free(leaf);
	}
}

void insert(double key, struct node **leaf) { // only adds if doesn't exist yet
	if (*leaf == 0) {
		*leaf = (struct node *) malloc (sizeof(struct node));
		(*leaf)->key_value = key;
		(*leaf)->left = 0;
		(*leaf)->right = 0;
	}
	else if (key < (*leaf)->key_value) {
		insert(key, &(*leaf)->left);
	}
	else if (key > (*leaf)->key_value) {
		insert(key, &(*leaf)->right);
	}
}

struct node *search(double key, struct node *leaf) {
	if (leaf != 0) {
		if (key == leaf->key_value) {
			return leaf;
		}
		else if (key < leaf->key_value) {
			return search(key, leaf->left);
		}
		else if (key > leaf->key_value) {
			return search(key, leaf->right);
		}
	}
	return 0; // not found
}

void print_tree(struct node *leaf) {
	if (leaf != 0) {
		print_tree(leaf->left);
		printf("%f\n", leaf->key_value);
		print_tree(leaf->right);
	}
}

int count_tree(struct node *leaf) {
	if (leaf == 0) {
		return 1;
	}
	else {
		return count_tree(leaf->left) + count_tree(leaf->right);
	}
}








