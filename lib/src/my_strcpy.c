/*
** my_strcpy.c for my_elem in /home/landai_n/rendu/PSU_2013_minishell/lib/src
** 
** Made by Nathanael Landais
** Login   <landai_n@epitech.net>
** 
** Started on  Thu Dec 12 22:04:08 2013 Nathanael Landais
** Last update Mon Dec 16 13:59:10 2013 Nathanael Landais
*/

char	*my_strcpy(char *dest, char *src)
{
  int	i;

  i = 0;
  if (!dest || !src)
    return (0);
  while (src[i])
    dest[i] = src[i++];
  dest[i] = 0;
  return (dest);
}
