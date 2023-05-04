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


Character **swap_array_elements(int start_index, int end_index, Character **characters) {
	Character *first_element = *(characters + start_index * sizeof(void *));
	Character *second_element = *(characters + end_index * sizeof(void *));
	*(characters + start_index * sizeof(void *)) = second_element;
	*(characters + end_index * sizeof(void *)) = first_element;
	return characters;
}



Character **sort_characters(Character **characters, int character_count) {
	int current_minimum_index = 0;
	for (int i = 0; i < character_count; i++) {
		int current_lowest = current_minimum_index;
		int min_occurences = (*(characters + current_minimum_index * sizeof(void *)))->occurences;
		for (int j = current_minimum_index + 1; j < character_count; j++) {
			Character *current_char = *(characters + j * sizeof(void *));
			if (current_char->occurences < min_occurences) {
				current_lowest = j;
			}
		}
		if (current_lowest != current_minimum_index) {
			characters = swap_array_elements(current_minimum_index, current_lowest, characters);
		}
		current_minimum_index++;
	}
	return characters;
}


void print_node(Node *n) {
	if (!n->character) {
		printf("Node: %d\n", n->frequency);
	} else {
		printf("Node: %c\n", n->character->character);
	}

	if (n->left) {
		print_node(n->left);
	} else if (n->right) {
		print_node(n->right);
	}
}

void print_nodes(Node **nodes, int node_count) {
	for (int i = 0; i < node_count; i++) {
		print_node(*(nodes + sizeof(Node) * i));
	}
}


