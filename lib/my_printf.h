/*
** my_printf.h for my_printf in /home/lblanchard/PSU_2016_my_printf
** 
** Made by Leandre Blanchard
** Login   <lblanchard@epitech.net>
** 
** Started on  Tue Nov  8 10:10:10 2016 Leandre Blanchard
** Last update Wed Mar 15 18:52:26 2017 Léandre Blanchard
*/

#ifndef MY_PRINTF_H_
# define MY_PRINTF_H_

# include <stdarg.h>

# define NNBR my_nputnbr_base
# define NBR  my_put_nbr

typedef union	float_u
{
  double	floating;
  int		part[2];
}		float_n;

void	pointeur(void *);

int	my_printf(const char *, ...);

int	nb_arg(const char *, int i);

int	dec_to_base(int, int);

void	conv_to_printable(char *);

char	*int_to_char(int);

char	*int_ascii_to_char(int);

int	my_strlenconst(const char *);

char	*my_strcpyn(char *, char *, int);

char	*char_to_nchar(va_list, int);

int	int_to_nint(int, int);

void	my_nputnbr_base(long long, char *, int);

void	my_put_float(double);

#endif /* !MY_PRINTF_H_ */
