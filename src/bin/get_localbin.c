/*
** get_localbin.c for my_sh in /home/landai_n/rendu/PSU_2013_minishell/src/get
** 
** Made by Nathanael Landais
** Login   <landai_n@epitech.net>
** 
** Started on  Tue Dec 17 20:28:35 2013 Nathanael Landais
** Last update Tue Feb 18 14:52:23 2014 Nathanael Landais
*/

#include <unistd.h>
#include "my_sh.h"

char	*get_localbin(char *path)
{
  if (access(path, X_OK) == -1)
    return (NULL);
  return (my_strdup(path));
}
