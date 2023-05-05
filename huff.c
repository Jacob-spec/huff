#include <stdio.h>
#include "./src/compressor.h"
#include "./src/queue.h"
#include "./src/tree.h"

int main() {
	Compressor *com = create_compressor("/Users/jacobstoner/Code/C/comp/misc/test.md");
	com = find_letters_and_frequency(com);
	PriorityQueue *pq = create_priority_queue(com->characters, com->number_of_characters);
	print_nodes(pq->nodes, pq->node_count);
	destroy_priority_queue(pq);
	destroy_compressor(com);
	return 0;
}
