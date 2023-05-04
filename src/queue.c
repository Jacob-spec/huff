#include "tree.h";
#include "character.h"
#include "queue.h";

#define PQ_CAPACITY 128

// whole file has yet to be even compiled

typdef struct PriorityQueue {
	Node **nodes;
	int node_count;
	int capacity;
}PriorityQueue;

// takes the list of Character *, wraps them into Node's, and loads them
// into the PriorityQueue
PriorityQueue *create_priority_queue(Character **characters, int character_count) {
	PriorityQueue *pq = (PriorityQueue *) malloc(sizeof(PriorityQueue));
	pq->nodes = malloc(sizeof(void *) * PQ_CAPACITY);
	pq->node_count = character_count;
	for (int i = 0; i < character_count; i++) {
		Character *new_leaf = *(character + sizeof(void *) * i);
		*(pq->nodes + sizeof(void *) * i) = create_node(new_leaf, new_leaf->frequency);
	}
	pq->capacity = PQ_CAPACITY;
	return pq;
}

void destroy_priority_queue(PriorityQueue *pq) {
	free(pq->nodes);
	free(pq);
}

PriorityQueue *enqueue(PriorityQueue *pq, Node *node) {
	if (pq->node_count == pq->capacity) {
		pq->nodes = realloc(pq->nodes, sizeof(void *) * (pq->capacity + PQ_CAPACITY));
	}
	*(pq->nodes + sizeof(void *) * pq->node_count) = node;
	pq->node_count++;
	return pq;
}

// why did I pick something with such goddamn complicated algorithms and data structures
Node *dequeue(PriorityQueue *pq) {
	int lowest_frequency;
	Node *node;
	for (int i = 0; i < pq->node_count; i++) {

		int frequency = (*(pq->nodes + sizeof(void *) * i))->frequency;

	}
}

// totally untested
int find_index_of_lowest_frequency(PriorityQueue *pq) {
	int index = 0;
	for (int i = index; i < pq->node_count; i++) {
		int current_node = *(pq->nodes + index * sizeof(void *));
		for (int j = index; j < pq->node_count; j++) {
			if ( (*(pq->nodes + j * sizeof(void *)))->frequency < current_node->frequency) {
				index = j;
				break;
			}
		}
	} 
}

