/*
** tetris.h for tetris in /home/leandre/Games/Tetris
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Fri Mar 17 18:04:23 2017 Léandre Blanchard
** Last update Tue Mar 28 19:12:28 2017 Léandre Blanchard
*/

#ifndef TETRIS_H_
# define TETRIS_H_

# include <curses.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <locale.h>
# include <time.h>

# include "my.h"
# include "colors.h"

# define DIFF_ "[Difficulty]"
# define PLAY_ "[Play !]"
# define DIFFI_ "Choose your new difficulty level ! (previous [%d])"
# define HELP_ "%sTetris game, press SPACE to rotate and arrow keys to move tetriminos, upper key to fast fall\n%s"

# define PIR_(a) attron(COLOR_PAIR(a) | A_BOLD)
# define L_ 65 / 2
# define C_ 118 / 2
# define C_J 118 / 2 - 10 + j
# define L_I 65 / 2 - 25 + i
# define LEN_2(str) my_strlen(str) / 2
# define CRED     3
# define CMAGENTA 1
# define CGREEN   2
# define CYELLOW  4
# define CWHITE   5
# define CCYAN    6
# define CBLUE    7
# define T_ tetris->

typedef struct	s_xy
{
  int		x;
  int		y;
}		t_xy;

typedef struct	s_tetris
{
  int		key;
  char		***tetriminos;
  char		**map;
  t_xy		xy;
  int		no;
  int		next;
  int		matrix;
  int		nazi;
  int		score;
  double	time;
  int		save;
}		t_tetris;

typedef struct	s_score
{
  char		name[100];
  int		score;
  int		max_dif;
}		t_score;

char		**rotate(char **);
void		save_game(char **, int, int, int, int);
void		put_tetrimino(t_tetris *, int);
void		lose(t_tetris *);
int		main(int, char **);
void		init_color_pairs();
void		moves(t_tetris *);
void		init_screen_menu();
int		can_fall(t_tetris *);
int		menu(char **);
int		play_game(char **);
char		**tetri_bar();
char		**tetri_cube();
char		**tetri_pyramid();
char		**tetri_z();
char		**tetri_r_z();
char		**tetri_l();
void		display_falling_tetrimino(t_tetris *);
t_xy		xy_tuple(int, int);
char		***create_tetriminos();
t_tetris	*init_struct(char **);
int		max_len(char **);
void		put_in_tab(t_tetris *);
void		free_struct(t_tetris *);
int		holes_left(char *);
int		line_to_break(char **);
void		break_lines(char **, t_tetris *);

int		difficulty;
int		the_difficulty;
int		the_no;
int		the_next;
int		the_score;

#endif /* !TETRIS_H_ */
