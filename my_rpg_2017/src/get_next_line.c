/*
** EPITECH PROJECT, 2018
** get_next_line
** File description:
** get_next_line
*/

#include <unistd.h>
#include <stdlib.h>
#include "../include/get_next_line.h"
#include "../include/my.h"

char get_next_char(int fd)
{
	static char   buffer[READ_SIZE];
	static char   *tmp;
	static int    len = 0;
	char          next_char = 0;

	if (len == 0) {
		len = read(fd, buffer, READ_SIZE);
		tmp = buffer;
		if (len <= 0)
			return (0);
	}
	next_char = tmp[0];
	tmp = tmp + 1;
	len = len - 1;
	return (next_char);
}

char *my_realloc(char *str, int size)
{
	char	*tmp;
	int	i = 0;

	tmp = malloc(sizeof(*tmp) * (my_strlen(str) + size));
	tmp = str;
	if (tmp == NULL)
		return (NULL);
	while (str[i++]) {
		tmp[i] = str[i];
	}
	free(str);
	return (tmp);
}

char *get_next_line(const int fd)
{
	int	i = 0;
	char	next_char;
	char	*str = malloc(READ_SIZE + 1);

	if (str == NULL || fd == -1)
		return (NULL);
	next_char = get_next_char(fd);
	if (next_char == -1)
		return (NULL);
	while (next_char != '\n' && next_char != '\0') {
		str[i] = next_char;
		next_char = get_next_char(fd);
		i = i + 1;
		if (i % (READ_SIZE + 1) == 0)
			str = my_realloc(str, i + READ_SIZE + 1);
	}
	str[i] = '\0';
	if (next_char == '\0' && str[0] == '\0')
		return (NULL);
	return (str);
}
