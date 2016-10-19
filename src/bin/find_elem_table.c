/*
** find_elem_table.c for my_sh in /home/landai_n/rendu/Unix/PSU_2013_minishell2/src/bin
** 
** Made by Nathanael Landais
** Login   <landai_n@epitech.net>
** 
** Started on  Sun Feb 23 16:37:03 2014 Nathanael Landais
** Last update Sun Feb 23 18:10:27 2014 Nathanael Landais
*/

#include "my_sh.h"

char	*find_elem_table(t_hashtable *table, char *name)
{
  while (table != NULL)
    {
      if (my_strcmp(table->name, name) == 0)
	{
	  table->used++;
	  return (table->path);
	}
      table = table->next;
    }
  return (NULL);
}
