#ifndef SORT_H_INCLUDED
#define SORT_H_INCLUDED

typedef struct Sorter Sorter;

Character **swap_array_elements(int start_index, int end_index, Character **characters);

Character **sort_characters(Character **characters, int character_count);

#endif
