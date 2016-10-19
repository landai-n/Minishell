/*
** my_strcat.c for my_elem in /home/landai_n/rendu/PSU_2013_minishell/lib/src
** 
** Made by Nathanael Landais
** Login   <landai_n@epitech.net>
** 
** Started on  Thu Dec 12 23:07:04 2013 Nathanael Landais
** Last update Sun Dec 15 15:30:33 2013 Nathanael Landais
*/

#include <stdlib.h>
#include "my_elem.h"

char	*my_strcat(char *str1, char *str2)
{
  char	*cat;
  int	i;

  i = 0;
  if (str1 == NULL || str2 == NULL)
    return (NULL);
  if ((cat = malloc(my_strlen(str1) + my_strlen(str2) * sizeof(cat))) == NULL)
    return (NULL);
  while (*str1 != 0)
    {
      cat[i++] = *str1;
      str1++;
    }
  while (*str2 != 0)
    {
      cat[i++] = *str2;
      str2++;
    }
  cat[i] = 0;
  return (cat);
}
