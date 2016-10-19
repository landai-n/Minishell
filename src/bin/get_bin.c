/*
** get_bin.c for my_sh in /home/landai_n/rendu/PSU_2013_minishell/src
** 
** Made by Nathanael Landais
** Login   <landai_n@epitech.net>
** 
** Started on  Thu Dec 12 22:37:31 2013 Nathanael Landais
** Last update Sun Feb 23 19:05:28 2014 Nathanael Landais
*/

#include <unistd.h>
#include "my_sh.h"

char			*get_bin(char **path, char *name)
{
  static t_hashtable    *table = NULL;
  char			*bin;

  if (my_strcontain(name, '/'))
    return (get_localbin(name));
  if (my_strcmp(name, CMD_HASH) == 0)
    return ((char *)table);
  if (path == NULL)
    return (NULL);
  if ((bin = find_elem_table(table, name)) != NULL)
    return (bin);
  if ((bin = find_bin(path, name)) == NULL)
    return (NULL);
  if (table == NULL)
    table = add_elem_table(table, name, bin);
  else
    add_elem_table(table, name, bin);
  return (bin);
}

char	*find_bin(char **path, char *name)
{
  char	*bin;
  char	*temp;
  int	ac;

  if ((bin = my_strdup(" ")) == NULL)
    return (NULL);
  while ((ac = access(bin, X_OK)) == -1 && *path != NULL)
    {
      temp = my_strcat(*path++, "/");
      free(bin);
      bin = my_strcat(temp, name);
      free(temp);
    }
  if (ac != -1)
    return (bin);
  free(bin);
  return (NULL);
}
