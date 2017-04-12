/*
** total_name.c for total_name in /home/leandre/Prog_elem/CPE_2016_corewar
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Wed Mar  1 12:08:37 2017 Léandre Blanchard
** Last update Wed Mar  1 12:09:59 2017 Léandre Blanchard
*/

int		total_name(char *str)
{
  int           i;
  int           nb;

  nb = 0;
  i = 0;
  while (str[i] != 0)
    nb += str[i++];
  return (nb);
}
