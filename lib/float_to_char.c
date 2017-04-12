/*
** float_to_char.c for float_to_char in /home/lblanchard/PSU_2016_my_printf
** 
** Made by Leandre Blanchard
** Login   <lblanchard@epitech.net>
** 
** Started on  Wed Nov  9 12:26:31 2016 Leandre Blanchard
** Last update Wed Mar 15 19:42:01 2017 Léandre Blanchard
*/

#include "my_printf.h"

void		my_put_nbr(long long);
void		my_putchar(int);

int		ret_zeros(int nb)
{
  while (nb % 10 == 0)
    nb /= 10;
  return (nb);
}

void		my_put_float(double nbr)
{
  long		integer;
  long		floating;
  double	dec;

  if (nbr == 0)
    {
      my_put_nbr(0);
      return;
    }
  integer = (int)nbr;
  my_put_nbr(integer);
  dec = nbr - integer;
  dec *= 10000000;
  my_putchar('.');
  floating = (int)dec;
  if (floating % 10 >= 5)
    {
      floating /= 10;
      floating += 1;
    }
  else
    floating /= 10;
  if (floating < 0)
    floating *= (-1);
  my_put_nbr(floating);
}
