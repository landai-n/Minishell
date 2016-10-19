/*
** my_prompt.c for mysh in /home/landai_n/rendu/PSU_2013_minishell/src
** 
** Made by Nathanael Landais
** Login   <landai_n@epitech.net>
** 
** Started on  Thu Dec 12 16:11:17 2013 Nathanael Landais
** Last update Sun Mar  9 17:43:19 2014 Nathanael Landais
*/

#include "my_sh.h"

char	*prompt(char *msg)
{
  char	*command;

  command = NULL;
  while (is_empty(command))
    {
      command = NULL;
      my_putstr(msg);
      intercept_sig();
      command = get_nxtline(0);
      if (command == NULL)
	{
	  my_putstrl("exit");
	  return (NULL);
	}
    }
  return (command);
}
