#ifndef COMPRESSOR_H_INCLUDED
#define COMPRESSOR_H_INCLUDED


typedef struct Compressor Compressor;

char *read_file(const char *filename);

Compressor * create_compressor(const char *filename);

void destroy_compressor(Compressor *com);

Compressor * first_occurence_of_character(Compressor *com, char c);

int is_first_occurence(Compressor *com, char c);

Compressor *add_character(Compressor *com, char c);
Compressor *find_letters_and_frequency(Compressor *com);
int get_character_index(Compressor *com, char c);

#endif
