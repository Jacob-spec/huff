#ifndef TREE_H_DEFINED
#define TREE_H_DEFINED

typedef struct Node Node;

Node *create_node(Character *c, int frequency);
void print_node(Node *n); 
void print_nodes(Node **nodes, int node_count);
Character **swap_array_elements(int start_index, int end_index, Character **characters);

Character **sort_characters(Character **characters, int character_count);

#endif
