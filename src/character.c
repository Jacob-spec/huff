#include <stdlib.h>
#include <stdio.h>
#include "character.h"



Character *create_character(char c) {
	Character *ch = (Character *) malloc(sizeof(Character));
	ch->character = c;
	ch->occurences = 1;
	return ch;
}

void print_characters(Character **c, int number_of_characters) {
	for (int i = 0; i < number_of_characters; i++) {
		if ( (*(c + sizeof(void *) * i))->character == '\xff') {
			printf("EOF\n");
		} else if ( (*(c + sizeof(void *) * i))->character == '\n') {
			printf("Character: \\n | %d\n", (*(c + sizeof(void *) * i))->occurences);
		} else {
			printf("Character: %c | %d\n", (*(c + sizeof(void *) * i))->character, (*(c + sizeof(void *) * i))->occurences);
		}
	}
}

void destroy_character(Character *c) {
	free(c);
}

void increment_character_occurence(Character *character) {
	character->occurences++;
}



