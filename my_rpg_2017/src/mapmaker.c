
/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** rpg
*/

#include "../include/my.h"
#include "../include/lib.h"

float **chararray_to_intarray(char **mapi, s_struct *all)
{
	all->map.map = malloc(sizeof(float *) * all->map.nbchar * all->map.line + 1);

	for (int tamp = 0; tamp != all->map.line; tamp++) {
		all->map.map[tamp] = malloc(sizeof(int *) * all->map.nbchar + 1);
		for(int temp = 0; temp != all->map.nbchar; temp++) {
			all->map.map[tamp][temp] = mapi[tamp][temp] - 48;
		}
	}
	return (all->map.map);
}

float **txt_to_char(FILE *fd, s_struct *all)
{
	char *mapc[1024];
	char *array = NULL;
	size_t size = 0;
	ssize_t read = 0;
	all->map.line = 0;
	all->map.nbchar = 0;

	for(all->map.line = 0; (read = getline(&array,&size,fd)) != -1; all->map.line++) {
		if (all->map.line == 0)
			all->map.nbchar = read-1;
		mapc[all->map.line] = malloc(sizeof(char) * all->map.nbchar+2);
		my_strcpy(mapc[all->map.line],array);
		mapc[all->map.line][all->map.nbchar + 1] = 0;
	}
	mapc[all->map.line] = 0;
	fclose (fd);
	free (array);
	float **tmp = chararray_to_intarray(mapc,all);
	for (int i = 0; i < all->map.line; i += 1)
		free(mapc[i]);
	return (tmp);
}
