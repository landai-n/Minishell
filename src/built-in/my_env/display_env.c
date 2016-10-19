/*
** my_displayenv.c for my_sh in /home/landai_n/rendu/PSU_2013_minishell/src/built-in/my_env
** 
** Made by Nathanael Landais
** Login   <landai_n@epitech.net>
** 
** Started on  Tue Dec 17 19:56:28 2013 Nathanael Landais
** Last update Tue Dec 17 19:57:18 2013 Nathanael Landais
*/

#include "my_sh.h"

void	display_env(char **env)
{
  while (*env != NULL)
    {
      my_putstrl(*env);
      env++;
    }
}
