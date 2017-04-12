/*
** my.h for my.h in /home/lblanchard/CPool_Day09/include
** 
** Made by Leandre Blanchard
** Login   <lblanchard@epitech.net>
** 
** Started on  Thu Oct 13 09:19:01 2016 Leandre Blanchard
** Last update Thu Mar 23 13:10:43 2017 Léandre Blanchard
*/

#ifndef MY_H_
# define MY_H_

# include <unistd.h>
# include <stdlib.h>

void	free_tab(char **);

char	**my_alloc_tab(int, int);

float	my_get_float(char *);

char	*convert_endian_str(int);

int	convert_endian(int);

int	epur_str(char *);

int	total_name(char *);

void	zeros(void *, int);

void	my_putchar(char);

int	my_isneg(int);

int	my_put_nbr(long long);

void	my_putnbr_base(int, char *);

int	my_swap(int *, int *);

int	my_putstr(char *);

int	my_strlen(char *);

int	my_getnbr(char *);

void	my_sort_int_tab(int *, int);

int	my_power_rec(int, int);

int	my_square_root(int);

int	my_is_prime(int);

int	my_find_prime(int);

char	*my_strcpy(char *, char *);

char	*my_strncpy(char *, const char *, int);

char	*my_revstr(char *);

char	*my_strstr(char *, char *);

int	my_strcmp(char *, char *);

int	my_strncmp(char *, char *, int);

char	*my_strupcase(char *);

char	*my_strlowcase(char *);

char	*my_strcapitalize(char *);

int	my_str_isalpha(char *);

int	my_str_isnum(char *, char);

int	my_str_islower(char *);

int	my_str_isupper(char *);

int	my_str_isprintable(char *);

int	my_showstr(char *);

int	my_showmem(char *, int);

char	*my_strcat(char *, char *);

char	*my_strncat(char *, char *, int);

int	my_fact_rec(int);

int	my_find_prime_sup(int);

int	my_show_wordtab(char **);

char	*my_strdup(char *);

int	my_power_rec(int, int);

char	*my_revstr(char *);

char	*int_to_char(int);

char	*my_putstr_error(char *);

int	my_printf(const char *, ...);

int	my_tablen(char **);

int	my_intlen(int);

void	my_put_tab(char **);

#endif /* !MY_H_ */
