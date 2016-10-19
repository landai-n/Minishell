/*
** create_table.c for my_sh in /home/landai_n/rendu/Unix/PSU_2013_minishell2/src/bin
** 
** Made by Nathanael Landais
** Login   <landai_n@epitech.net>
** 
** Started on  Fri Feb 21 22:14:15 2014 Nathanael Landais
** Last update Sun Feb 23 18:10:10 2014 Nathanael Landais
*/

#include	"my_sh.h"

t_hashtable	*add_elem_table(t_hashtable *table, char *name, char *bin)
{
  if (table == NULL)
    {
      if ((table = malloc(sizeof(t_hashtable))) == NULL)
	return (NULL);
    }
  else
    {
      while (table->next != NULL)
	table = table->next;
      if ((table->next = malloc(sizeof(t_hashtable))) == NULL)
	{
	  is_error(ERROR_MALLOC);
	  return (NULL);
	}
      table = table->next;
    }
  table->path = bin;
  table->name = my_strdup(name);
  table->used = 1;
  table->next = NULL;
  return (table);
}
