/*
** get_sep.c for my_sh in /home/landai_n/rendu/Unix/PSU_2013_minishell2/src/exec_command
** 
** Made by Nathanael Landais
** Login   <landai_n@epitech.net>
** 
** Started on  Thu Mar  6 19:23:12 2014 Nathanael Landais
** Last update Sun Mar  9 18:53:03 2014 Nathanael Landais
*/

#include	"my_sh.h"

char		replace_sep(char c)
{
  if (c == RREDIR_CHAR)
    return (DRREDIR_CHAR);
  if (c == LREDIR_CHAR)
    return (DLREDIR_CHAR);
  return (c);
}

char		*get_sep(char *str, char *sep)
{
  int		nbr;
  char		*list;
  int		i;

  nbr = get_nbr_arg(str, sep);
  i = 0;
  if ((list = malloc(sizeof(char) * nbr + 1)) == NULL)
    return (NULL);
  while (i < nbr && *str)
    {
      if (is_sep(sep, *str))
	{
	  list[i] = *str;
	  if (*(str + 1) == *str)
	    list[i] = replace_sep(*str++);
	  i++;
	}
      str++;
    }
  list[i] = 0;
  return (list);
}
