#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED



typedef struct PriorityQueue PriorityQueue;

PriorityQueue *create_priority_queue(Character **characters, int character_count);

void destroy_priority_queue(PriorityQueue *pq);

PriorityQueue *enqueue(PriorityQueue *pq, Node *node);

Node *dequeue(PriorityQueue *pq);

#endif
