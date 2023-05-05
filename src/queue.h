#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED
#include "tree.h"


typedef struct PriorityQueue {
	Node **nodes;
	int node_count;
	int capacity;
}PriorityQueue;

PriorityQueue *create_priority_queue(Character **characters, int character_count);

void destroy_priority_queue(PriorityQueue *pq);
int find_index_of_lowest_frequency(PriorityQueue *pq);
PriorityQueue *enqueue(PriorityQueue *pq, Node *node);

Node *dequeue(PriorityQueue *pq);

#endif
