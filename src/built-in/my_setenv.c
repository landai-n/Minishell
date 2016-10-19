/*
** my_export.c for my_sh in /home/landai_n/rendu/PSU_2013_minishell/src/built-in
** 
** Made by Nathanael Landais
** Login   <landai_n@epitech.net>
** 
** Started on  Fri Dec 13 17:12:27 2013 Nathanael Landais
** Last update Sun Mar  9 17:05:34 2014 Nathanael Landais
*/

#include "my_sh.h"

int	my_setenv(char **env, char **arg)
{
  char	*temp;
  char	*temp2;
  char	*value;
  int	nbr;

  value = NULL;
  if (arg[1] == NULL)
    return (my_env(env, arg));
  value = (arg[2] == NULL) ? " " : arg[2];
  nbr = 0;
  temp = my_strcat(arg[1], "=");
  temp2 = my_strcat(temp, value);
  free(temp);
  my_unsetenv(env, arg);
  while (env[nbr++] != NULL);
  env[nbr - 1] = temp2;
  env[nbr] = NULL;
  return (0);
}
