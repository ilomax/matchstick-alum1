/*
** misc2.c for matchstick in /home/shielder/Projects/CPE/CPE_2016_matchstick
** 
** Made by Maxime PICOT
** Login   <shielder@epitech.net>
** 
** Started on  Sat Feb 18 22:20:20 2017 Maxime PICOT
** Last update Wed Feb 22 15:51:06 2017 Maxime PICOT
*/

#include <stdlib.h>
#include <unistd.h>

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    i++;
  return (i);
}

char	*my_strdup(char *str)
{
  char	*res;
  int	i;

  i = 0;
  res = malloc(sizeof(char) * (my_strlen(str) + 1));
  while (str[i])
    {
      res[i] = str[i];
      i++;
    }
  res[i] = 0;
  return (res);
}

int	isnum(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] < '0' || str[i] > '9')
	return (0);
      i++;
    }
  return (1);
}

void	my_putchar(char c)
{
  write(1, &c, 1);
}

void	my_putstr(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      my_putchar(str[i]);
      i++;
    }
}
