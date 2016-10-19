/*
** my_cd.c for my_sh in /home/landai_n/rendu/PSU_2013_minishell/src
** 
** Made by Nathanael Landais
** Login   <landai_n@epitech.net>
** 
** Started on  Fri Dec 13 22:40:02 2013 Nathanael Landais
** Last update Mon Dec 16 23:59:02 2013 Nathanael Landais
*/

#include <unistd.h>
#include "my_sh.h"

int	my_cd(char **env, char **arg)
{
  char	*path;

  if (arg[1] == NULL)
    path = my_cdhome(env);
  else
    if (my_strcmp(arg[1], "-") == 0)
      path = my_cdprev(env);
  else
    path = my_cdclassic(arg);
  if (path == NULL)
    return (0);
  if (copy_var(env, PWD_VAR, PREV_PWD_VAR) == 1)
    return (0);
  path = complete_path(env, path);
  if (chdir(path) == -1)
    is_error(ERROR_DIR_NFND);
  else
    save_current_dir(env, path);
  free(path);
  return (0);
}
