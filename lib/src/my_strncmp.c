/*
** my_strcmp.c for my_strcmp in /home/landai_n/rendu/Piscine-C-Jour_06
** 
** Made by Nathanael Landais
** Login   <landai_n@epitech.net>
** 
** Started on  Mon Oct  7 15:43:26 2013 Nathanael Landais
** Last update Fri Dec 13 21:17:51 2013 Nathanael Landais
*/

#include "my_elem.h"

int	my_strncmp(char *s1, char *s2, int n)
{
  int	i;
  int	result;

  i = 0;
  while (s1[i] != 0 && s2[i] != 0 && i < n)
    {
      if (s1[i] != s2[i])
	return (1);
      i++;
    }
  if (i < n)
    return (1);
  return (0);
}
