/*
** EPITECH PROJECT, 2018
** wordtab
** File description:
** wordtab
*/

#include <stdlib.h>
#include <string.h>

char **make_wordtab(char *input, int occur)
{
	char **tab = malloc(sizeof(char *) * (occur + 2));
	int j = 0;
	int k = 0;

	for (int i = 0; i <= occur + 1; i++)
		tab[i] = malloc(sizeof(char) * (strlen(input) * 2));
	for (int i = 0; input[i] != '\0'; i++) {
		if (input[i] != ' ') {
			tab[j][k] = input[i];
			k++;
		} else {
			tab[j][k] = '\0';
			j++;
			k = 0;
		}
	}
	tab[j][k] = '\0';
	tab[j + 1] = NULL;
	return (tab);
}

char **count_input(char *input)
{
	int occur = 0;
	char **tab = NULL;

	if (!input)
		return (NULL);
	for (int i = 0; input[i] != '\0'; i++)
		if (input[i] == ' ')
			occur++;
	tab = make_wordtab(input, occur);
	return (tab);
}
