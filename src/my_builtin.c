/*
** my_builtin.c for my_sh in /home/landai_n/rendu/PSU_2013_minishell/src
** 
** Made by Nathanael Landais
** Login   <landai_n@epitech.net>
** 
** Started on  Fri Dec 13 16:24:04 2013 Nathanael Landais
** Last update Sun Mar  9 17:04:01 2014 Nathanael Landais
*/

#include "my_sh.h"

int	my_builtin(char **env, char *command, int *run, int *return_value)
{
  char	**arg;
  int	is_builtin;

  if (command == NULL)
    return (0);
  arg = get_arg(command, " \t");
  is_builtin = 1;
  if (my_strcmp(CMD_ENV, *arg) == 0)
    is_builtin = my_env(env, arg);
  if (my_strcmp(CMD_SETENV, *arg) == 0)
    is_builtin = my_setenv(env, arg);
  if (my_strcmp(CMD_UNSETENV, *arg) == 0)
    is_builtin = my_unsetenv(env, arg);
  if (my_strcmp(CMD_CD, *arg) == 0)
    is_builtin = my_cd(env, arg);
  if (my_strcmp(CMD_EXIT, *arg) == 0)
    is_builtin = my_exit(arg, run, return_value);
  if (my_strcmp(CMD_HASH, *arg) == 0)
    is_builtin = my_hash(arg);
  free(*arg);
  free(arg);
  return (is_builtin);
}
