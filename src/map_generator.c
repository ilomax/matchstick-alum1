/*
** map_generator.c for matchstick in /home/shielder/Projects/CPE/CPE_2016_matchstick
** 
** Made by Maxime PICOT
** Login   <shielder@epitech.net>
** 
** Started on  Mon Feb 13 12:41:50 2017 Maxime PICOT
** Last update Mon Feb 20 13:37:58 2017 Maxime PICOT
*/

#include <stdlib.h>
#include <unistd.h>
#include "alum.h"

char	**create_map(int size)
{
  char	**map;
  int	i;

  i = 0;
  if (size && (map = malloc(sizeof(char *) * (size + 3))) == NULL)
    return (NULL);
  while (i < (size + 2))
    {
      if ((map[i] = malloc(sizeof(char) * (size * 2) + 3)) == NULL)
	return (NULL);
      i++;
    }
  map[i] = NULL;
  return (map);
}

char	**fill_map(int sz)
{
  char	**map;
  int	i;

  i = 0;
  if ((map = create_map(sz)) == NULL)
    return (NULL);
  if ((map[0] = my_memset(map[0], '*', (sz * 2) + 1)) == NULL)
    return (NULL);
  if ((map[sz + 1] = my_memset(map[sz + 1], '*', (sz * 2) + 1)) == NULL)
    return (NULL);
  i = 1;
  while (i < (sz + 1))
    {
      map[i] = my_memset(map[i], ' ', (sz * 2) + 2);
      map[i][0] = '*';
      map[i][(sz * 2)] = '*';
      i++;
    }
  return (map);
}
