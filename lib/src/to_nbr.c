/*
** my_getnbr.c for my_getnbr in /home/landai_n/rendu/Piscine-C-lib/my
** 
** Made by Nathanael Landais
** Login   <landai_n@epitech.net>
** 
** Started on  Mon Oct 21 11:36:28 2013 Nathanael Landais
** Last update Sun Dec  8 22:09:13 2013 Nathanael Landais
*/

int	is_num(char c)
{
  if (c >= '0' && c <= '9')
    return (1);
  return (0);
}

int	neg(char *str)
{
  int	i;
  int	count;

  i = 0;
  count = 0;
  while (str[i] > '9' || str[i] < '0')
  {
    if (str[i] == '-')
      count++;
    i++;
  }
  if (count % 2 != 0)
    return (1);
  return (0);
}

int	to_nbr(char *str)
{
  int	i;
  int	nbr;

  nbr = 0;
  i = 0;
  if (!is_num(str[i]) && str[i] != '-' && str[i] != '+')
    return (0);
  while (is_num(str[i]))
  {
    nbr = ((nbr * 10) + (str[i] - '0'));
    i++;
  }
  if (neg(str) == 1)
    nbr = -nbr;
  return (nbr);
}
