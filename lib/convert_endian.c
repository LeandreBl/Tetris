/*
** convert_endian.c for endian in /home/leandre/Prog_elem/CPE_2016_corewar
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Mon Mar 13 18:19:05 2017 Léandre Blanchard
** Last update Mon Mar 13 18:41:17 2017 Léandre Blanchard
*/

char		*my_strdup(char *);

char		*convert_endian_str(int x)
{
  char		endian[4];
  char		*s;

  endian[0] = (x >> 24) & 0xFF;
  endian[1] = (x >> 16) & 0xFF;
  endian[2] = (x >> 8) & 0xFF;
  endian[3] = x & 0xFF;
  s = my_strdup(endian);
  return (s);
}

int             convert_endian(int x)
{
  x = ( x >> 24 ) | (( x << 8) & 0x00ff0000 ) | ((x >> 8) & 0x0000ff00) | ( x << 24);
  return (x);
}
