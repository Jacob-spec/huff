#include <stdlib.h>
#include "character.h"
#include "sort.h"


typedef Sorter struct {
	Character *characters;
	int character_count;
}

Sorter *create_sorter(Character *characters, int character_count) {
	Sorter *s = (Sorter *) malloc(sizeof(Sorter));
	s->characters = characters;
	s->character_count = character_count;
	return s;
}

// can't remember whether this is a catastrophic bug
Character *destroy_sorter(Sorter *s) {
	Character *characters = s->characters;
	free(s);
	return characters;
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

Character *switch_array_elements(Characters *characters, int first_index, int second_index) {
	Character *first_element = characters + sizeof(Character) * first_index;
	Character *second_element = characters
}







