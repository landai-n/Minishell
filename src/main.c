/*
** main.c for my_sh in /home/landai_n/rendu/PSU_2013_minishell/src
** 
** Made by Nathanael Landais
** Login   <landai_n@epitech.net>
** 
** Started on  Thu Dec 12 15:30:38 2013 Nathanael Landais
** Last update Mon Jan  6 23:38:22 2014 Nathanael Landais
*/

#include "my_sh.h"

int	main(int argc, char **argv, char **env)
{
  if (*env == NULL)
    is_error(ERROR_NO_ENV);
  if (argc && *argv)
    return(my_sh(env));
  return (0);
}
