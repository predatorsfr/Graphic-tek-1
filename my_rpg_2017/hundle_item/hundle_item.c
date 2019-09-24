/*
** EPITECH PROJECT, 2018
** hundle_item.c
** File description:
** my_rpg
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "../include/item.h"
#include "../include/lib.h"
#include "../include/my.h"
#include "../include/get_next_line.h"

inventory *initialisation_inventory()
{
	inventory *inventory = malloc(sizeof(*inventory));
	item *item = malloc(sizeof(*item));

	if (inventory == NULL || item == NULL)
		return (NULL);
	item->name_item = NULL;
	item->lvl = 0;
	item->damage = 0;
	item->cost_in_effect = 0;
	item->next = NULL;
	inventory->first_item = item;
	return inventory;
}

void insertion(inventory *inventory, char *name, int lvl, int damage, int cost)
{
	item *new_item = malloc(sizeof(*new_item));

	if (inventory == NULL || new_item == NULL)
		return;
	new_item->name_item = malloc(sizeof(char) * my_strlen(name) + 1);
	new_item->name_item = my_strcpy(new_item->name_item, name);
	new_item->lvl = lvl;
	new_item->damage = damage;
	new_item->cost_in_effect = cost;
	new_item->next = inventory->first_item;
	inventory->first_item = new_item;
}

void save_inventory(inventory *inventory)
{
	item *now;
	int fd = open("hundle_item/Inventory", O_CREAT | O_TRUNC | O_RDWR, 0664);


	if (inventory == NULL)
		return;
	now = inventory->first_item;
	while (now->name_item != NULL) {
		write(fd, now->name_item, my_strlen(now->name_item));
		write(fd, "\n", 1);
		now = now->next;
	}
}

void init_inventory(inventory *inventory)
{
	int fd = open("hundle_item/Inventory", O_RDWR);
	char *s = get_next_line(fd);
	int i = 0;
	t_armor armor1[] = {{"wood_sword", 1, 5, 3},{"dagger_fall", 2, 10, 3},
	{"katana", 3, 12, 5},{"iron_sword", 4, 15, 6},{"ax of attila", 5, 18, 14},
			   {"ax of perdition", 6, 20, 20},{"claymor_sword",7, 23, 20},
			   {"excalibur", 8, 25, 5},{"lightsaber", 10, 30, 10},
			   {"vigor_potion", 0, 10, 0}, {"life_potion", 0, 10, 0},
			   {"vigor_hyperpotion", 0, 20, 0},{"life_hyperpotion", 0, 20, 0},{NULL}};

	while (s != NULL) {
		i = 0;
		while (my_strcmp(s, armor1[i].name) == 1 && armor1[i].name != NULL)
			 i++;
		insertion(inventory, armor1[i].name, armor1[i].lvl,armor1[i].damage, armor1[i].cost);
		free(s);
		s = get_next_line(fd);
	}
}

void add_item(char *name, inventory *inventory)
{
    int i = 0;
		t_armor armor[] = {{"wood_sword", 1, 5, 3},{"dagger_fall", 2, 10, 3},
		{"katana", 3, 12, 5},{"iron_sword", 4, 15, 6},{"ax of attila", 5, 18, 14},
			{"ax of perdition", 6, 20, 20},{"claymor_sword",7, 23, 20},
			{"excalibur", 8, 25, 5},{"lightsaber", 10, 30, 10},
			{"vigor_potion", 0, 10, 0}, {"life_potion", 0, 10, 0},
			{"vigor_hyperpotion", 0, 20, 0},{"life_hyperpotion", 0, 20, 0},{NULL}};


		while (my_strcmp(name, armor[i].name) != 0 && armor[i].name != NULL)
			i++;
		insertion(inventory, armor[i].name, armor[i].lvl, armor[i].damage, armor[i].cost);
}
