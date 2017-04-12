/*
** main.c for tetris in /home/leandre/Games/Tetris
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Fri Mar 17 18:04:13 2017 Léandre Blanchard
** Last update Tue Mar 28 19:23:29 2017 Léandre Blanchard
*/

#include "tetris.h"

void		put_n_space(int n)
{
  int		i;

  i = 0;
  while (i <= n)
    {
      my_printf(" ");
      i++;
    }
}

int		print_scores(char **av)
{
  int		fd;
  t_score	score;

  if ((fd = open(av[1], O_RDONLY)) == -1)
    {
      my_printf("%sCan't open highscore file\n%s", BOLDRED, RESET);
      return (84);
    }
  my_printf("%s|NAME|\t\t\t|SCORE|\t\t\t|DIFFICULTY|%s\n\n", BOLDCYAN, RESET);
  while (read(fd, &score, sizeof(t_score)) > 0)
    {
      my_printf("%s[%s%s%s]%s ", BOLDBLUE, BOLDWHITE, score.name, BOLDBLUE, RESET);
      put_n_space(20 - my_strlen(score.name));
      my_printf("%s[%s%d%s]%s ", BOLDBLUE, BOLDWHITE, score.score, BOLDBLUE, RESET);
      put_n_space(23 - my_intlen(score.score));
      my_printf("%s[%s%d%s]%s\n", BOLDBLUE,
		BOLDWHITE, score.max_dif, BOLDBLUE, RESET);
    }
  return (0);
}

int		main(int ac, char **av)
{
  char		**map;

  if (ac == 2)
    return (print_scores(av));
  difficulty = 1;
  srand(time(NULL));
  setlocale(LC_ALL, "");
  init_screen_menu();
  if ((map = my_alloc_tab(51, 20)) == NULL)
    return (84);
  menu(map);
  endwin();
  free_tab(map);
  return (0);
}
