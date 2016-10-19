/*
** save_current_dir.c for my_sh in /home/landai_n/rendu/PSU_2013_minishell
** 
** Made by Nathanael Landais
** Login   <landai_n@epitech.net>
** 
** Started on  Sun Dec 15 16:38:10 2013 Nathanael Landais
** Last update Tue Dec 17 14:31:49 2013 Nathanael Landais
*/

#include "my_sh.h"

void	save_current_dir(char **env, char *path)
{
  char	*temp;

  if (path[0] != '/')
    {
      temp = get_env(env, PWD_VAR);
      if (temp[my_strlen(temp) - 1] != '/')
	path = my_strcat("/", path);
      path = my_strcat(temp, path);
    }
  edit_env(env, PWD_VAR, path);
}
