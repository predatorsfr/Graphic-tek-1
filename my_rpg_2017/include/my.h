/*
** EPITECH PROJECT, 2017
** my_h
** File description:
** my_h
*/

# ifndef MY_H
# define MY_H

# define WIDTH		1024
# define HEIGHT		600

/////////////
/////SFML////
/////////////
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/Graphics/Export.h>
#include <SFML/Graphics/Color.h>
#include <SFML/Graphics/Rect.h>
#include <SFML/Graphics/Types.h>
#include <SFML/Graphics/PrimitiveType.h>
#include <SFML/Graphics/RenderStates.h>
#include <SFML/Graphics/Vertex.h>
#include <SFML/Window/Event.h>
#include <SFML/Window/Export.h>
#include <SFML/Window/Joystick.h>
#include <SFML/Window/Keyboard.h>
#include <SFML/Window/Mouse.h>
#include <SFML/Window/Sensor.h>
#include <SFML/Window/VideoMode.h>
#include <SFML/Window/WindowHandle.h>
#include <SFML/Window/Window.h>
#include <SFML/System/Vector2.h>
#include <stddef.h>

/////////////
//other_fct//
/////////////
#include <wait.h>
#include <math.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
/////////////
////Struct///
/////////////

struct map_t {
  int line;
  ssize_t nbchar;
  float **map;
  float	**map2;
} map_t;

struct		s_data
{
  int mapx;
  int mapy;
  double front_speed;
  double rot_speed;
  double x_pos;
  double y_pos;
  double x_dir;
  double y_dir;
  double x_cam;
  double y_cam;
  int x;
  int intro;
} t_data;

struct		s_ray
{
  int			x_win;
  double		cam_x;
  double		ray_x;
  double		ray_y;
  double		dir_x;
  double		dir_y;
  int			*steps;
  double		*sides;
  int			*pos_i;
  int			is_side;
}	t_ray;

struct		s_rend
{
  sfRenderWindow	*win;
  sfTexture		*texture;
  sfSprite		*sprite;
}	t_rend;

struct  s_text
{
  sfTexture *t_hitbox;
  sfSprite *s_hitbox;
  sfVector2f p_hitbox;
  sfTexture *t_fight;
  sfSprite *s_fight;
  sfTexture *t_skeleton;
  sfSprite *s_skeleton;
  sfVector2f p_skeleton;
  sfTexture *t_bckgrnd;
  sfSprite *s_bckgrnd;
  sfTexture *t_dialog;
  sfSprite *s_dialog;
  sfVector2f p_dialog;
  sfTexture *t_little;
  sfSprite *s_little;
  sfVector2f p_little;
  sfVector2f p_bckgrnd;
  sfTexture *t_bar;
  sfSprite *s_bar;
  sfVector2f p_bar;
  float se_first_pnj;
  sfSprite *s_first_pnj;
  sfTexture *t_first_pnj;
  sfClock *c_first_pnj;
  sfVector2f m_first_pnj;
  sfVector2f p_first_pnj;
  sfTime ti_first_pnj;
} s_text;

struct s_string
{
  sfText *life;
  sfVector2f val_stat;
  sfText *stat;
  sfText *vig;
  sfText *lvl;
  sfText *dmg;
  sfText *name;
  sfText *skeleton;
  sfVector2f p_skeleton;
  sfText *text1;
  sfText *text2;
  sfText *text3;
  sfText *text4;
  sfText *text5;
  sfText *text6;
  sfText *text7;
  sfText *text8;
  sfText *text9;
  sfText *text10;
  sfText *text11;
  sfText *text12;
  sfText *text13;
  sfText *diag1;
  sfText *space;
  sfText *quit;
  sfFont *font;
  sfVector2f pos;
  sfVector2f p_space;
  sfVector2f p_diag;
  sfVector2i mouse;
  sfVector2f ext;
  sfVector2f val_lvl;
  sfVector2f val_life;
  sfVector2f val_dmg;
  sfVector2f val_vig;
  sfVector2f val_name;
	sfVector2f scale;
  char **text;
} s_string;

typedef struct s_struct
{
  struct s_string string;
  struct s_text text;
  struct s_rend render;
  struct s_ray ray;
  struct s_data data;
  struct map_t map;
} s_struct;

s_struct *init_text(s_struct *all);
void wait_five(s_struct *all);
void start_dialog(s_struct *all);
int ini_text(s_struct *all);
char		*my_strcpy(char *dest, char *src);
int fight_detection(s_struct *all);
int pnj_case_intro(s_struct *all);
char *my_strcpy2(char *dest, char *src);
int		my_strlen(char const *str);
char		*my_strdup(char const *str);
void		my_put_pixel(sfUint8 *, int, int, sfColor);
void		my_draw_line(sfUint8 *, sfVector2i, sfVector2i, sfColor);
sfUint8*	create_pixel_buffer(int, int);
sfRenderWindow	*create_window(char *, int, int);
s_struct *init_render(s_struct *all);
int init_data(s_struct *all);
s_struct *fill_ray(s_struct *all, int);
double		grab_wall_dist(s_struct *all, double dx, double dy, int hit);
double		get_wall_dist(s_struct *all, double dx, double dy);
sfColor		choose_color(s_struct *all);
void		draw_ray(s_struct *all, sfUint8* pixels);
void		mov_cam(s_struct *all, int);
void		rot_cam(s_struct *all, int);
float **txt_to_char(FILE *fd, s_struct *all);
int		**get_file(int, int *, int *);
int		**convfile(char **, int, int);
char		*realloc_and_add(char *, char);
void		my_putchar(char c);
void		my_isneg(int nb);
void		my_put_nbr(int nb);
void		my_swap(int *a, int *b);
int		my_putstr(char const *str);
void		my_getnbr(char const *str);
void		my_sort_int_array(int *tab, int size);
int		my_compute_power_rec(int nb, int power);
int		my_compute_square_root(int nb);
int		my_is_prime(int nb);
int		my_find_prime_sup(int nb);
char		*my_strncpy(char *dest, char const *src, int n);
char		*my_revstr(char *str);
char		*my_strstr(char *str, char const *to_find);
int		my_strcmp(char *s1, char *s2);
int		my_strncmp(char const *s1, char const *s2, int n);
char		*my_strupcase(char *str);
char		*my_strlowcase(char *str);
char		*my_strcapitalize(char *str);
int		my_str_isalpha(char const *str);
int		my_str_isnum(char const *str);
int		my_str_islower(char const *str);
int		my_str_isupper(char const *str);
int		my_str_isprintable(char const *str);
int		my_showstr(char const *str);
int		my_showmem(char const *str, int size);
char		*my_strcat(char *dest, char *src);
char		*my_strncat(char *dest, char const *src, int nb);
int		count_substrac(char const *str);
int		get_strlen(char const *str);
int		Pos_or_Neg(int nb);
void		set_first_upper(char *str, int i);
void		set_all_lower(char *str, int i);
int		check_str(char const *str, char const *to_find);
int		cat(int ac, char **av);
char		*standard_output();
void		infin_add(char *s1, char *s2);
int		get_all_nbr(char *str);
char		**parse(char *str);
char		**my_str_to_word_array(char *str);
int		count_words(char *str);
int	start_game(void);
char *itoa(int, char *);
char **count_input(char *);
#endif
