#include "main.h"
/**
 * get_tokens - takes a string and returns an array of char pointers
 * Description - takes an inputted string and makes a couple of copies
 * that can be modified, creates an array of char pointers, and returns it
 * @buf: the string literal that was acquired from getline
 * @sep: list of separators that will be used for strtok
 * Return: returns an array of char pointers (success)
*/
char **get_tokens(char *buf, char *sep)
{
	char *word; /*word is the pointer used to iterate through strtok, str is a dynamically allocated string that can be modified by strtok*/
	char **args; /*an array of char pointers that will be dynamically allocated based off of strtok and then returned to the calling function*/
	char *temp_str = strdup(buf); /*a temp string that is used to find out how large we need to make the arg list*/
	int count = 0; /*a count of how many args there are*/

	
	if (!temp_str)
	{
		perror("Allocation Error\n");
		exit(EXIT_FAILURE);
	}

	for (word = strtok(temp_str, sep); word != NULL; word = strtok(NULL, sep)) /*counts how many arguments there are*/
	{
		count++;
	}
	args = malloc(sizeof(char *) * (count + 1)); /*dynamically allocates an array of char pointers based off of the count*/
	if (!args)
	{
		perror("Allocation Error\n");
		exit(EXIT_FAILURE);
	}

	for (word = strtok(temp_str, sep); word != NULL; word = strtok(NULL, sep)) /*initializes position count in the array of char pointers to the arg*/
	{
		args[count] = strdup(word);
		count++;
	}
	args[count] = NULL; /*sets the final position in the array to NULL*/

	return (args); /*returns the array of args to the calling function*/
}
