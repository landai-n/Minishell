/*
** is_empty.c for my_sh in /home/landai_n/rendu/PSU_2013_minishell/src/utils
** 
** Made by Nathanael Landais
** Login   <landai_n@epitech.net>
** 
** Started on  Sun Dec 15 15:17:35 2013 Nathanael Landais
** Last update Sun Dec 15 15:28:15 2013 Nathanael Landais
*/

#include "my_sh.h"

int	is_empty(char *str)
{
  int	i;

  i = 0;
  if (str == NULL || *str == '\n')
    return (1);
  while (str[i] != '\0')
    {
      if (str[i] != ' ' && str[i] != '\t')
	return (0);
      i++;
    }
  return (1);
}
