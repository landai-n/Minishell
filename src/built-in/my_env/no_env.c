/*
** no_env.c for my_sh in /home/landai_n/rendu/PSU_2013_minishell/src/built-in/my_env
** 
** Made by Nathanael Landais
** Login   <landai_n@epitech.net>
** 
** Started on  Tue Dec 17 20:06:16 2013 Nathanael Landais
** Last update Sun Mar  9 17:03:25 2014 Nathanael Landais
*/

#include "my_sh.h"

void	no_env(char **env, char **arg)
{
  char	**empty;
  char	**path;
  char	*command;
  int	run;

  if ((empty = malloc(sizeof(*empty))) == NULL)
    {
      is_error(ERROR_MALLOC);
      return ;
    }
  *empty = NULL;
  path = get_arg(get_var(env, PATH_VAR), "=:");
  if (arg[2] != NULL)
    {
      command = get_str(arg + 2);
      interpret_command(empty, command, &run);
      free(command);
    }
  free(path);
  free(empty);
}
