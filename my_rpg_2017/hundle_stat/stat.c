/*
** EPITECH PROJECT, 2018
** stat.c
** File description:
** my_rpg
*/
#include "../include/item.h"
#include "../include/my.h"

stats init_gamer(stats player)
{
	int fd = open("hundle_stat/Stats", O_RDWR);
	int i = 0;
	char *s = get_next_line(fd);
	char **tab = count_input(s);
	player.life =  malloc(sizeof(char) *my_strlen(tab[0]));
	player.vigor =  malloc(sizeof(char) *my_strlen(tab[1]));
	player.lvl = malloc(sizeof(char) *my_strlen(tab[2]));
	player.damage = malloc(sizeof(char) *my_strlen(tab[3]));

	player.life = my_strcpy(player.life, tab[0]);
	player.vigor = my_strcpy(player.vigor, tab[1]);
	player.lvl = my_strcpy(player.lvl, tab[2]);
	player.damage = my_strcpy(player.damage, tab[3]);
	free(s);
	return (player);
}

int lenght_list(inventory *inventory)
{
		int i = 0;
		item *now = inventory->first_item;

		while (now->name_item != NULL) {
			i++;
			now = now->next;
		}
		return (i);
}

stats change_stats(int i, inventory *inventory, stats player)
{
	int j = 0;
	int size = lenght_list(inventory);
	item *now = inventory->first_item;
	t_armor armor3[] = {{"wood_sword", 1, 5, 3},{"dagger_fall", 2, 10, 3},
	{"katana", 3, 12, 5},{"iron_sword", 4, 15, 6},{"ax of attila", 5, 18, 14},
		{"ax of perdition", 6, 20, 20},{"claymor_sword",7, 23, 20},
		{"excalibur", 8, 25, 5},{"lightsaber", 10, 30, 10},
		{NULL}};

	while (now->name_item != NULL && j < size - i) {
		if (now->name_item != NULL) {
				now = now->next;
				j++;
		}
	}
	j = 0;
	while (my_strcmp(armor3[j].name, now->name_item) != 0)
	 		j++;
			player.damage = itoa(armor3[j].damage, player.damage);
			return (player);
}

void save_stats(stats player)
{
	int fd = open("hundle_stat/Stats", O_CREAT | O_TRUNC | O_RDWR, 0664);

	write(fd, player.life, my_strlen(player.life));
	write(fd, player.vigor, my_strlen(player.vigor));
	write(fd, player.lvl, my_strlen(player.lvl));
	write(fd, player.damage, my_strlen(player.damage));
	return;
}
