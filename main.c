#include "monty.h"
/**
*main - the main function
*@argc: the number of elements
*@argv: the array containing the arguments
*Return: Always 0
*/
int main(int argc, char *argv[])
{
	char *buffer = NULL;
	size_t size = 32;
	int line, count = 0;
	FILE *fp;

	if (argc != 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fp = fopen(argv[1], O_RDONLY);
	if (fp == NULL)
	{
		printf("Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	/*buffer = malloc(sizeof(char*) * 32);
	if(!buffer)
		return (-1);*/
	do
	{
		line = getline(&buffer, &size, fp);
		printf("%s", buffer);
		count++;
		free(buffer);
	}while(line);
	
	fclose(fp);
	return (0);
}