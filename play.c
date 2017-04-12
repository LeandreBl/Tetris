/*
** play.c for tetris in /home/leandre/Games/Tetris
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Sun Mar 19 00:44:48 2017 Léandre Blanchard
** Last update Fri Mar 24 16:51:15 2017 Léandre Blanchard
*/

#include "tetris.h"

char		***create_tetriminos()
{
  char		***tetriminos;

  if ((tetriminos = malloc(sizeof(char **) * 8)) == NULL)
    return (NULL);
  if ((tetriminos[0] = tetri_bar()) == NULL)
    return (NULL);
  if ((tetriminos[1] = tetri_cube()) == NULL)
    return (NULL);
  if ((tetriminos[2] = tetri_z()) == NULL)
    return (NULL);
  if ((tetriminos[3] = tetri_pyramid()) == NULL)
    return (NULL);
  if ((tetriminos[4] = tetri_l()) == NULL)
    return (NULL);
  if ((tetriminos[5] = tetri_r_z()) == NULL)
    return (NULL);
  tetriminos[6] = NULL;
  return (tetriminos);
}

void		save_tetrimino(t_tetris *tetris)
{
  int		i;
  int		j;
  int		no;

  i = 0;
  tetris = tetris;
  j = i;
  i = j;
  no = i;
  i = no;
  PIR_(CWHITE);
  mvhline(L_ - 16, C_ + 20, 0, 10);
  mvhline(L_ - 9, C_ + 20, 0, 10);
  mvvline(L_ - 15, C_ + 19, 0, 6);
  mvvline(L_ - 15, C_ + 30, 0, 6);
  mvprintw(L_ - 16, C_ + 23, "Save");
  mvaddch(L_ - 16, C_ + 19, ACS_ULCORNER);
  mvaddch(L_ - 16, C_ + 30, ACS_URCORNER);
  mvaddch(L_ - 9, C_ + 19, ACS_LLCORNER);
  mvaddch(L_ - 9, C_ + 30, ACS_LRCORNER);
  mvaddch(L_ - 9, C_ + 30, ACS_LRCORNER);
  mvprintw(L_ - 15, C_ + 20, "          ");
  mvprintw(L_ - 14, C_ + 20, "          ");
  mvprintw(L_ - 13, C_ + 20, "          ");
  mvprintw(L_ - 12, C_ + 20, "          ");
  mvprintw(L_ - 11, C_ + 20, "          ");
  mvprintw(L_ - 10, C_ + 20, "          ");
  if (T_ save == -1)
    return;
  while (T_ tetriminos[T_ save][i] != NULL)
    {
      j = 0;
      while (T_ tetriminos[T_ save][i][j] != 0)
	{
	  no = T_ tetriminos[T_ save][i][j];
	  (tetris->save == 2) ? PIR_(CRED) : 0;
	  (tetris->save == 4) ? PIR_(CBLUE) : 0;
	  (tetris->save == 1) ? PIR_(CYELLOW) : 0;
	  (tetris->save == 3) ? PIR_(CMAGENTA) : 0;
	  (tetris->save == 5) ? PIR_(CGREEN) : 0;
	  (tetris->save == 0) ? PIR_(CCYAN) : 0;
	  if (T_ matrix == 0 && T_ nazi == 0 && no != ' ')
	    mvprintw(L_ - 15 + i + 3 - my_tablen(T_ tetriminos[T_ save]) / 2,
		     C_ + 20 + j + 5 - max_len(T_ tetriminos[T_ save]) / 2, "#");
	  if (T_ matrix == 1 && no != ' ')
	    {
	      PIR_(CGREEN);
	      mvprintw(L_ - 15 + i + 3 - my_tablen(T_ tetriminos[T_ save]) / 2,
		       C_ + 20 + j + 5 - max_len(T_ tetriminos[T_ save]) / 2, "%c", 33 + rand() % 50);
	    }
	  if (T_ nazi == 1 && no != ' ')
	    mvprintw(L_ - 15 + i + 3 - my_tablen(T_ tetriminos[T_ save]) / 2,
		     C_ + 20 + j + 5 - max_len(T_ tetriminos[T_ save]) / 2, "࿕");
	  j++;
	}
      i++;
    }
}

