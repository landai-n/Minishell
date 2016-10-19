/*
** interpret_command.c for my_sh in /home/landai_n/rendu/Unix/PSU_2013_minishell2/src/exec_command
** 
** Made by Nathanael Landais
** Login   <landai_n@epitech.net>
** 
** Started on  Sun Feb 23 19:10:17 2014 Nathanael Landais
** Last update Sun Mar  9 22:56:02 2014 Nathanael Landais
*/

#include	"my_sh.h"

int		interpret_command(char **env, char *buffer, int *run)
{
  int		return_value;
  char		**commands;
  char		*sep;
  int		i;

  commands = get_arg(buffer, SEPARATOR_LIST);
  sep = get_sep(buffer, SEPARATOR_LIST);
  if (sep == NULL || commands == NULL)
    return (is_error(ERROR_MALLOC));
  while (commands[i] != NULL)
    i++;
  if (i - 1 != my_strlen(sep))
    return (is_error(ERROR_SYNTAX));
  return_value = exec_command(env, commands, sep, run);
  free(*commands);
  free(commands);
  free(sep);
  return (return_value);
}

int		exec_command(char **env, char **commands, char *sep, int *run)
{
  int		return_value;
  int		i;
  int		fildes[3];
  int		work;

  return_value = 0;
  i = 0;
  while (*commands != NULL && *run)
    {
      if (get_operator(sep, i++, fildes) == -1)
	return (-1);
      if (my_builtin(env, *commands, run, &return_value) == 1)
        if (my_system(env, commands, fildes, &work) == 1)
          my_printf(ERROR_NOTFOUND, *commands);
      if (sep[i - 1] == AND_CHAR && work != 0)
	break ;
      close_pipe(fildes);
      close_redirect(fildes, &commands);
      commands++;
    }
  return (return_value);
}
