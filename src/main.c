/*
** main.c for matchstick in /home/shielder/Projects/CPE/CPE_2016_matchstick
** 
** Made by Maxime PICOT
** Login   <shielder@epitech.net>
** 
** Started on  Mon Feb 13 17:37:25 2017 Maxime PICOT
** Last update Wed Feb 22 18:06:41 2017 Maxime PICOT
*/

#include <unistd.h>
#include "alum.h"

int	game_loop(char **map, int size, int limit)
{
  while (666)
    {
      if ((map = my_turn(size, limit, map)) == NULL)
	return (0);
      if ((check_win(map)) == 0)
	{
	  my_putstr("You lost, too bad...\n");
	  return (2);
	}
      if ((map = ia_turn(map, size, limit)) == NULL)
	return (0);
      if ((check_win(map)) == 0)
	{
	  my_putstr("I lost... snif... but I'll get you next time!!\n");
	  return (1);
	}
    }
}

int	main(int ac, char **av)
{
  int	size;
  int	limit;
  char	**map;

  if (ac == 3)
    {
      if ((size = my_getnbr(av[1])) == 0 && (size < 1 || size > 100))
	return (0);
      if ((limit = my_getnbr(av[2])) == 0 && (limit <= 0))
	return (0);
      map = fill_map(size);
      map = add_alums(map, size);
      display_map(map);
      game_loop(map, size, limit);
    }
  else
    return (0);
}
