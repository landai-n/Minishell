/*
** get_operator.c for my_sh in /home/landai_n/rendu/Unix/PSU_2013_minishell2/src/exec_command/operator
** 
** Made by Nathanael Landais
** Login   <landai_n@epitech.net>
** 
** Started on  Sun Mar  9 16:34:58 2014 Nathanael Landais
** Last update Sun Mar  9 20:12:29 2014 Nathanael Landais
*/

#include	"my_sh.h"

int		get_operator(char *sep, int i, int fildes[])
{
  if (get_pipe(sep, i++, fildes) == -1)
    return (-1);
  if (i > 0 && sep[i - 1] == RREDIR_CHAR)
    fildes[2] = R_REDIRECT;
  if (i > 0 && sep[i - 1] == DRREDIR_CHAR)
    fildes[2] = DR_REDIRECT;
  if (i > 0 && sep[i - 1] == LREDIR_CHAR)
    fildes[2] = L_REDIRECT;
  if (i > 0 && sep[i - 1] == DLREDIR_CHAR)
    fildes[2] = DL_REDIRECT;
  return (0);
}
