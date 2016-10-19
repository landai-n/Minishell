/*
** my_strcontain.c for my_elem in /home/landai_n/rendu/PSU_2013_minishell/lib/src
** 
** Made by Nathanael Landais
** Login   <landai_n@epitech.net>
** 
** Started on  Thu Dec 19 11:25:37 2013 Nathanael Landais
** Last update Sun Mar  9 22:51:08 2014 Nathanael Landais
*/

#include	<stdlib.h>

int		my_strcontain(char *str, char c)
{
  if (str == NULL)
    return (0);
  while (*str)
    {
      if (*str == c)
	return (1);
      str++;
    }
  return (0);
}
