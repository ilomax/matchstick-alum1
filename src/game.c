/*
** game.c for alum in /home/shielder/Projects/CPE/CPE_2016_matchstick
** 
** Made by Maxime PICOT
** Login   <shielder@epitech.net>
** 
** Started on  Sat Feb 18 19:33:22 2017 Maxime PICOT
** Last update Wed Feb 22 16:04:25 2017 Maxime PICOT
*/

#include <unistd.h>
#include <stdlib.h>
#include "alum.h"

int	get_line_index(int size)
{
  int	line;
  char	*str;

  my_putstr("Line: ");
  while ((str = get_next_line(0)))
    {
      if (isnum(str) == 0)
	{
	  my_putsterr("Error: invalid input (positive number expected)\n");
	  return (get_line_index(size));
	}
      else
	{
	  line = my_getnbr(str);
	  if (line < 1 || line > size)
	    {
	      my_putsterr("Error: this line is out of range\n");
	      return (get_line_index(size));
	    }
	  return (line);
	}
    }
  return (-1);
}

void	reprot_norm(t_game *game, int limit, char *line, int size)
{
  if (game->cnt == 0)
    {
      my_putsterr("Error: you have to remove at least one match\n");
      game->line = get_line_index(size);
    }
  else if (game->cnt > limit)
    {
      my_putsterr("Error: you cannot remove more than ");
      my_putnbr_err(limit);
      my_putsterr(" matches per turn\n");
      game->line = get_line_index(size);
    }
  else if (game->cnt > count_matches(line))
    {
      my_putsterr("Error: not enough matches on this line\n");
      game->line = get_line_index(size);
    }
}

int	get_matches_count(int limit, char *line, int size, t_game *game)
{
  char	*str;

  my_putstr("Matches: ");
  while ((str = get_next_line(0)))
    {
      game->cnt = my_getnbr(str);
      reprot_norm(game, limit, line, size);
      if (game->cnt != 0)
	return (game->cnt);
      else
	my_putstr("Matches: ");
    }
  return (-1);
}

char	**rmv_matches(char **map, int line, int cnt, int size)
{
  int	pos;
  int	rmn;
  char	**new_map;

  if (!map || !line || !cnt || !size)
    return (NULL);
  if ((new_map = map_cpy(map)) == NULL)
    return (NULL);
  pos = (size * 2);
  rmn = cnt;
  while (rmn > 0)
    {
      if (new_map[line][pos] != '|')
	pos--;
      else
	{
	  new_map[line][pos] = ' ';
	  rmn--;
	}
    }
  return (new_map);
}

char		**my_turn(int size, int limit, char **map)
{
  t_game	game;
  char		**new_map;

  my_putstr("Your turn:\n");
  if ((game.line = get_line_index(size)) == -1)
    {
      my_putstr("\n");
      return (NULL);
    }
  if ((game.cnt = get_matches_count(limit, map[game.line], size, &game)) == -1)
    {
      my_putstr("\n");
      return (NULL);
    }
  my_putstr("Player removed ");
  my_putnbr(game.cnt);
  my_putstr(" match(es) from line ");
  my_putnbr(game.line);
  my_putchar('\n');
  new_map = rmv_matches(map, game.line, game.cnt, size);
  display_map(new_map);
  return (new_map);
}
