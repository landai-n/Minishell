/*
** my_realloc.c for get_next_line in /home/landai_n/rendu/get_next_line/get_next_line-2018-landai_n
** 
** Made by Nathanael Landais
** Login   <landai_n@epitech.net>
** 
** Started on  Thu Nov 21 14:07:27 2013 Nathanael Landais
** Last update Fri Dec 13 22:03:17 2013 Nathanael Landais
*/

#include <stdlib.h>
#include "my_elem.h"

char	*my_realloc(char *str, int new_size)
{
  char	*new_str;

  if ((new_str = malloc(new_size)) == NULL)
    return (NULL);
  my_memset(new_str, 1, new_size);
  my_strcpy(new_str, str);
  free(str);
  return (new_str);
}
