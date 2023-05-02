#include "character.h"
#include "sort.h"


typedef Sorter struct {
	Character *characters;
	int character_count;
}

Sorter *find_lowest(Sorter *s) {
	Character *lowest = s->characters;
	for (int i = 0; i < character_count; i++) {
		if ( (s->characters + sizeof(Character) * i)->occurences < lowest->occurences) {
			lowest = (s->characters + sizeof(Character) * i);
			Character *original_first_element = s->characters;
			s->characters = lowest;
			(s->characters + sizeof(Character) * i) = original_first_element;
		}	
	}
	return s;
}
