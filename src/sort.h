#ifndef SORT_H_INCLUDED
#define SORT_H_INCLUDED

typedef struct Sorter Sorter;

Sorter *create_sorter(Character *characters, int character_count);
Character *destroy_sorter(Sorter *s);

Sorter *find_lowest(Sorter *s);

#endif
