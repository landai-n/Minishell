/*
** call_command.c for my_sh in /home/landai_n/rendu/Unix/PSU_2013_minishell2/src/exec_command
** 
** Made by Nathanael Landais
** Login   <landai_n@epitech.net>
** 
** Started on  Sat Mar  8 22:36:50 2014 Nathanael Landais
** Last update Sun Mar  9 20:15:51 2014 Nathanael Landais
*/

#include "my_sh.h"

int		call_command(int fildes[], t_command *command, char **env)
{
  if (redirect_pipe(fildes) == -1)
    exit(-1);
  if (simple_rredirect(fildes, command->next) == -1)
    exit(-1);
  if (double_rredirect(fildes, command->next) == -1)
    exit(-1);
  if (simple_lredirect(fildes, command->next) == -1)
    exit(-1);
  if (double_lredirect(fildes, command->next) == -1)
    exit(-1);
  if (execve(command->bin, command->arg, env) == -1)
    exit(is_error(ERROR_UNDFND));
  return (0);
}
