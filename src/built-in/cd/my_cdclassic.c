/*
** my_cdclassic.c for my_sh in /home/landai_n/rendu/PSU_2013_minishell/src/built-in/my_cd
** 
** Made by Nathanael Landais
** Login   <landai_n@epitech.net>
** 
** Started on  Mon Dec 16 23:33:59 2013 Nathanael Landais
** Last update Mon Dec 16 23:52:26 2013 Nathanael Landais
*/

#include "my_sh.h"

char	*my_cdclassic(char **arg)
{
  char	*path;

  path = my_strdup(arg[1]);
  if (path == NULL)
    is_error(ERROR_MALLOC);
  return (path);
}
