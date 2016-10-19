/*
** my_strdup.c for my_strdup in /home/landai_n/rendu/Piscine-C-Jour_08/ex_01
** 
** Made by Nathanael Landais
** Login   <landai_n@epitech.net>
** 
** Started on  Wed Oct  9 09:17:56 2013 Nathanael Landais
** Last update Fri Feb 21 21:34:24 2014 Nathanael Landais
*/

#include <stdlib.h>

char	*my_strdup(const char *src)
{
  int	length;
  char	*s1;

  if (src == NULL)
    return (NULL);
  length = my_strlen(src) + 2;
  s1 = malloc(length * sizeof(*s1));
  my_strcpy(s1, src);
  return (s1);
}
