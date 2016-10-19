/*
** hash_table.h for my_sh in /home/landai_n/rendu/Unix/PSU_2013_minishell2/includes
** 
** Made by Nathanael Landais
** Login   <landai_n@epitech.net>
** 
** Started on  Tue Feb 18 14:55:30 2014 Nathanael Landais
** Last update Sun Feb 23 18:09:57 2014 Nathanael Landais
*/

typedef	struct		s_hashtable
{
  char			*path;
  char			*name;
  struct s_hashtable	*next;
  int			used;
}			t_hashtable;
