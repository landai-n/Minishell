/*
** my_unsetenv.c for my_sh in /home/landai_n/rendu/PSU_2013_minishell
** 
** Made by Nathanael Landais
** Login   <landai_n@epitech.net>
** 
** Started on  Fri Dec 13 20:59:05 2013 Nathanael Landais
** Last update Fri Dec 13 21:24:19 2013 Nathanael Landais
*/

#include "my_sh.h"

int	my_unsetenv(char **env, char **arg)
{
  int	i;

  i = 0;
  if (arg[1] == NULL)
    return (!is_error(ERROR_NBR_ARG));
  while (env[i] != NULL)
    {
      if (my_strncmp(env[i], arg[1], my_strnlen(env[i], '=')) == 0)
	{
	  while (env[i] != NULL)
	    {
	      env[i] = env[i + 1];
	      i++;
	    }
	  i = 0;
	}
      i++;
    }
  return (0);
}
