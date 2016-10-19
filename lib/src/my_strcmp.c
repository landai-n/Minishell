/*
** my_strcmp.c for my_strcmp in /home/landai_n/rendu/Piscine-C-Jour_06
** 
** Made by Nathanael Landais
** Login   <landai_n@epitech.net>
** 
** Started on  Mon Oct  7 15:43:26 2013 Nathanael Landais
** Last update Sun Dec 15 14:58:09 2013 Nathanael Landais
*/

#include <stdlib.h>
#include "my_elem.h"

int	my_strcmp(char *s1, char *s2)
{
  int	i;
  int	result;

  i = 0;
  if (s1 == NULL || s2 == NULL)
    return (1);
  if (my_strlen(s1) != my_strlen(s2))
    return (1);
  while (s1[i] != 0 && s2[i] != 0)
    {
      if (s1[i] != s2[i])
	return (1);
      i++;
    }
  return (0);
}
