/*
** EPITECH PROJECT, 2018
** itoa
** File description:
** raphael.dubois@epitech.eu
*/

#include "../include/my.h"

char *itoa(int i, char *b)
{
	char const *digit = "0123456789";
	char *p = b;
	int j = i;

	if (i < 0) {
		*p++ = '-';
		i *= -1;
	}
	while (j) {
		++p;
		j = j/10;
	}
	*p = '\0';
	while (i) {
		*--p = digit[i%10];
		i = i/10;
	}
	return b;
}
