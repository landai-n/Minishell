/*
** copy_var.c for my_sh in /home/landai_n/rendu/PSU_2013_minishell/src/get
** 
** Made by Nathanael Landais
** Login   <landai_n@epitech.net>
** 
** Started on  Fri Dec 13 23:49:47 2013 Nathanael Landais
** Last update Tue Dec 17 17:45:52 2013 Nathanael Landais
*/

#include "my_sh.h"

int	copy_var(char **env, char *src, char *dest)
{
  char	*var;
  char	**arg;
  char	**args;

  var = get_var(env, src);
  arg = get_arg(var, "=");
  if ((args = malloc(4 * sizeof(*args))) == NULL)
    return (!is_error(ERROR_MALLOC));
  args[0] = CMD_SETENV;
  args[1] = dest;
  args[2] = arg[1];
  args[3] = NULL;
  my_setenv(env, args);
  free(*arg);
  free(arg);
  free(args);
  return (0);
}
