/*
** my_put_tab.c for put_tab in /home/leandre
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Fri Feb 24 16:25:21 2017 Léandre Blanchard
** Last update Fri Feb 24 16:26:16 2017 Léandre Blanchard
*/

#include <unistd.h>
#include "my.h"

void		my_put_tab(char **tab)
{
  int		i;

  i = 0;
  while (tab[i] != NULL)
    my_printf("%s\n", tab[i++]);
}
