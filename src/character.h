#ifndef CHARACTER_H_INCLUDED
#define CHARACTER_H_INCLUDED


typedef struct Character {
	char character;
	int occurences;
}Character;

Character *create_character(char c);

void destroy_character(Character *c);

void print_characters(Character *c, int number_of_characters);

void increment_character_occurence(Character *character);
#endif
