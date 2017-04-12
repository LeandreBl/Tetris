/*
** falling.c for tetris in /home/leandre/Games/Tetris
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Mon Mar 20 12:24:07 2017 Léandre Blanchard
** Last update Thu Mar 23 14:50:24 2017 Léandre Blanchard
*/

#include "tetris.h"

void		display_fake(t_tetris *tetris)
{
  int		real_pos_y;

  real_pos_y = T_ xy.y;
  while (can_fall(tetris) == 0 && T_ xy.y <= (50 - my_tablen(T_ tetriminos[T_ no])))
    T_ xy.y++;
  PIR_(CWHITE);
  put_tetrimino(tetris, 0);
  T_ xy.y = real_pos_y;
}

int		can_fall(t_tetris *tetris)
{
  int		i;
  int		j;

  i = 0;
  while (T_ tetriminos[T_ no][i] != NULL)
    {
      j = 0;
      while (T_ tetriminos[T_ no][i][j] != 0)
	{
	  if (T_ xy.y + i < my_tablen(T_ map))
	    {
	      if ((T_ tetriminos[T_ no][i][j] != 0
		   && T_ tetriminos[T_ no][i][j] != ' ')
		  && T_ map[T_ xy.y + i][T_ xy.x + 9 + j] != 0
		  && T_ tetriminos[T_ no][i][j] != 6)
		return (-1);
	      if (T_ xy.y + i + 1 <= my_tablen(T_ map))
		if ((T_ tetriminos[T_ no][i][j] != 0
		     && T_ tetriminos[T_ no][i][j] != ' ')
		    && T_ map[T_ xy.y + i][T_ xy.x + 10 + j] != 0
		    && T_ tetriminos[T_ no][i][j] == 6)
		  return (-1);
	    }
	  j++;
	}
      i++;
    }
  return (0);
}

void		put_in_tab(t_tetris *tetris)
{
  int		i;
  int		j;
  int		posx;
  int		posy;
  i = 0;
  while (T_ tetriminos[T_ no][i] != NULL)
    {
      j = 0;
      while (T_ tetriminos[T_ no][i][j] != 0)
	{
	  posy = T_ xy.y + i - 1;
	  posx = T_ xy.x + 9 + j;
	  if (posy < 0)
	    lose(tetris);
	  if (max_len(T_ tetriminos[T_ no]) == 1 || max_len(T_ tetriminos[T_ no]) == 4)
	    posx++;
	  if (T_ tetriminos[T_ no][i][j] != ' ')
	    T_ map[posy][posx] = T_ tetriminos[T_ no][i][j];
	  j++;
	}
      i++;
    }
  T_ xy = xy_tuple(0, 0);
  T_ no = T_ next;
  T_ next = rand() % 6;
  T_ score += 2;
}

int		max_len(char **tetrimino)
{
  int		len;
  int		i;

  i = 0;
  len = 0;
  while (tetrimino[i] != NULL)
    {
      if (my_strlen(tetrimino[i]) > len)
	len = my_strlen(tetrimino[i]);
      i++;
    }
  return (len);
}

void		put_tetrimino(t_tetris *tetris, int a)
{
  t_xy		xy;
  int		posx;
  int		posy;

  xy = xy_tuple(0, 0);
  while (T_ tetriminos[T_ no][xy.y] != NULL)
    {
      xy.x = 0;
      while (T_ tetriminos[T_ no][xy.y][xy.x] != 0)
	{
	  posx = C_ - max_len(T_ tetriminos[T_ no]) / 2 + xy.x + T_ xy.x;
	  posy = L_ - 26 + T_ xy.y + xy.y;
	  if (max_len(T_ tetriminos[T_ no]) == 4)
	    posx += 2;
	  if (T_ tetriminos[T_ no][xy.y][xy.x] != ' ' && posy > L_ - 28 && posy < L_ + 25)
	    {
	      if (T_ matrix == 1 && a == 1)
		mvprintw(posy, posx, "%c", 33 + rand() % 50);
	      if (T_ nazi == 1 && a == 1)
		mvprintw(posy, posx, "࿕");
	      else if (T_ matrix == 0 && T_ nazi == 0 && a == 1)
		mvprintw(posy, posx, "#");
	      if (a == 0)
		mvprintw(posy, posx, "∏");
	    }
	  xy.x++;
	}
      xy.y++;
    }
}

void		display_falling_tetrimino(t_tetris *tetris)
{
  (tetris->no == 0) ? PIR_(CCYAN) : 0;
  (tetris->no == 1) ? PIR_(CYELLOW) : 0;
  (tetris->no == 2) ? PIR_(CRED) : 0;
  (tetris->no == 3) ? PIR_(CMAGENTA) : 0;
  (tetris->no == 4) ? PIR_(CBLUE) : 0;
  (tetris->no == 5) ? PIR_(CGREEN) : 0;
  if (T_ xy.y + my_tablen(T_ tetriminos[T_ no]) > L_ + 19)
    {
      T_ xy.y = L_ + 19 - my_tablen(T_ tetriminos[T_ no]);
      put_in_tab(tetris);
    }
  if (can_fall(tetris) != 0)
    put_in_tab(tetris);
  put_tetrimino(tetris, 1);
  display_fake(tetris);
}
