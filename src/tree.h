#ifndef TREE_H_DEFINED
#define TREE_H_DEFINED
#include "character.h"

// character == NULL represents an internal node where frequency is the sum of it's children
typedef struct Node {
	Character *character;
	int frequency;	
	struct Node *left;
	struct Node *right;
}Node;


Node *create_node(Character *c, int frequency);
void print_node(Node *n); 
void print_nodes(Node **nodes, int node_count);
Character **swap_array_elements(int start_index, int end_index, Character **characters);

Character **sort_characters(Character **characters, int character_count);

#endif
