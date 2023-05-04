#include <stdlib.h>
#include "character.h"
#include "sort.h"


Character **swap_array_elements(int start_index, int end_index, Character **characters) {
	Character *first_element = *(characters + start_index * sizeof(void *));
	Character *second_element = *(characters + end_index * sizeof(void *));
	*(characters + start_index * sizeof(void *)) = second_element;
	*(characters + end_index * sizeof(void *)) = first_element;
	return characters;
}



Character **sort_characters(Character **characters, int character_count) {
	int current_minimum_index = 0;
	for (int i = 0; i < character_count; i++) {
		int current_lowest = current_minimum_index;
		int min_occurences = (*(characters + current_minimum_index * sizeof(void *)))->occurences;
		for (int j = current_minimum_index + 1; j < character_count; j++) {
			Character *current_char = *(characters + j * sizeof(void *));
			if (current_char->occurences < min_occurences) {
				current_lowest = j;
			}
		}
		if (current_lowest != current_minimum_index) {
			characters = swap_array_elements(current_minimum_index, current_lowest, characters);
		}
		current_minimum_index++;
	}
	return characters;
}
