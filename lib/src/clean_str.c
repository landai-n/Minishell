/*
** clean_str.c for my_elem in /home/landai_n/rendu/Unix/PSU_2013_minishell2/lib/src
** 
** Made by Nathanael Landais
** Login   <landai_n@epitech.net>
** 
** Started on  Sun Mar  9 15:27:08 2014 Nathanael Landais
** Last update Sun Mar  9 15:30:36 2014 Nathanael Landais
*/

#include	<stdlib.h>
#include	"my_elem.h"

char		*clean_str(char *str, char *to_rm)
{
  char		*new;
  int		i;

  if ((new = malloc(sizeof(*str) * my_strlen(str))) == NULL)
    return (NULL);
  i = 0;
  while (*str)
    {
      if (!my_strcontain(to_rm, *str))
	new[i++] = *str;
      str++;
    }
  new[i] = 0;
  return (new);
}
