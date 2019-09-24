/*
** EPITECH PROJECT, 2018
** kevin
** File description:
** kav
*/

#include "../include/my.h"
#include "../include/lib.h"

int	my_strcmp(char *s1, char *s2)
{
	int i = 0;

	if (s1 == NULL || s2 == NULL)
		return (1);

	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (1);
		i++;
	}
	if (s1[i] == '\0' && s2[i] == '\0')
		return (0);
	return (1);
}
