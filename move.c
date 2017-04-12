/*
** move.c for tetris in /home/leandre/Games/Tetris
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Wed Mar 22 20:21:22 2017 Léandre Blanchard
** Last update Fri Mar 24 16:49:02 2017 Léandre Blanchard
*/

#include "tetris.h"

void		save_game(char **map, int no, int next, int difficulty, int score)
{
  int		i;
  int		fd;

  i = 0;
  if ((fd = open("save.dat", O_WRONLY | O_CREAT, 00666)) == -1)
    return;
  while (map[i] != NULL)
    {
      write(fd, map[i], 20);
      i++;
    }
  write(fd, &no, 4);
  write(fd, &next, 4);
  write(fd, &difficulty, 4);
  write(fd, &score, 4);
  close(fd);
}

void		to_the_bot(t_tetris *tetris)
{
  while (can_fall(tetris) == 0 && T_ xy.y < 50)
    T_ xy.y++;
}

void            moves(t_tetris *tetris)
{
  int		swap;

  if (T_ key == ' ')
    T_ tetriminos[T_ no] = rotate(T_ tetriminos[T_ no]);
  if (T_ key == 9)
    {
      system("aplay -q musics/hold.wav&");
      if (T_ save == -1)
	{
	  T_ save = T_ no;
	  T_ no = T_ next;
	  T_ next = rand() % 6;
	}
      else if (T_ save != (-1))
	{
	  swap = T_ no;
	  T_ no = T_ save;
	  T_ save = swap;
	}
    }
  if (T_ key == 'q' || T_ key == KEY_LEFT)
    {
      system("aplay -q musics/bip.wav&");
      T_ xy.x--;
    }
  if (T_ key == 'd' || T_ key == KEY_RIGHT)
    {
      system("aplay -q musics/bip.wav&");
      T_ xy.x++;
    }
  if (T_ key == 'z' || T_ key == KEY_UP)
    {
      system("aplay -q musics/drop.wav&");
      to_the_bot(tetris);
    }
  if (T_ key == 's' || T_ key == KEY_DOWN)
    {
      system("aplay -q musics/bip.wav&");
      T_ xy.y++;
    }
  if (T_ key == KEY_END)
    T_ xy.x += 20;
  if (T_ key == 262)
    T_ xy.x = -20;
  if (T_ xy.x - max_len(T_ tetriminos[T_ no]) / 2 < C_ / 2 - 39 && max_len(T_ tetriminos[T_ no]) != 4)
    T_ xy.x = C_ / 2 - 39 + max_len(T_ tetriminos[T_ no]) / 2;
  if (T_ xy.x - max_len(T_ tetriminos[T_ no]) / 2 < C_ / 2 - 41 && max_len(T_ tetriminos[T_ no]) == 4)
    T_ xy.x = C_ / 2 - 41 + max_len(T_ tetriminos[T_ no]) / 2;
  if (T_ xy.x + max_len(T_ tetriminos[T_ no]) / 2 > C_ / 2 - 20 && max_len(T_ tetriminos[T_ no]) != 4)
    {
      T_ xy.x = C_ / 2 - 20 - max_len(T_ tetriminos[T_ no]) / 2;
      if (max_len(T_ tetriminos[T_ no]) % 2 == 0)
	T_ xy.x += 1;
    }
  if (T_ xy.x + max_len(T_ tetriminos[T_ no]) / 2 > C_ / 2 - 22 && max_len(T_ tetriminos[T_ no]) == 4)
    {
      T_ xy.x = C_ / 2 - 22 - max_len(T_ tetriminos[T_ no]) / 2;
      if (max_len(T_ tetriminos[T_ no]) % 2 == 0)
	T_ xy.x += 1;
    }
  if (T_ key == 'M')
    {
      system("kill $(pgrep aplay)&");
      clear();
      refresh();
    }
  if (T_ key == 'm')
    {
      T_ matrix = !T_ matrix;
      T_ nazi = 0;
    }
  if (T_ key == 'n')
    {
      T_ nazi = !T_ nazi;
      T_ matrix = 0;
    }
  if (T_ key == 's')
    save_game(tetris->map, T_ no, T_ next, difficulty, T_ score);
}
