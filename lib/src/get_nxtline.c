/*
** get_line.c for my_elem in /home/landai_n/rendu/Prog-elem/get_next_line-2018-landai_n
** 
** Made by Nathanael Landais
** Login   <landai_n@epitech.net>
** 
** Started on  Wed Dec  4 20:56:00 2013 Nathanael Landais
** Last update Sun Mar  9 17:48:49 2014 Nathanael Landais
*/

#include <stdlib.h>
#include "my_elem.h"

int	eol(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    if (str[i++] == '\n')
      return (i);
  return (0);
}

char	*term_read(char *str_more, int *byte, char *str)
{
  my_memset(str_more, 0, MEMSIZE - 1);
  if (*byte == -1)
    {
      free(str);
      *byte = 1;
      return ("\0");
    }
  *byte = 1;
  return (NULL);
}

void	get_more(char *str, char *more)
{
  while (*str && *str != '\n')
    str++;
  if (!(*str))
    return ;
  str++;
  my_memset(more, '0', MEMSIZE);
  my_strcpy(more, str);
}

char		*get_nxtline(int file)
{
  static char	str_more[MEMSIZE];
  char		*str;
  static int	byte = 1;
  int		size;
  int		size_str;

  if (byte <= 0 || (str = malloc(MEMSIZE)) == NULL)
    return (term_read(str_more, &byte, str));
  my_memset(str, 1, MEMSIZE);
  size_str = 0;
  my_strcpy(str, str_more);
  size_str = my_strlen(str);
  while (!(size = eol(str)) && byte)
    {
      str = my_realloc(str, size_str + MEMSIZE);
      if ((byte = read(file, str + size_str, MEMSIZE - 1)) <= 0)
	return (term_read(str_more, &byte, str));
      str[size_str + byte] = 0;
      size_str = my_strlen(str);
    }
  get_more(str, str_more);
  if (size < 2)
    size = size_str + 1;
  str[size - 1] = 0;
  return (str);
}
