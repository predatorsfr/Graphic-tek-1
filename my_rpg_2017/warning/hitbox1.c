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

char *good_value(char *value, item *now)
{
	char *number = malloc(sizeof(char) * 40);
	char *number2 = malloc(sizeof(char) * 40);
	char *number3 = malloc(sizeof(char) * 4);
	char *name = malloc(sizeof(char)* my_strlen(now->name_item) + 5);

	name = my_strcpy(name, now->name_item);
	name = my_strcpy2(name, "\t\t\t\t\t\t\t\t\t");
	value = my_strcpy(value, name);
	number = itoa(now->cost_in_effect, number);
	number = my_strcpy2(number, "\t\t\t");
	value =  my_strcpy2(value, number);
	number2 = itoa(now->lvl, number);
	number2 = my_strcpy2(number2, "\t\t\t");
	value =  my_strcpy2(value, number2);
	number3 = itoa(now->damage, number3);
	value =  my_strcpy2(value, number3);
	free(name);
	return (value);
}

s_struct *load_text_1(s_struct *all, item *now)
{
	char *value = NULL;

		sfText_setPosition(all->string.text1, all->string.pos);
		if (now->name_item == NULL)
			sfText_setString(all->string.text1, "(EMPTY)");
		else {
			value = malloc(sizeof(char) * 100 + my_strlen(now->name_item));
			value = good_value(value, now);
			sfText_setString(all->string.text1, value);
		}
		free (value);
			return (all);
}

s_struct *load_text_2(s_struct *all, item *now)
{
	char *value;

		sfText_setPosition(all->string.text2, all->string.pos);
		if (now->name_item == NULL)
			sfText_setString(all->string.text2, "(EMPTY)");
		else {
				value = malloc(sizeof(char) * 100 + my_strlen(now->name_item));
				value = good_value(value, now);
				sfText_setString(all->string.text2, value);
			}
		return (all);
}

s_struct *load_text_3(s_struct *all, item *now)
{
	char *value;

		sfText_setPosition(all->string.text3, all->string.pos);
		if (now->name_item == NULL)
			sfText_setString(all->string.text3, "(EMPTY)");
		else {
				value = malloc(sizeof(char) * 100 + my_strlen(now->name_item));
				value = good_value(value, now);
				sfText_setString(all->string.text3, value);
			}
			return (all);
}

s_struct *load_text_4(s_struct *all, item *now)
{
	char *value;

		sfText_setPosition(all->string.text4, all->string.pos);
		if (now->name_item == NULL)
			sfText_setString(all->string.text4, "(EMPTY)");
		else {
				value = malloc(sizeof(char) * 100 + my_strlen(now->name_item));
				value = good_value(value, now);
				sfText_setString(all->string.text4, value);
			}
		return (all);
}

s_struct *load_text_5(s_struct *all, item *now)
{
	char *value;

		sfText_setPosition(all->string.text5, all->string.pos);
		if (now->name_item == NULL)
			sfText_setString(all->string.text5, "(EMPTY)");
		else {
				value  = malloc(sizeof(char) * 100 + my_strlen(now->name_item));
				value = good_value(value, now);
				sfText_setString(all->string.text5, value);
			}
		return (all);
}
