/*
** ia.c for alum in /home/shielder/Projects/CPE/CPE_2016_matchstick
** 
** Made by Maxime PICOT
** Login   <shielder@epitech.net>
** 
** Started on  Mon Feb 20 13:12:19 2017 Maxime PICOT
** Last update Thu Feb 23 00:51:27 2017 Maxime PICOT
*/

#include <stdlib.h>
#include <unistd.h>
#include "alum.h"

int	random_gen(int min, int max)
{
  int	gen;

  min = 1;
  gen = ((rand() % (max - min)) + min);
  return (gen);
}

void	print_last_line(int matches, int line)
{
  my_putstr("IA removed ");
  my_putnbr(matches);
  my_putstr(" match(es) from line ");
  my_putnbr(line);
  my_putchar('\n');
}

char	**ia_turn(char **map, int size, int limit)
{
  int	line;
  int	matches;
  char	**new_map;

  my_putstr("AI's turn...\n");
  line = random_gen(1, (size + 1));
  while ((count_matches(map[line]) == 0))
    line = random_gen(1, (size + 1));
  while ((matches = random_gen(1, (limit + 1))) > count_matches(map[line]))
    matches = random_gen(1, (limit + 1));
  if ((check_win(map)) == 2)
    new_map = rmv_matches(map, line, 1, size);
  else if ((check_win(map)) == 1) // you can remove all this 'else if' block to make the game winnable
    {                             // and so the AI will stop cheating !
      new_map = ia_cheats(map, line, size);
      display_map(new_map);
      return (new_map);
    }
  else
    new_map = rmv_matches(map, line, matches, size);
  print_last_line(matches, line);
  display_map(new_map);
  return (new_map);
}
