/*
** my_cdhome.c for my_sh in /home/landai_n/rendu/PSU_2013_minishell/src/built-in/my_cd
** 
** Made by Nathanael Landais
** Login   <landai_n@epitech.net>
** 
** Started on  Mon Dec 16 23:32:01 2013 Nathanael Landais
** Last update Tue Dec 17 14:16:14 2013 Nathanael Landais
*/

#include "my_sh.h"

char     *my_cdhome(char **env)
{
  char	**arg;
  char	*path;

  arg = get_arg(get_var(env, HOME_VAR), "=");
  path = my_strdup(arg[1]);
  if (path == NULL)
    is_error(ERROR_MALLOC);
  free(*arg);
  free(arg);
  return (path);
}
