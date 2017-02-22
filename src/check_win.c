/*
** check_win.c for alum1 in /home/shielder/Projects/CPE/CPE_2016_matchstick
** 
** Made by Maxime PICOT
** Login   <shielder@epitech.net>
** 
** Started on  Tue Feb 21 18:08:47 2017 Maxime PICOT
** Last update Wed Feb 22 18:07:07 2017 Maxime PICOT
*/

#include <unistd.h>
#include "alum.h"

int	check_win(char **map)
{
  int	res;
  int	i;

  res = 0;
  i = 0;
  while (map && map[i] != NULL)
    {
      res += count_matches(map[i]);
      i++;
    }
  if (res == 0)
    return (0);
  else if (res > 0)
    return (res);
  else
    return (-1);
}
