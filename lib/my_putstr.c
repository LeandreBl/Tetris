/*
** my_putstr.c for my_putstr in /home/lblanchard/CPool_Day04
** 
** Made by Leandre Blanchard
** Login   <lblanchard@epitech.net>
** 
** Started on  Thu Oct  6 11:19:22 2016 Leandre Blanchard
** Last update Fri Feb 24 21:06:08 2017 Léandre Blanchard
*/

#include <unistd.h>
#include <stdlib.h>

int	my_strlen(char *);

int	my_putstr(char *str)
{
  if (str != NULL)
    write(1, str, my_strlen(str));
  else
    my_putstr("NULL");
  return (0);
}
