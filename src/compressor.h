#ifndef COMPRESSOR_H_INCLUDED
#define COMPRESSOR_H_INCLUDED
#include "character.h"

typedef struct Compressor {
	char *input;
	// array of Characters which store the occurences as well
	Character **characters;
	int number_of_characters;
}Compressor;

char *read_file(const char *filename);

Compressor *create_compressor(const char *filename);

void destroy_compressor(Compressor *com);

Compressor *first_occurence_of_character(Compressor *com, char c);

int is_first_occurence(Compressor *com, char c);

Compressor *add_character(Compressor *com, char c);
Compressor *find_letters_and_frequency(Compressor *com);
int get_character_index(Compressor *com, char c);

#endif
