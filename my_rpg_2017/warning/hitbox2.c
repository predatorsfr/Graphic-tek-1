/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** rpg
*/

#include "../include/my.h"
#include "../include/item.h"
#include "../include/lib.h"
#include "../include/get_next_line.h"
#include "../include/menu.h"

s_struct *load_text_6(s_struct *all, item *now)
{
	char *value;

		sfText_setPosition(all->string.text6, all->string.pos);
		if (now->name_item == NULL)
			sfText_setString(all->string.text6, "(EMPTY)");
		else {
					value = malloc(sizeof(char) * 100 + my_strlen(now->name_item));
					value = good_value(value, now);
					sfText_setString(all->string.text6, value);
				}
return (all);
}

s_struct *load_text_7(s_struct *all, item *now)
{
	char *value;

		sfText_setPosition(all->string.text7, all->string.pos);
		if (now->name_item == NULL)
			sfText_setString(all->string.text7, "(EMPTY)");
		else {
					value = malloc(sizeof(char) * 100 + my_strlen(now->name_item));
					printf("lol\n");
					value = good_value(value, now);
					sfText_setString(all->string.text7, value);
				}
return (all);
}

s_struct *load_text_8(s_struct *all, item *now)
{
	char *value;

		sfText_setPosition(all->string.text8, all->string.pos);
		if (now->name_item == NULL)
			sfText_setString(all->string.text8, "(EMPTY)");
		else {
					value = malloc(sizeof(char) * 100 + my_strlen(now->name_item));
					printf("lol\n");
					value = good_value(value, now);
					sfText_setString(all->string.text8, value);
				}
return (all);
}

s_struct *load_text_9(s_struct *all, item *now)
{
	char *value;

		sfText_setPosition(all->string.text9, all->string.pos);
		if (now->name_item == NULL)
			sfText_setString(all->string.text9, "(EMPTY)");
		else {
					value = malloc(sizeof(char) * 100 + my_strlen(now->name_item));
					printf("lol\n");
					value = good_value(value, now);
					sfText_setString(all->string.text9, value);
				}
return (all);
}

s_struct *load_text_10(s_struct *all, item *now)
{
	char *value;

		sfText_setPosition(all->string.text10, all->string.pos);
		if (now->name_item == NULL)
			sfText_setString(all->string.text10, "(EMPTY)");
		else {
					value = malloc(sizeof(char) * 100 + my_strlen(now->name_item));
					printf("lol\n");
					value = good_value(value, now);
					sfText_setString(all->string.text10, value);
				}
return (all);
}
s_struct *load_text_11(s_struct *all, item *now)
{
	char *value;

		sfText_setPosition(all->string.text11, all->string.pos);
		if (now->name_item == NULL)
			sfText_setString(all->string.text11, "(EMPTY)");
		else {
					value = malloc(sizeof(char) * 100 + my_strlen(now->name_item));
					printf("lol\n");
					value = good_value(value, now);
					sfText_setString(all->string.text11, value);
				}
return (all);
}
