/*
** break_lines.c for tetris in /home/leandre/Games/Tetris
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Tue Mar 21 13:39:24 2017 Léandre Blanchard
** Last update Thu Mar 23 20:20:09 2017 Léandre Blanchard
*/

#include "tetris.h"

void		the_strcpy(char *dest, char *str)
{
  int		i;

  i = 0;
  while (i != 20)
    {
      dest[i] = str[i];
      i++;
    }
}

int		holes_left(char *line)
{
  int		i;
  int		nb;

  i = 0;
  nb = 0;
  while (i != 20)
    {
      if (line[i] == 0)
	nb++;
      i++;
    }
  return (nb);
}

int		line_to_break(char **tab)
{
  int		i;

  i = 0;
  while (tab[i] != NULL)
    {
      if (holes_left(tab[i]) == 0)
	return (i);
      i++;
    }
  return (-1);
}

void		break_lines(char **tab, t_tetris *tetris)
{
  int		i;

  i = line_to_break(tab);
  if (i != -1)
    {
      system("aplay -q musics/break_line.wav&");
      T_ score += 100;
    }
  if (i > my_tablen(tab))
    return;
  while (i > 1)
    {
      the_strcpy(tab[i], tab[i - 1]);
      i--;
    }
  zeros(tab[0], 20);
}
