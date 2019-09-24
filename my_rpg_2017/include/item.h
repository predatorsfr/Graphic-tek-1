/*
** EPITECH PROJECT, 2018
** item.h
** File description:
** my_rpg
*/
#include "stats.h"
#include "my.h"
#include "lib.h"

/***********/
/**struct**/
/**********/

typedef struct s_armor
{
	char *name;
	int lvl;
	int damage;
	int cost;
}t_armor;

typedef struct item item;

struct item
{
        char *name_item;
        int lvl;
        int damage;
        int heal;
        int cost_in_effect;
        item *next;
};

typedef struct inventory
{
        item *first_item;
}inventory;

char *good_value(char *value, item *now);
stats init_gamer(stats);
int		wolf(s_struct *all, inventory *inventory, stats player);
void		insertion(inventory *inventory, char *name, int lvl, int damage, int cost);
void		save_inventory(inventory *inventory);
void		init_inventory(inventory *inventory);
void		add_item(char *name, inventory *inventory);
char *get_next_line(int);
inventory	*initialisation_inventory();
s_struct *load_text_1(s_struct *all, item *now);
s_struct *load_text_2(s_struct *all, item *now);
s_struct *load_text_3(s_struct *all, item *now);
s_struct *load_text_4(s_struct *all, item *now);
s_struct *load_text_5(s_struct *all, item *now);
s_struct *load_text_6(s_struct *all, item *now);
s_struct *load_text_7(s_struct *all, item *now);
s_struct *load_text_8(s_struct *all, item *now);
s_struct *load_text_9(s_struct *all, item *now);
s_struct *load_text_10(s_struct *all, item *now);
s_struct *load_text_11(s_struct *all, item *now);
