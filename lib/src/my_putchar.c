/*
** my_putchar.c for my_elem in /home/landai_n/rendu/PSU_2013_minishell/lib/src
** 
** Made by Nathanael Landais
** Login   <landai_n@epitech.net>
** 
** Started on  Mon Dec 16 18:31:15 2013 Nathanael Landais
** Last update Mon Dec 16 18:31:39 2013 Nathanael Landais
*/

void	my_putchar(char c)
{
  write(1, &c, 1);
}
