/*
** my_strnlen.c for my_elem in /home/landai_n/rendu/PSU_2013_minishell/lib/src
** 
** Made by Nathanael Landais
** Login   <landai_n@epitech.net>
** 
** Started on  Fri Dec 13 21:22:22 2013 Nathanael Landais
** Last update Fri Dec 13 21:23:07 2013 Nathanael Landais
*/

int	my_strnlen(char *str, char c)
{
  int	i;

  i = 0;
  while (str[i] != 0 && str[i] != c)
    i++;
  return (i);
}
