/*
** EPITECH PROJECT, 2017
** my_strcpy
** File description:
** raphael.dubois@epitech.eu
*/

#include "../include/lib.h"
#include "../include/my.h"
#include "../include/lib.h"
#include <stdlib.h>

int my_strlen2(char *str)
{
		int i = 0;

		while (str[i] != '\0')
		i++;
		return (i);
}

char	*my_strcpy2(char *dest, char *src)
{
	int	i = 0;
	int z = 0;

if (dest != NULL)
	i = my_strlen2(dest);
	while (src[z] != '\0') {
		dest[i] = src[z];
		i = i + 1;
		z++;
	}
	dest[i] = 0;
	return (dest);
}

char	*my_strcpy(char *dest, char *src)
{
	int	i = 0;

	while (src[i]) {
		dest[i] = src[i];
		i = i + 1;
	}
	dest[i] = 0;
	return (dest);
}
