#include <stdlib.h>
#include <stdio.h>
#include "character.h"
#include "tree.h"

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


Character **insert_array_element(int element_index, int insertion_index, Character **characters) {
	Character *element = *(characters + element_index * sizeof(void *));
	for (int i = insertion_index; i <= element_index; i++) {
		
	}
	return characters;
}


// not working
Character **sort_characters(Character **characters, int character_count) {
	int current_minimum_index = 0;
	for (int i = 1; i < character_count; i++) {
		int current_index = i;
		Character *current_char = *(characters + sizeof(void *) * i);	
		for (int j = 0; j < character_count; j++) {
			if (current_char->frequency > (*(characters + sizeof(void *) * j))->frequency) {
				
			}
		}
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


