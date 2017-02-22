/*
** add_alums.c for alum in /home/shielder/Projects/CPE/CPE_2016_matchstick
** 
** Made by Maxime PICOT
** Login   <shielder@epitech.net>
** 
** Started on  Thu Feb 16 18:05:19 2017 Maxime PICOT
** Last update Sat Feb 18 14:51:25 2017 Maxime PICOT
*/

#include <unistd.h>

char	**add_alums(char **map, int size)
{
  int	x;
  int	y;
  int	i;

  x = 1;
  y = size;
  i = 0;
  if (map[x] != NULL)
    {
      while (x < (size + 1))
	{
	  y = (size - i);
	  while (y <= (size + i))
	    {
	      map[x][y] = '|';
	      y++;
	    }
	  i++;
	  x++;
	}
    }
  return (map);
}
