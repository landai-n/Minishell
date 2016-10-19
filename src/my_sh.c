/*
** mysh.c for mysh in /home/landai_n/rendu/PSU_2013_minishell/src
** 
** Made by Nathanael Landais
** Login   <landai_n@epitech.net>
** 
** Started on  Thu Dec 12 15:19:54 2013 Nathanael Landais
** Last update Fri Mar  7 20:06:21 2014 Nathanael Landais
*/

#include	"my_sh.h"

int		my_sh(char **env)
{
  char		*buffer;
  char		*prompt_msg;
  int		run;
  int		return_value;

  buffer = NULL;
  run = 1;
  return_value = 0;
  prompt_msg = get_promptmsg(env);
  while (run == 1)
    {
      if ((buffer = prompt(prompt_msg)) == NULL)
	break ;
      return_value = interpret_command(env, buffer, &run);
      free(buffer);
    }
  free(prompt_msg);
  return (return_value);
}
