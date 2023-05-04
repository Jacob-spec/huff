#include <stdlib.h>
#include "tree.h"
#include "character.h"

// character == NULL represents an internal node where frequency is the sum of it's children
struct Node {
	Character *character;
	int frequency;	
	struct Node *left;
	struct Node *right;
};

Node *create_node(Character* c, int frequency) {
	Node *new_node = (Node *) malloc(sizeof(Node));
	new_node->character = c;
	new_node->frequency = frequency;
	new_node->left = NULL;
	new_node->right = NULL;
	return new_node;
}

void destroy_node(Node *n) {
	free(n->character);
	free(n);
}
