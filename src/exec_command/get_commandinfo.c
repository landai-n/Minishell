/*
** get_commandinfo.c for my_sh in /home/landai_n/rendu/Unix/PSU_2013_minishell2/src/exec_command
** 
** Made by Nathanael Landais
** Login   <landai_n@epitech.net>
** 
** Started on  Sun Mar  9 15:53:38 2014 Nathanael Landais
** Last update Sun Mar  9 16:02:02 2014 Nathanael Landais
*/

#include	"my_sh.h"

int		get_commandinfo(char **command, char **env, t_command *actual)
{
  char          **path;

  actual->arg = get_arg(*command, " \t");
  path = get_arg(get_var(env, PATH_VAR), "=:");
  if (actual->arg == NULL || path == NULL)
    return (is_error(ERROR_MALLOC));
  actual->bin = get_bin(path, actual->arg[0]);
  actual->next = *(command + 1);
  free(*path);
  free(path);
  return (0);
}
