##
## EPITECH PROJECT, 2017
## makefile
## File description:
##
##

SRC	=	main.c \
		./src/init.c \
		./src/mapmaker.c\
		./src/draw.c \
		./src/itoa.c \
		./src/wordtab.c \
		./src/math.c \
		./src/menu.c \
		./src/get_next_line.c\
		lib/my_strdup.c\
		lib/my_strlen.c \
		lib/my_strcpy.c\
		lib/my_atoi.c\
		lib/my_strcmp.c\
		warning/hitbox1.c\
		warning/hitbox2.c\
		hundle_item/hundle_item.c\
		hundle_stat/stat.c\
		./src/intro.c\
		./src/npc_dialog.c\
		./src/fight.c\

OBJ	=	$(SRC:.c=.o)

CC	=	gcc -g3  -l c_graph_prog -lm

NAME	=	my_rpg

all:		$(NAME)

$(NAME):	$(OBJ)
		$(CC) $(SRC) -o $(NAME)
clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)
		rm -f *~
		rm -f src/*~
		rm -f include/*~

re:		fclean all

.PHONY :	all clean fclean re
