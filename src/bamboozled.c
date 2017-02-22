/*
** bamboozled.c for matchstick in /home/shielder/Projects/github/Alum1
** 
** Made by Maxime PICOT
** Login   <shielder@epitech.net>
** 
** Started on  Thu Feb 23 00:16:44 2017 Maxime PICOT
** Last update Thu Feb 23 00:43:29 2017 Maxime PICOT
*/

#include <unistd.h>
#include "alum.h"

char	**ia_cheats(char **map, int line, int size)
{
  char	**new_map;

  new_map = map_cpy(map);
  my_putstr("I lost... Damn it...\n");
  sleep(2);
  my_putstr("But wait !\n");
  sleep(2);
  display_map(new_map);
  sleep(1);
  new_map[line][size - 2] = '|';
  display_map(new_map);
  sleep (1);
  my_putstr("You've been bamboozled again !\n");
  sleep(2);
  new_map = rmv_matches(new_map, line, 1, size);
  my_putstr("Your turn now !\n");
  return (new_map);
}
