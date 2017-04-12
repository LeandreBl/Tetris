/*
** epur_str.c for epur_str in /home/leandre/libmy
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Mon Mar 13 14:38:15 2017 Léandre Blanchard
** Last update Mon Mar 13 14:49:46 2017 Léandre Blanchard
*/

#include <stdlib.h>

int	my_strlen(char *);

char	*epur_str(char *str)
{
  char	*src;
  int	i;
  int	j;

  i = 0;
  j = 0;
  if ((src = malloc(sizeof(char *) * my_strlen(str))) == NULL)
    return (NULL);
  while (str[i] != '\0')
    {
      if (str[i] == ' ' || str[i] == '\t')
	{
	  while ((str[i] == ' ' || str[i] == '\t') && str[i] != '\0')
	    i = i + 1;
	  if (j > 0 && str[i] != '\0')
	    src[j++] = ' ';
	}
      src[j++] = str[i++];
    }
  src[j] = '\0';
  return (src);
}
