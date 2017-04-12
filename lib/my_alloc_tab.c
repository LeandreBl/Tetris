/*
** my_alloc_tab.c for alloc_tab in /home/leandre/Games/Tetris
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Fri Mar 17 18:13:15 2017 Léandre Blanchard
** Last update Fri Mar 17 18:16:41 2017 Léandre Blanchard
*/

#include <stdlib.h>

void		zeros(char *, int);

char		**my_alloc_tab(int height, int width)
{
  char		**tab;
  int		i;

  i = 0;
  if ((tab = malloc(sizeof(char *) * height)) == NULL)
    return (NULL);
  while (i != height)
    {
      if ((tab[i] = malloc(sizeof(char) * width)) == NULL)
	return (NULL);
      zeros(tab[i], width);
      i++;
    }
  tab[height - 1] = NULL;
  return (tab);
}
