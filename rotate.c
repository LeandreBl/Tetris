/*
** rotate.c for tetris in /home/leandre/Games/Tetris
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Thu Mar 23 14:05:50 2017 Léandre Blanchard
** Last update Thu Mar 23 15:09:06 2017 Léandre Blanchard
*/

#include "tetris.h"

char		**rotate(char **tet)
{
  char		**new;
  int		i;
  int		j;
  int		k;
  int		l;

  i = 0;
  if ((new = my_alloc_tab(max_len(tet) + 1, my_tablen(tet) + 1)) == NULL)
    return (NULL);
  k = my_tablen(tet) - i;
  while (k >= 0 && tet[i] != NULL)
    {
      k = my_tablen(tet) - 1 - i;
      j = 0;
      l = 0;
      while (j < max_len(tet))
	{
	  new[l][k] = tet[i][j];
	  l++;
	  j++;
	}
      i++;
    }
  free_tab(tet);
  return (new);
}
