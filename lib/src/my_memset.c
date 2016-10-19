/*
** my_memset.c for my_elem in /home/landai_n/rendu/Prog-elem/get_next_line-2018-landai_n/Lib/src
** 
** Made by Nathanael Landais
** Login   <landai_n@epitech.net>
** 
** Started on  Wed Dec  4 21:07:35 2013 Nathanael Landais
** Last update Wed Dec  4 21:47:20 2013 Nathanael Landais
*/

void	my_memset(char *var, int value, int size)
{
  int	i;

  i = 0;
  while (i < size - 1)
    var[i++] = value;
  var[i] = 0;
}
