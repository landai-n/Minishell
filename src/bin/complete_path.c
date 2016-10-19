/*
** complete_path.c for my_sh in /home/landai_n/rendu/PSU_2013_minishell/src/utils
** 
** Made by Nathanael Landais
** Login   <landai_n@epitech.net>
** 
** Started on  Sun Dec 15 21:24:50 2013 Nathanael Landais
** Last update Tue Dec 17 14:15:19 2013 Nathanael Landais
*/

#include "my_sh.h"

char	*complete_path(char **env, char *path)
{
  int	home;
  char	**arg;

  home = 0;
  if (*path == '~')
    {
      path++;
      home = 1;
    }
  if (home == 1)
    {
      arg = get_arg(get_var(env, HOME_VAR), "=");
      path = my_strcat(arg[1], path);
      free(*arg);
      free(arg);
    }
  return (path);
}
