/*
** get_nbrelem.c for my_sh in /home/landai_n/rendu/PSU_2013_minishell
** 
** Made by Nathanael Landais
** Login   <landai_n@epitech.net>
** 
** Started on  Fri Dec 13 20:22:59 2013 Nathanael Landais
** Last update Fri Dec 13 20:24:44 2013 Nathanael Landais
*/

#include "my_sh.h"

int	get_nbrelem(char **env)
{
  int	i;

  i = 0;
  while (env[i++] != NULL);
  return (i);
}
