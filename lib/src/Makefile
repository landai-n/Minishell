##
## Makefile for my_elem in /home/landai_n/rendu/PSU_2013_minishell/src/lib
## 
## Made by Nathanael Landais
## Login   <landai_n@epitech.net>
## 
## Started on  Thu Dec 12 21:45:48 2013 Nathanael Landais
## Last update Sun Mar  9 17:34:29 2014 Nathanael Landais
##

SRC		=	my_putstr.c		\
			my_putstrl.c		\
			my_str_isprintable.c	\
			my_putchar.c		\
			my_strcontain.c		\
			my_strlen.c		\
			my_strnlen.c		\
			my_printf.c		\
			my_memset.c		\
			my_realloc.c		\
			my_strcmp.c		\
			my_strcat.c		\
			my_strdup.c		\
			my_strncmp.c		\
			my_strcpy.c		\
			my_putnbr.c		\
			to_nbr.c		\
			clean_str.c		\
			get_nxtline.c

OBJ		=	$(SRC:.c=.o)

INCLUDE		=	-I ../includes/

NAME		=	libmy_elem.a

all:	$(NAME)

$(NAME):
	cc -c $(SRC) $(INCLUDE)
	ar rvs $(NAME) $(OBJ)
	ranlib $(NAME)
	mv $(NAME) ../bin

clean:
	rm $(OBJ)

fclean: clean
	rm -f ../bin/$(NAME)

re:	fclean all
