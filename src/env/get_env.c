/*
** edit_env.c for my_sh in /home/landai_n/rendu/PSU_2013_minishell/src/utils
** 
** Made by Nathanael Landais
** Login   <landai_n@epitech.net>
** 
** Started on  Sun Dec 15 16:45:12 2013 Nathanael Landais
** Last update Sun Dec 15 17:40:46 2013 Nathanael Landais
*/

#include "my_sh.h"

char	*get_env(char **env, char *var)
{
  int	c;
  int	l;

  c = 0;
  l = 0;
  if (*env == NULL || var == NULL)
    return (NULL);
  while (env[l] != NULL && my_strncmp(env[l], var, my_strlen(var) - 1) != 0)
    l++;
  if (env[l] == NULL)
    return (NULL);
  while (env[l][c] != '\0' && env[l][c] != '=')
    c++;
  if (env[l][c] != '\0')
    c++;
  return (env[l] + c);
}
