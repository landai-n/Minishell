/*
** get_var.c for my_sh in /home/landai_n/rendu/PSU_2013_minishell/src
** 
** Made by Nathanael Landais
** Login   <landai_n@epitech.net>
** 
** Started on  Thu Dec 12 22:54:15 2013 Nathanael Landais
** Last update Mon Dec 16 16:49:53 2013 Nathanael Landais
*/

#include "my_sh.h"

char	*get_var(char **env, char *var)
{
  int	i;

  i = 0;
  while (env[i] != NULL && my_strncmp(var, env[i], my_strlen(var)) != 0)
    i++;
  if (env[i] == NULL)
    edit_env(env, var, "/");
  return (env[i]);
}
