/*
** get_arg.c for my_sh in /home/landai_n/rendu/PSU_2013_minishell/src
** 
** Made by Nathanael Landais
** Login   <landai_n@epitech.net>
** 
** Started on  Thu Dec 12 21:10:03 2013 Nathanael Landais
** Last update Sun Feb 23 19:01:47 2014 Nathanael Landais
*/

#include "my_sh.h"

int	is_sep(char *seps, char c)
{
  int	i;

  i = 0;
  while (seps[i] != '\0')
    if (seps[i++] == c)
      return (1);
  return (0);
}

int	get_nbr_arg(char *str, char *seps)
{
  int	i;
  char	c;

  i = 0;
  c = seps[0];
  while ((*str) != 0)
    {
      if (!is_sep(seps, *str) && is_sep(seps, c))
	i++;
      c = *str;
      str++;
    }
  return (i);
}

char	**get_arg(char *command, char *seps)
{
  char	**arg;
  char	*str;
  char	c;
  int	i;

  if (command == NULL)
    return (NULL);
  while (*command != '\0' && is_sep(seps, *command))
    command++;
  str = my_strdup(command);
  if ((arg = malloc((get_nbr_arg(str, seps) + 1) * sizeof(*arg))) == NULL)
    return (NULL);
  c = seps[0];
  i = 0;
  while ((*str) != 0)
    {
      if (!is_sep(seps, *str) && (is_sep(seps, c) || c == 0))
	arg[i++] = str;
      if (is_sep(seps, *str) && (!is_sep(seps, c) && c != 0))
	*str = 0;
      c = *str;
      str++;
    }
  arg[i] = NULL;
  return (arg);
}
