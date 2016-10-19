/*
** get_str.c for my_sh in /home/landai_n/rendu/PSU_2013_minishell/src/get
** 
** Made by Nathanael Landais
** Login   <landai_n@epitech.net>
** 
** Started on  Thu Dec 19 17:28:54 2013 Nathanael Landais
** Last update Thu Dec 19 17:36:03 2013 Nathanael Landais
*/

#include "my_sh.h"

char	*get_str(char **arg)
{
  char	*str;
  char	*temp;

  str = my_strdup(*arg);
  arg++;
  while (*arg != NULL)
    {
      temp = my_strcat(str, " ");
      free(str);
      str = my_strcat(temp, *arg);
      free(temp);
      arg++;
    }
  return (str);
}
