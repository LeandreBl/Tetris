/*
** menu.c for Tetris in /home/leandre/Games/Tetris
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Fri Mar 17 18:21:19 2017 Léandre Blanchard
** Last update Thu Mar 23 20:21:36 2017 Léandre Blanchard
*/

#include "tetris.h"

int		keys_menu(int a, int i)
{
  if (i == KEY_UP)
    a++;
  if (i == KEY_DOWN)
    a--;
  if (a > 1)
    a = 0;
  if (a < 0)
    a = 1;
  return (a);
}

void		change_difficulty()
{
  int		i;
  int		new_diff;

  i = 0;
  new_diff = difficulty;
  while (i != 'x' && i != 'X' && i != 10)
    {
      timeout(-1);
      clear();
      PIR_(CBLUE);
      mvprintw(L_ - 1, C_ - my_strlen(DIFFI_) / 2, DIFFI_, difficulty);
      PIR_(CYELLOW);
      mvprintw(L_, C_, "%d", new_diff);
      i = getch();
      if (i == KEY_UP)
	new_diff++;
      if (i == KEY_DOWN)
	new_diff--;
      if (new_diff < 1)
	new_diff = 1;
      if (new_diff > 20)
	new_diff = 20;
      refresh();
    }
  if (i == 10)
    difficulty = new_diff;
}

void		display_boxes(int a)
{
  clear();
  (a == 0) ? PIR_(CWHITE) : PIR_(CYELLOW);
  mvprintw(L_, C_ - my_strlen(PLAY_) / 2, PLAY_);
  (a == 1) ? PIR_(CWHITE) : PIR_(CYELLOW);
  mvprintw(L_ - 1, C_ - my_strlen(DIFF_) / 2, DIFF_);
  refresh();
}

char		**get_map()
{
  int		fd;
  char		**map;
  int		i;
  int		j;

  i = 0;
  if ((fd = open("save.dat", O_RDONLY)) == -1)
    return (NULL);
  lseek(fd, 0, 0);
  if ((map = my_alloc_tab(51, 20)) == NULL)
    return (NULL);
  j = 0;
  while (i != 50)
    {
      read(fd, &map[i][j], 1);
      j++;
      if (j >= 20)
	{
	  j = 0;
	  i++;
	}
    }
  read(fd, &the_no, 4);
  read(fd, &the_next, 4);
  read(fd, &the_difficulty, 4);
  read(fd, &the_score, 4);
  return (map);
}

int		menu(char **tab)
{
  int		key;
  int		a;
  char		**map;

  system("aplay -q musics/start.wav&");
  key = 0;
  a = 0;
  clear();
  map = get_map();
  while (key != 'x' && key != 'X')
    {
      timeout(-1);
      display_boxes(a);
      if (map != NULL)
	{
	  PIR_(CBLUE);
	  mvprintw(L_ - 4, C_ - 20, "Previous save found, press [S] to load");
	  if (key == 'S' || key == 's')
	    play_game(map);
	}
      refresh();
      key = getch();
      a = keys_menu(a, key);
      if (key == 10 && a == 0)
	change_difficulty();
      if (key == 10 && a == 1)
	{
	  the_no = rand() % 6;
	  the_next = rand() % 6;
	  the_score = 0;
	  the_difficulty = difficulty;
	  play_game(tab);
	}
      refresh();
    }
  return (0);
}
