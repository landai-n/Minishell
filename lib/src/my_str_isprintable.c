/*
** my_str_isprintable.c for my_elem in /home/landai_n/rendu/PSU_2013_minishell/lib/src
** 
** Made by Nathanael Landais
** Login   <landai_n@epitech.net>
** 
** Started on  Tue Dec 17 00:07:50 2013 Nathanael Landais
** Last update Tue Dec 17 00:14:38 2013 Nathanael Landais
*/

#include <stdlib.h>

int	my_str_isprintable(char *str)
{
  if (str == NULL)
    return (0);
  while (*str)
    {
      if (!((*str > 7 && *str < 14) || (*str > 31 && *str < 127)))
	return (0);
      str++;
    }
  return (1);
}
