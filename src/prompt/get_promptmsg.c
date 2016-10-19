/*
** get_promptmsg.c for my_sh in /home/landai_n/rendu/PSU_2013_minishell/src/get
** 
** Made by Nathanael Landais
** Login   <landai_n@epitech.net>
** 
** Started on  Wed Dec 18 22:43:45 2013 Nathanael Landais
** Last update Wed Dec 18 22:58:00 2013 Nathanael Landais
*/

#include "my_sh.h"

char	*get_promptmsg(char **env)
{
  char	**var;
  char	*name;
  char	*temp;

  var = get_arg(get_var(env, USER_VAR), "=");
  if (var == NULL || var[0] == NULL)
    return (my_strdup(PROMPT_MSG));
  if (var[1] == NULL || *var[1] == '/')
    {
      free(*var);
      free(var);
      return (my_strdup(PROMPT_MSG));
    }
  temp = my_strdup("(");
  name = my_strcat(temp, var[1]);
  free(temp);
  temp = my_strcat(name, ")");
  free(name);
  free(*var);
  free(var);
  return (temp);
}
