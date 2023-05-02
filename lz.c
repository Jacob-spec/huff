#include <stdio.h>
#include "./src/compressor.h"

int main() {
	Compressor *com = create_compressor("/Users/jacobstoner/Code/C/comp/misc/test.md");
	com = find_letters_and_frequency(com);
	destroy_compressor(com);
	return 0;
}
