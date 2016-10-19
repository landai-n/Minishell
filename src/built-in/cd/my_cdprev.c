/*
** my_cdprev.c for my_sh in /home/landai_n/rendu/PSU_2013_minishell/src/built-in/my_cd
** 
** Made by Nathanael Landais
** Login   <landai_n@epitech.net>
** 
** Started on  Mon Dec 16 23:32:36 2013 Nathanael Landais
** Last update Mon Dec 16 23:52:58 2013 Nathanael Landais
*/

#include "my_sh.h"

char	*my_cdprev(char **env)
{
  char	*path;

  path = my_strdup(get_env(env, PREV_PWD_VAR));
  if (path == NULL)
    {
      is_error(ERROR_NO_PDIR);
      return (NULL);
    }
  else
    my_putstrl(path);
  return (path);
}
