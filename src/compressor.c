#include <stdlib.h>
#include <stdio.h>
#include "character.h"
#include "compressor.h"
#include "tree.h"

#define BUFFER_INCREMENT 256
#define ASCII_MAX 128


char *read_file(const char *filename) {
	char *file_contents = (char *) malloc(sizeof(char) * BUFFER_INCREMENT);

	FILE *file = fopen(filename, "r");
	if (file == NULL) {
		printf("Cannot open file\n");
		return NULL;
	}
	int index = 0, buffer_size = BUFFER_INCREMENT, allocations = 1;
	while (!feof(file)) {
		if ( (index + 1) == buffer_size) {
			file_contents = (char *) realloc(file_contents, BUFFER_INCREMENT * (allocations + 1));
			allocations++;
		}
		*(file_contents + index) = fgetc(file);
		index++;
	}
	return file_contents;
}

// internal character array is a block of memory which is a list of pointers to the actual Characters
// -- allows for switching the places of array elements much easier while sorting
Compressor *create_compressor(const char *filename) {
	Compressor *c = (Compressor *) malloc(sizeof(Compressor));
	c->input = read_file(filename);
	printf("File: %s\n", c->input);
	c->characters = malloc(sizeof(void *) * ASCII_MAX);
	c->number_of_characters = 0;
	return c;
}

void destroy_compressor(Compressor *com) {
	free(com->input);
	for (int i = 0; i < com->number_of_characters; i++) {
		destroy_character( *(com->characters + sizeof(void *) * i) );
	}
	free(com->characters);
	free(com);
}

int is_first_occurence(Compressor *com, char c) {
	for (int i = 0; i < com->number_of_characters; i++) {
		if ( (*(com->characters + sizeof(void *) * i))->character == c) {
			return 0;
		}
	}
	return 1;
}

Compressor *add_character(Compressor *com, char c) {
	Character *new_char = create_character(c);
	*(com->characters + sizeof(void *) * com->number_of_characters) = new_char;
	com->number_of_characters++;
	return com;
}

int get_character_index(Compressor *com, char c) {
	for (int i = 0; i < com->number_of_characters; i++) {
		if ( (*(com->characters + sizeof(void *) * i))->character == c) {
			return i;
		}
	} 	
	return -1;
}

Compressor *find_letters_and_frequency(Compressor *com) {
	int i = 0;
	// stop at EOF
	while (*(com->input + i) != '\xff') {
		if (is_first_occurence(com, *(com->input + i)) != 0) {
			com = add_character(com, *(com->input + i));
		} else {
			int character_index = get_character_index(com, *(com->input + i));
			increment_character_occurence( *(com->characters + sizeof(void *) * character_index) );
		}	
		i++;
	}
	com->characters = sort_characters(com->characters, com->number_of_characters);
	print_characters(com->characters, com->number_of_characters);
	return com;
}
