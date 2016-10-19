/*
** my_printf.c for my_printf in /home/landai_n/rendu/PSU_2013_my_printf
** 
** Made by Nathanael Landais
** Login   <landai_n@epitech.net>
** 
** Started on  Tue Nov 12 15:48:23 2013 Nathanael Landais
** Last update Sun Mar  9 00:35:30 2014 Nathanael Landais
*/

#include <stdarg.h>
#include "my_elem.h"

int     check_str(char *str, int *i, va_list *ap)
{
  if (str[*i] == 's')
    {
      my_putstr(va_arg(*ap, char *));
      return (0);
    }
  if (str[*i] == 'd')
    {
      my_putnbr(va_arg(*ap, int));
      return (0);
    }
  return (1);
}

void		my_printf(char *str, ...)
{
  va_list	ap;
  char		prev_charac;
  int		i;
  int		to_print;
  int		escape;

  prev_charac = 0;
  i = 0;
  escape = 0;
  va_start(ap, str);
  while (str[i])
    {
      to_print = 1;
      if (prev_charac == '%' && !escape)
	to_print = check_str(str, &i, &ap);
      if (prev_charac == '%' && to_print == 1 && !escape)
	my_putchar('%');
      if (to_print && str[i] != '%')
	my_putchar(str[i]);
      escape = (prev_charac == '%' && str[i] == '%' && !escape);
      prev_charac = str[i++];
    }
  va_end(ap);
}
