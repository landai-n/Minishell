##
## Makefile for my_sh in /home/landai_n/rendu/PSU_2013_minishell
## 
## Made by Nathanael Landais
## Login   <landai_n@epitech.net>
## 
## Started on  Thu Dec 12 15:31:21 2013 Nathanael Landais
## Last update Sun Mar  9 22:18:57 2014 Nathanael Landais
##

SRC		=	src/main.c					\
			src/my_builtin.c				\
			src/my_system.c					\
			src/my_sh.c					\
			src/bin/complete_path.c				\
			src/bin/get_bin.c				\
			src/bin/get_localbin.c				\
			src/bin/add_elem_table.c			\
			src/bin/find_elem_table.c			\
			src/built-in/my_exit.c				\
			src/built-in/my_setenv.c			\
			src/built-in/my_unsetenv.c			\
			src/built-in/cd/my_cd.c				\
			src/built-in/cd/my_cdclassic.c			\
			src/built-in/cd/my_cdhome.c			\
			src/built-in/cd/my_cdprev.c			\
			src/built-in/cd/save_current_dir.c		\
			src/built-in/my_env/display_env.c		\
			src/built-in/my_env/my_env.c			\
			src/built-in/my_env/no_env.c			\
			src/built-in/my_hash.c				\
			src/env/edit_env.c				\
			src/env/get_env.c				\
			src/env/get_nbrelem.c				\
			src/env/var/copy_var.c				\
			src/env/var/get_var.c				\
			src/prompt/get_promptmsg.c			\
			src/prompt/prompt.c				\
			src/exec_command/interpret_command.c		\
			src/exec_command/get_sep.c			\
			src/exec_command/call_command.c			\
			src/exec_command/get_commandinfo.c		\
			src/exec_command/operator/right_redirect.c	\
			src/exec_command/operator/left_redirect.c	\
			src/exec_command/operator/pipe.c		\
			src/exec_command/operator/redirect.c		\
			src/exec_command/operator/get_operator.c	\
			src/utils/get_arg.c				\
			src/utils/get_str.c				\
			src/utils/is_empty.c				\
			src/utils/is_error.c				\
			src/utils/signal/intercept_sig.c		\
			src/utils/signal/my_sig.c			\

INCLUDE		=	-I includes/					\
			-I lib/includes/

LIB		=	-L lib/bin/

OBJS		=	$(SRC:.c=.o)

LFLAGS		=	-lmy_elem

CFLAGS		=	-W -Wall -Wextra -Wshadow -Werror $(INCLUDE)

NAME		=	mysh

all:		$(NAME)

$(NAME):	$(OBJS)
	@cc -o $(NAME) $(OBJS) $(INCLUDE) $(LIB) $(LFLAGS)
	@rm -f $(OBJS)

clean:
	rm -f $(OBJS)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
