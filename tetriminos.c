/*
** tetriminos.c for tetris in /home/leandre/Games/Tetris
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Sun Mar 19 00:59:54 2017 Léandre Blanchard
** Last update Wed Mar 22 21:41:25 2017 Léandre Blanchard
*/

#include "tetris.h"

char		**tetri_bar()
{
  char		**tetri_bar;
  int		i;

  i = 0;
  if ((tetri_bar = my_alloc_tab(5, 2)) == NULL)
    return (NULL);
  while (i < 4)
    {
      tetri_bar[i][0] = 6;
      i++;
    }
  return (tetri_bar);
}

char		**tetri_cube()
{
  char		**tetri_cube;

  if ((tetri_cube = my_alloc_tab(3, 3)) == NULL)
    return (NULL);
  tetri_cube[0][0] = 3;
  tetri_cube[0][1] = 3;
  tetri_cube[1][0] = 3;
  tetri_cube[1][1] = 3;
  return (tetri_cube);
}

char		**tetri_z()
{
  char		**tetri_z;

  if ((tetri_z = my_alloc_tab(3, 4)) == NULL)
    return (NULL);
  tetri_z[0][0] = 1;
  tetri_z[0][1] = 1;
  tetri_z[1][1] = 1;
  tetri_z[1][2] = 1;
  tetri_z[0][2] = ' ';
  tetri_z[1][0] = ' ';
  return (tetri_z);
}

char		**tetri_r_z()
{
  char		**tetri_z;

  if ((tetri_z = my_alloc_tab(3, 4)) == NULL)
    return (NULL);
  tetri_z[0][0] = ' ';
  tetri_z[0][1] = 5;
  tetri_z[0][2] = 5;
  tetri_z[1][0] = 5;
  tetri_z[1][1] = 5;
  tetri_z[1][2] = ' ';
  return (tetri_z);
}

char		**tetri_l()
{
  char		**tetri_l;

  if ((tetri_l = my_alloc_tab(3, 4)) == NULL)
    return (NULL);
  tetri_l[0][0] = 2;
  tetri_l[0][1] = ' ';
  tetri_l[0][2] = ' ';
  tetri_l[1][0] = 2;
  tetri_l[1][1] = 2;
  tetri_l[1][2] = 2;
  return (tetri_l);
}

char		**tetri_pyramid()
{
  char		**tetri_pir;

  if ((tetri_pir = my_alloc_tab(3, 4)) == NULL)
    return (NULL);
  tetri_pir[0][0] = ' ';
  tetri_pir[0][1] = 4;
  tetri_pir[0][2] = ' ';
  tetri_pir[1][0] = 4;
  tetri_pir[1][1] = 4;
  tetri_pir[1][2] = 4;
  return (tetri_pir);
}
