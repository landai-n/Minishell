/*
** is_error.c for my_sh in /home/landai_n/rendu/PSU_2013_minishell
** 
** Made by Nathanael Landais
** Login   <landai_n@epitech.net>
** 
** Started on  Fri Dec 13 11:44:22 2013 Nathanael Landais
** Last update Sun Feb 23 19:40:54 2014 Nathanael Landais
*/

#include "my_sh.h"

int	is_error(char *error)
{
  write(2, error, my_strlen(error));
  write(2, "\n", 1);
  return (1);
}
