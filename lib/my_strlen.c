/*
** my_strlen.c for my_strlen in /home/lblanchard/CPool_Day04
** 
** Made by Leandre Blanchard
** Login   <lblanchard@epitech.net>
** 
** Started on  Thu Oct  6 19:01:09 2016 Leandre Blanchard
** Last update Fri Feb 24 21:11:48 2017 Léandre Blanchard
*/

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i] && i < 2147483647)
    i++;
  return (i);
}
