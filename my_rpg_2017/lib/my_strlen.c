/*
** EPITECH PROJECT, 2017
** my_strlen
** File description:
** raphael.dubois@epitech.eu
*/
#include "../include/my.h"
#include "../include/lib.h"

int my_strlen(char const *str)
{
	int i = 0;

	while (str[i] != '\0')
		i++;
	return i;
}