void		display_next_tetrimino(t_tetris *tetris)
{
  int		i;
  int		j;
  int		no;

  i = 0;
  PIR_(CWHITE);
  mvhline(L_ - 26, C_ + 20, 0, 10);
  mvhline(L_ - 19, C_ + 20, 0, 10);
  mvvline(L_ - 25, C_ + 19, 0, 6);
  mvvline(L_ - 25, C_ + 30, 0, 6);
  mvprintw(L_ - 26, C_ + 23, "Next");
  mvaddch(L_ - 26, C_ + 19, ACS_ULCORNER);
  mvaddch(L_ - 26, C_ + 30, ACS_URCORNER);
  mvaddch(L_ - 19, C_ + 19, ACS_LLCORNER);
  mvaddch(L_ - 19, C_ + 30, ACS_LRCORNER);
  mvprintw(L_ - 25, C_ + 20, "          ");
  mvprintw(L_ - 24, C_ + 20, "          ");
  mvprintw(L_ - 23, C_ + 20, "          ");
  mvprintw(L_ - 22, C_ + 20, "          ");
  mvprintw(L_ - 21, C_ + 20, "          ");
  mvprintw(L_ - 20, C_ + 20, "          ");
  while (T_ tetriminos[T_ next][i] != NULL)
    {
      j = 0;
      while (T_ tetriminos[T_ next][i][j] != 0)
	{
	  no = T_ tetriminos[T_ next][i][j];
	  (tetris->next == 2) ? PIR_(CRED) : 0;
	  (tetris->next == 4) ? PIR_(CBLUE) : 0;
	  (tetris->next == 1) ? PIR_(CYELLOW) : 0;
	  (tetris->next == 3) ? PIR_(CMAGENTA) : 0;
	  (tetris->next == 5) ? PIR_(CGREEN) : 0;
	  (tetris->next == 0) ? PIR_(CCYAN) : 0;
	  if (T_ matrix == 0 && T_ nazi == 0 && no != ' ')
	    mvprintw(L_ - 25 + i + 3 - my_tablen(T_ tetriminos[T_ next]) / 2,
		     C_ + 20 + j + 5 - max_len(T_ tetriminos[T_ next]) / 2, "#");
	  if (T_ matrix == 1 && no != ' ')
	    {
	      PIR_(CGREEN);
	      mvprintw(L_ - 25 + i + 3 - my_tablen(T_ tetriminos[T_ next]) / 2,
		       C_ + 20 + j + 5 - max_len(T_ tetriminos[T_ next]) / 2, "%c", 33 + rand() % 50);
	    }
	  if (T_ nazi == 1 && no != ' ')
	    mvprintw(L_ - 25 + i + 3 - my_tablen(T_ tetriminos[T_ next]) / 2,
		     C_ + 20 + j + 5 - max_len(T_ tetriminos[T_ next]) / 2, "࿕");
	  j++;
	}
      i++;
    }
  save_tetrimino(tetris);
}

