/*
** my_putstr.c for mysh in /home/landai_n/rendu/PSU_2013_minishell/src/lib
** 
** Made by Nathanael Landais
** Login   <landai_n@epitech.net>
** 
** Started on  Thu Dec 12 16:07:20 2013 Nathanael Landais
** Last update Mon Dec 16 15:48:10 2013 Nathanael Landais
*/

#include <stdlib.h>
#include "my_elem.h"

void	my_putstrl(char *str)
{
  char	endl;

  endl = '\n';
  if (str == NULL)
    return ;
  while (*str)
    write(1, str++, 1);
  my_putstr("\n");
}
