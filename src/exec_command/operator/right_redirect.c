/*
** right_redirect.c for my_sh in /home/landai_n/rendu/Unix/PSU_2013_minishell2/src/exec_command
** 
** Made by Nathanael Landais
** Login   <landai_n@epitech.net>
** 
** Started on  Sun Mar  9 00:43:31 2014 Nathanael Landais
** Last update Sun Mar  9 22:38:10 2014 Nathanael Landais
*/

#include	<sys/types.h>
#include	<sys/stat.h>
#include	<fcntl.h>
#include	"my_sh.h"

int		simple_rredirect(int fildes[], char *path)
{
  char		*clean_path;

  if (fildes[2] != R_REDIRECT)
    return (0);
  if ((clean_path = clean_str(path, " \t")) == NULL)
    return (is_error(ERROR_MALLOC));
  if ((fildes[0] = open(clean_path, O_CREAT | O_RDWR | O_TRUNC, 0644)) == -1)
    {
      my_printf(ERROR_NOFILDIR, clean_path);
      return (-1);
    }
  if (dup2(fildes[0], 1) == -1)
    return (is_error(ERROR_REDIRECT));
  close(fildes[0]);
  return (0);
}

int		double_rredirect(int fildes[], char *path)
{
  char		*clean_path;

  if (fildes[2] != DR_REDIRECT)
    return (0);
  if ((clean_path = clean_str(path, " \t")) == NULL)
    return (is_error(ERROR_MALLOC));
  if ((fildes[0] = open(clean_path, O_CREAT | O_RDWR | O_APPEND, 0644)) == -1)
    {
      my_printf(ERROR_NOFILDIR, clean_path);
      return (-1);
    }
  if (dup2(fildes[0], 1) == -1)
    return (is_error(ERROR_REDIRECT));
  return (0);
}
