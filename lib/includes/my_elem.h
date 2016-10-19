/*
** my_elem.h for my_elem in /home/landai_n/rendu/PSU_2013_minishell/src/lib
** 
** Made by Nathanael Landais
** Login   <landai_n@epitech.net>
** 
** Started on  Thu Dec 12 21:41:57 2013 Nathanael Landais
** Last update Sun Mar  9 17:32:33 2014 Nathanael Landais
*/

#ifndef		__MY_ELEM_H__
# define	__MY_ELEM_H__

#define		MEMSIZE		128

int		get_nextline(int file, char **str);
void		*my_memset(char *var, int value, int size);
int		my_strlen(char *str);
int		my_strnlen(char *str, char c);
int		my_str_isprintable(char *str);
void		my_putstrl(char *str);
void		my_putchar(char c);
void		my_putstr(char *str);
char		*my_realloc(char *str, int new_size);
char		*my_strcpy(char *dest, char *src);
int		my_strcmp(char *s1, char *s2);
char		*my_strcat(char *str1, char *str2);
int		my_strncmp(char *s1, char *s2, int n);
char		*my_strdup(char *src);
int		to_nbr(char *str);
void		my_printf(char *str, ...);
int		my_strcontain(char *str, char c);
void		my_putnbr(int nbr);
char            *clean_str(char *str, char *to_rm);
int             my_match(char *str, char *to_compare);

#endif
