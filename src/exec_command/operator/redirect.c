/*
** redirect.c for my_sh in /home/landai_n/rendu/Unix/PSU_2013_minishell2/src/exec_command/operator
** 
** Made by Nathanael Landais
** Login   <landai_n@epitech.net>
** 
** Started on  Sun Mar  9 16:32:06 2014 Nathanael Landais
** Last update Sun Mar  9 22:41:51 2014 Nathanael Landais
*/

#include	"my_sh.h"

void		close_redirect(int fildes[], char ***command)
{
  if (fildes[2] == R_REDIRECT || fildes[2] == DR_REDIRECT || \
      fildes[2] == DL_REDIRECT || fildes[2] == L_REDIRECT)
    {
      if (*(*command + 1) != NULL)
	(*command)++;
      fildes[2] = NO_PIPE;
    }
}
