/*
** my_exit.c for my_sh in /home/landai_n/rendu/PSU_2013_minishell
** 
** Made by Nathanael Landais
** Login   <landai_n@epitech.net>
** 
** Started on  Sun Dec 15 16:07:38 2013 Nathanael Landais
** Last update Mon Dec 16 14:26:29 2013 Nathanael Landais
*/

#include "my_sh.h"

int	my_exit(char **arg, int *run, int *return_value)
{
  *return_value = 0;
  if (arg[1] != NULL)
    *return_value = to_nbr(arg[1]);
  *run = 0;
  return (0);
}
