/*
** my_hash.c for my_sh in /home/landai_n/rendu/Unix/PSU_2013_minishell2/src/built-in/my_hash
** 
** Made by Nathanael Landais
** Login   <landai_n@epitech.net>
** 
** Started on  Sun Feb 23 18:17:55 2014 Nathanael Landais
** Last update Sun Feb 23 18:55:56 2014 Nathanael Landais
*/

#include "my_sh.h"

int		my_hash(char **arg)
{
  t_hashtable	*table;

  table = (t_hashtable *)get_bin(NULL, CMD_HASH);
  if (table == NULL)
    {
      is_error(ERROR_HASHEMPTY);
      return (0);
    }
  if (arg[1] == NULL)
    aff_hashtable(table);
  else
    if (my_strcmp(arg[1], "-r") == 0)
      reset_hashtable(table);
    else
      is_error(HASH_USAGE);
  return (0);
}

void		aff_hashtable(t_hashtable *table)
{
  my_putstr(HASH_HEADER);
  if (table->path == NULL)
    table = table->next;
  while (table != NULL)
    {
      my_putnbr(table->used);
      my_putchar('\t');
      my_putstr(table->path);
      my_putchar('\n');
      table = table->next;
    }
}

void		reset_hashtable(t_hashtable *table)
{
  t_hashtable	*prev;

  table->path = NULL;
  table->name = NULL;
  table->next = NULL;
  table = table->next;
  while (table != NULL)
    {
      prev = table;
      free(table->name);
      free(table->path);
      table = table->next;
      free(prev);
    }
}
