/*
** intercept_sig.c for my_sh in /home/landai_n/rendu/Unix/PSU_2013_minishell/src/utils
** 
** Made by Nathanael Landais
** Login   <landai_n@epitech.net>
** 
** Started on  Sun Jan  5 16:01:12 2014 Nathanael Landais
** Last update Sun Jan  5 16:05:18 2014 Nathanael Landais
*/

#include <signal.h>
#include "my_sh.h"

void	intercept_sig()
{
  if (signal(SIGINT, my_sig) == SIG_ERR)
    is_error(ERROR_SIG);
  if (signal(SIGTSTP, my_sig) == SIG_ERR)
    is_error(ERROR_SIG);
}
