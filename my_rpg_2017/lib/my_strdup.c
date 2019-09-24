/*
** EPITECH PROJECT, 2017
** strdup
** File description:
** strdup
*/

#include "../include/my.h"
#include <stdlib.h>

char *my_strdup(char const *src)
{
	char	*str;
	int	i = 0;

	str = malloc(sizeof(char) * my_strlen(src + 1));
	while (src[i] != '\0') {
		str[i] = src[i];
		i++;
	}
	str[i] = '\0';
	return (str);
	free (str);
}
