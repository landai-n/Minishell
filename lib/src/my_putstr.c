/*
** my_putstr.c for mysh in /home/landai_n/rendu/PSU_2013_minishell/src/lib
** 
** Made by Nathanael Landais
** Login   <landai_n@epitech.net>
** 
** Started on  Thu Dec 12 16:07:20 2013 Nathanael Landais
** Last update Sun Dec 15 15:03:02 2013 Nathanael Landais
*/

#include <stdlib.h>
#include "my_elem.h"

void	my_putstr(char *str)
{
  if (str == NULL)
    return ;
  while (*str)
    write(1, str++, 1);
}
