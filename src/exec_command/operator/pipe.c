/*
** pipe.c for my_sh in /home/landai_n/rendu/Unix/PSU_2013_minishell2/src/exec_command
** 
** Made by Nathanael Landais
** Login   <landai_n@epitech.net>
** 
** Started on  Thu Mar  6 20:04:45 2014 Nathanael Landais
** Last update Sun Mar  9 23:12:22 2014 Nathanael Landais
*/

#include	"my_sh.h"

int		get_pipe(char *sep, int i, int fildes[])
{
  fildes[2] = NO_PIPE;
  if (i > 0 && sep[i - 1] == PIPE_CHAR)
    {
      if (sep[i] == PIPE_CHAR)
      	fildes[2] = MULTI_PIPE;
      else
	fildes[2] = OUTPUT_PIPE;
    }
  else
    if (sep[i] == PIPE_CHAR)
      {
	if (input_pipe(fildes) == -1)
	  return (-1);
      }
  return (0);
}

int		input_pipe(int fildes[])
{
  if (pipe(fildes) == -1)
    return (is_error(ERROR_PIPE));
  fildes[2] = INPUT_PIPE;
  return (0);
}

void		close_pipe(int fildes[])
{
  if (fildes[2] == OUTPUT_PIPE)
    dup2(0, fildes[0]);
  if (fildes[2] == INPUT_PIPE || fildes[2] == MULTI_PIPE)
    dup2(1, fildes[1]);
}

int		redirect_pipe(int fildes[])
{
  if (fildes[2] == OUTPUT_PIPE || fildes[2] == INPUT_PIPE)
    {
      if (fildes[2] == OUTPUT_PIPE)
	{
	  close(fildes[1]);
	  if (dup2(fildes[0], 0) == -1)
	    return (is_error(ERROR_PIPE));
	}
      else
	{
	  close(fildes[0]);
	  if (dup2(fildes[1], 1) == -1)
	    return (is_error(ERROR_PIPE));
	}
    }
  return (0);
}
