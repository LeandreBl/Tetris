/*
** init.c for Tetris in /home/leandre/Games/Tetris
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Fri Mar 17 18:12:38 2017 Léandre Blanchard
** Last update Thu Mar 23 15:50:54 2017 Léandre Blanchard
*/

#include "tetris.h"

void		init_color_pairs()
{
  init_pair(1, COLOR_MAGENTA, COLOR_BLACK);
  init_pair(2, COLOR_GREEN, COLOR_BLACK);
  init_pair(3, COLOR_RED, COLOR_BLACK);
  init_pair(4, COLOR_YELLOW, COLOR_BLACK);
  init_pair(5, COLOR_WHITE, COLOR_BLACK);
  init_pair(6, COLOR_CYAN, COLOR_BLACK);
  init_pair(7, COLOR_BLUE, COLOR_BLACK);
}

void            init_screen_menu()
{
  initscr();
  clear();
  curs_set(0);
  start_color();
  keypad(stdscr, TRUE);
  init_color_pairs();
}

t_tetris	*init_struct(char **tab)
{
  t_tetris	*tetris;

  if ((tetris = malloc(sizeof(t_tetris))) == NULL)
    return (NULL);
  tetris->xy = xy_tuple(0, 0);
  if ((tetris->tetriminos = create_tetriminos()) == NULL)
    return (NULL);
  if ((tetris->map = tab) == NULL)
    return (NULL);
  T_ no = the_no;
  T_ next = the_next;
  T_ key = 0;
  T_ matrix = 0;
  T_ nazi = 0;
  T_ score = the_score;
  T_ save = -1;
  difficulty = the_difficulty;
  return (tetris);
}

void		free_struct(t_tetris *tetris)
{
  int		i;

  i = 0;
  while (tetris->tetriminos[i] != NULL)
    {
      free_tab(tetris->tetriminos[i]);
      i++;
    }
  free(tetris->tetriminos);
  free(tetris);
}
