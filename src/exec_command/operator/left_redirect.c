/*
** left_redirect.c for my_sh in /home/landai_n/rendu/PSU_2013_minishell2/src/exec_command/operator
** 
** Made by Nathanael Landais
** Login   <landai_n@epitech.net>
** 
** Started on  Sun Mar  9 19:16:54 2014 Nathanael Landais
** Last update Sun Mar  9 23:04:26 2014 Nathanael Landais
*/

#include        <sys/types.h>
#include        <sys/stat.h>
#include        <fcntl.h>
#include	"my_sh.h"

int		simple_lredirect(int fildes[], char *path)
{
  char          *clean_path;

  if (fildes[2] != L_REDIRECT)
    return (0);
  if ((clean_path = clean_str(path, " \t")) == NULL)
    return (is_error(ERROR_MALLOC));
  if ((fildes[0] = open(clean_path, O_RDONLY)) == -1)
    {
      my_printf(ERROR_NOFILDIR, clean_path);
      return (-1);
    }
  if (dup2(fildes[0], 0) == -1)
    return (is_error(ERROR_REDIRECT));
  return (0);
}

int		double_lredirect(int fildes[], char *word)
{
  char		*actual;
  char		*clean_word;

  if (fildes[2] != DL_REDIRECT)
    return (0);
  if ((clean_word = clean_str(word, " \t")) == NULL)
    return (is_error(ERROR_MALLOC));
  my_putstr("> ");
  while ((actual = get_nxtline(0)) != NULL && my_strcmp(actual, clean_word))
    my_putstr("> ");
  free(clean_word);
  if (actual == NULL)
    return (is_error(ERROR_READ));
  return (0);
}