void		display_gui(t_tetris *tetris)
{
  int		sec;
  static int	prev;
  static int	previous;
  char		*music;
  
  display_falling_tetrimino(tetris);
  display_next_tetrimino(tetris);
  PIR_(CWHITE);
  mvhline(L_ - 26, C_ - 10, 0, 20);
  mvhline(L_ + 25, C_ - 10, 0, 20);
  mvvline(L_ - 25, C_ - 11, 0, 50);
  mvvline(L_ - 25, C_ + 10, 0, 50);
  mvaddch(L_ - 26, C_ - 11, ACS_ULCORNER);
  mvaddch(L_ + 25, C_ - 11, ACS_LLCORNER);
  mvaddch(L_ - 26, C_ + 10, ACS_URCORNER);
  mvaddch(L_ + 25, C_ + 10, ACS_LRCORNER);
  mvprintw(10, 10, "                 ");
  mvprintw(10, 10, "%d min %d sec", ((int)(T_ time + 10) / 10) / 60, ((int)(T_ time + 10) / 10) % 60);
  PIR_(CRED);
  mvprintw(0, 0, "%f", T_ time / 10);
  sec = (int)(T_ time / 10);
  if ((music = my_strdup("aplay -q musics/tetris00.wav&")) == NULL)
    return;
  if (sec % 20 == 0 && prev != sec && difficulty < 40)
    {
      system("aplay -q musics/difficulty.wav&");
      prev = sec;
      difficulty++;
    }
  if ((int)T_ time / 10 % 80 == 0 && previous != sec)
    {
      music[23] = 49 + rand() % 5;
      endwin();
      my_printf("Loopback music\n");
      my_printf("%s%s\n%s", CYAN, music, RESET);
      previous = sec;
      system(music);
    }
  free(music);
  PIR_(CWHITE);
  mvprintw(11, 10, "                        ");
  mvprintw(11, 10, "Difficulty : [%d]", difficulty);
  mvprintw(12, 10, "                        ");
  mvprintw(12, 10, "Score : [%d]", T_ score);
  refresh();
}

void		display_terrain(t_tetris *tetris)
{
  int		i;
  int		j;

  i = 0;
  break_lines(T_ map, tetris);
  while (i < 50)
    {
      j = 0;
      while (j < 20)
	{
	  (tetris->map[i][j] == 1) ? PIR_(CRED) : 0;
	  (tetris->map[i][j] == 2) ? PIR_(CBLUE) : 0;
	  (tetris->map[i][j] == 3) ? PIR_(CYELLOW) : 0;
	  (tetris->map[i][j] == 4) ? PIR_(CMAGENTA) : 0;
	  (tetris->map[i][j] == 5) ? PIR_(CGREEN) : 0;
	  (tetris->map[i][j] == 6) ? PIR_(CCYAN) : 0;
	  mvprintw(L_I, C_J, " ");
	  if (tetris->map[i][j] != 0 && tetris->map[i][j] != ' ')
	    {
	      if (T_ matrix == 1)
		{
		  PIR_(CGREEN);
		  mvprintw(L_I, C_J, "%c", 34 + rand() % 50);
		}
	      if (T_ nazi == 1)
		mvprintw(L_I, C_J, "☭");
	      else if (T_ nazi == 0 && T_ matrix == 0)
		mvprintw(L_I, C_J, "#");
	    }
	  j++;
	}
      i++;
    }
  display_gui(tetris);
}

t_xy		xy_tuple(int x, int y)
{
  t_xy		xy;

  xy.x = x;
  xy.y = y;
  return (xy);
}

int		play_game(char **tab)
{
  t_tetris	*tetris;
  time_t	start;
  time_t	end;
  double	time;
  double	prev;
  char		*music;

  time = 0;
  prev = -1;
  if ((music = my_strdup("aplay -q musics/tetris00.wav&")) == NULL)
    return (-1);
  music[23] = 49 + rand() % 5;
  system(music);
  free(music);
  if ((tetris = init_struct(tab)) == NULL)
    return (-1);
  start = clock();
  clear();
  while (T_ key != 'x' && T_ key != 'X')
    {
      timeout(0);
      end = clock();
      time = ((double)(end - start)) / CLOCKS_PER_SEC * 10;
      T_ time = time;
      if (time > prev + 10 / (double)difficulty)
	{
	  prev = time;
	  tetris->xy.y++;
	}
      display_terrain(tetris);
      T_ key = getch();
      moves(tetris);
    }
  free_struct(tetris);
  system("kill $(pgrep aplay)");
  return (0);
}
