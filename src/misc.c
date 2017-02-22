/*
** misc.c for matchstick in /home/shielder/Projects/CPE/CPE_2016_matchstick
** 
** Made by Maxime PICOT
** Login   <shielder@epitech.net>
** 
** Started on  Mon Feb 13 17:40:40 2017 Maxime PICOT
** Last update Wed Feb 22 16:04:07 2017 Maxime PICOT
*/

#include <unistd.h>
#include <stdlib.h>
#include "alum.h"

char	**map_cpy(char **map)
{
  int	i;
  int	j;
  char	**new_map;

  i = -1;
  j = -1;
  if (map == NULL)
    return (NULL);
  while (map[++i]);
  new_map = malloc((sizeof(char *) * (i + 1)));
  while (++j < i)
    new_map[j] = my_strdup(map[j]);
  new_map[j] = NULL;
  return (new_map);
}

void	display_map(char **map)
{
  int	i;

  i = 0;
  while (map && map[i] != NULL)
    {
      my_putstr(map[i]);
      my_putchar('\n');
      i++;
    }
}

int	count_matches(char *line)
{
  int	i;
  int	count;

  i = 0;
  count = 0;
  if (line)
    {
      while (line[i] != '\0')
	{
	  if (line[i] == '|')
	    count++;
	  i++;
	}
    }
  return (count);
}

char    *my_memset(char *tab, char c, int size)
{
  int   i;

  i = 0;
  while (size && c && tab && i < size)
    {
      tab[i] = c;
      i++;
    }
  tab[i] = '\0';
  return (tab);
}

int	my_getnbr(char *str)
{
  int	i;
  int	res;

  i = 0;
  res = 0;
  if (str[0] && str[0] == '-')
    i++;
  while (str[i])
    {
      if ((str[i] < '0' || str[i] > '9'))
	return (0);
      res += str[i] - 48;
      res *= 10;
      i++;
    }
  res /= 10;
  if (str[0] == '-')
    return (res * -1);
  else
    return (res);
}
