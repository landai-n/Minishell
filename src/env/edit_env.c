/*
** edit_env.c for my_sh in /home/landai_n/rendu/PSU_2013_minishell/src/utils
** 
** Made by Nathanael Landais
** Login   <landai_n@epitech.net>
** 
** Started on  Sun Dec 15 16:45:12 2013 Nathanael Landais
** Last update Tue Dec 17 18:02:46 2013 Nathanael Landais
*/

#include "my_sh.h"

int	edit_env(char **env, char *var, char *value)
{
  char	*command;
  char	*temp;
  char	**arg;

  if (var == NULL || value == NULL)
    return (1);
  command = my_strdup(". ");
  temp = my_strcat(command, var);
  free(command);
  command = my_strcat(temp, " ");
  free(temp);
  temp = my_strcat(command, value);
  free(command);
  arg = get_arg(temp, " \t");
  my_setenv(env, arg);
  free(temp);
  free(*arg);
  free(arg);
  return (0);
}
