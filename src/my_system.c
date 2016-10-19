/*
** my_system.c for my_sh in /home/landai_n/rendu/PSU_2013_minishell/src
** 
** Made by Nathanael Landais
** Login   <landai_n@epitech.net>
** 
** Started on  Thu Dec 12 23:36:09 2013 Nathanael Landais
** Last update Sun Mar  9 16:01:34 2014 Nathanael Landais
*/

#include	<sys/types.h>
#include	<sys/wait.h>
#include	<unistd.h>
#include	"my_sh.h"

int		my_system(char **env, char **command, int fildes[], int *work)
{
  t_command	actual_command;
  int		pid;

  if (get_commandinfo(command, env, &actual_command) == -1)
    return (-1);
  if (actual_command.bin == NULL)
    return (1);
  pid = fork();
  if (pid == 0)
    call_command(fildes, &actual_command, env);
  wait(work);
  free(actual_command.arg[0]);
  free(actual_command.arg);
  if (pid == -1)
    return (is_error(ERROR_FORK));
  if (*work == 139)
    is_error(ERROR_SEGFAULT);
  return (0);
}
