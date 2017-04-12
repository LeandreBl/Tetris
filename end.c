/*
** lose.c for tetris in /home/leandre/Games/Tetris
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Wed Mar 22 20:47:42 2017 Léandre Blanchard
** Last update Fri Mar 24 16:51:42 2017 Léandre Blanchard
*/

#include "tetris.h"

int		save_score(t_score score)
{
  int		fd;

  if ((fd = open("highscore.dat", O_RDWR | O_CREAT, 00666)) == -1)
    return (-1);
  lseek(fd, 0, SEEK_END);
  if ((write(fd, &score, sizeof(t_score))) == -1)
    return (-1);
  if (access("highscore.dat", F_OK) != -1)
    my_printf("%sHighscore.dat has been successfully updated\n%s", BOLDGREEN, RESET);
  return (0);
}

void		display_hall_of_fame()
{
  t_score	score;
  int		fd;
  int		i;

  i = 1;
  PIR_(CRED);
  if ((fd = open("highscore.dat", O_RDONLY)) == -1)
    {
      mvprintw(L_ - 5, C_ - 12, "No previous scores saved");
      return;
    }
  PIR_(CBLUE);
  mvprintw(0, C_ - 10, "Previous highscores :");
  while (read(fd, &score, sizeof(t_score)) > 0 && i < 50)
    {
      PIR_(CYELLOW);
      mvprintw(i, 0, "Name : [%s]", score.name);
      mvprintw(i, 50, "score : [%d]", score.score);
      mvprintw(i, 100, "difficulty [%d]", score.max_dif);
      i++;
    }
  close(fd);
}

t_score		display_scores(t_tetris *tetris)
{
  t_score	score;
  int		i;
  int		k;

  i = 0;
  zeros(score.name, 100);
  k = 0;
  score.score = tetris->score;
  clear();
  refresh();
  while (i != 10)
    {
      clear();
      timeout(-1);
      PIR_(CWHITE);
      mvprintw(L_, C_ - LEN_2(score.name) - 10, "Enter player name : [%s]", score.name);
      mvprintw(L_ + 1, C_ - 7 - my_intlen(score.score), "Your score is !%d!", score.score);
      mvprintw(L_ - 1, C_ - 15, "Press ENTER to save your score");
      display_hall_of_fame();
      refresh();
      i = getch();
      if (((i >= '0' && i <= '9') || (i <= 'Z' && i >= 'A')
	  || (i <= 'z' && i >= 'a') || i == ' ') && (k < 100))
	score.name[k++] = i;
      if (i == KEY_BACKSPACE && k > 0)
	score.name[--k] = 0;
      if (k < 0)
	k = 0;
    }
  if (my_strlen(score.name) == 0)
    my_strcpy(score.name, "No name");
  score.max_dif = difficulty;
  return (score);
}

void		lose(t_tetris *tetris)
{
  t_score	score;

  system("kill $(pgrep aplay)");
  score = display_scores(tetris);
  endwin();
  if (save_score(score) == -1)
    my_printf("%sUnable to create and/or access highscore.dat file, please check permissions\n%s", BOLDRED, RESET);
  exit(0);
}
