#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char * argv[])
{
	char* word;
	word = (char*) malloc(15 * sizeof(char));
	if(word == NULL)
	{
		printf("Error. Not enough memory.\n");
		exit(1);
	}
	strncpy(word, "Hello World!", 14);
	printf("%s\n", word);
	free(word);
	return 0;
}
