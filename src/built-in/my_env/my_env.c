/*
** my_env.c for my_sh in /home/landai_n/rendu/PSU_2013_minishell/src/built-in
** 
** Made by Nathanael Landais
** Login   <landai_n@epitech.net>
** 
** Started on  Fri Dec 13 16:50:05 2013 Nathanael Landais
** Last update Sun Mar  9 17:05:57 2014 Nathanael Landais
*/

#include "my_sh.h"

int	my_env(char **env, char **arg)
{
  if (arg[1] == NULL)
    display_env(env);
  else
    if (my_strcmp(arg[1], "-i") == 0)
      no_env(env, arg);
  else
    is_error(ENV_USAGE);
  return (0);
}
