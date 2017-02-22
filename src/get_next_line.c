/*
** get_next_line.c for matchstick in /home/shielder/Projects/CPE/CPE_2016_matchstick
** 
** Made by Maxime PICOT
** Login   <shielder@epitech.net>
** 
** Started on  Thu Feb 16 18:19:51 2017 Maxime PICOT
** Last update Thu Feb 16 18:19:56 2017 Maxime PICOT
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "alum.h"

char            *my_strloc(char *buff, int offset)
{
  char          *dest;
  int           i;

  i = 0;
  buff[offset] = '\0';
  if ((dest = malloc((offset + READ_SIZE + 2) * sizeof(char))) == NULL)
    return (NULL);
  i = 0;
  while (buff && buff[i] != '\0')
    {
      dest[i] = buff[i];
      i++;
    }
  dest[i] = '\0';
  free(buff);
  return (dest);
}

char		*my_line(char *buff, int *nbchar, int last)
{
  int		i;
  int		j;
  char		*temp;

  i = 0;
  j = 0;
  while (buff[i] != '\n' && buff[i] != '\0')
    i++;
  if (buff && (buff[i] != '\0' || (last == 1 && i > 0)))
    {
      if ((temp = malloc((i + 1) * sizeof(char))) == NULL)
        return (NULL);
      while (j < i && buff[j] != '\0')
        {
          temp[j] = buff[j];
          j++;
        }
      temp[j] = '\0';
      j++;
      *nbchar += j;
      return (temp);
    }
  return (NULL);
}

void		gnl_clear(char **buff, int *offset, int *nbchar)
{
  *offset = 0;
  *nbchar = 0;
  *buff = NULL;
}

char		*get_next_line(const int fd)
{
  static int	offset = 0;
  static int	nbchar = 0;
  static char	*buff = NULL;
  char		*line;
  int		len;

  if (buff == NULL)
    {
      if ((buff = malloc((READ_SIZE + 1) * sizeof(char))) == NULL)
	return (NULL);
      buff[0] = '\0';
    }
  if (buff[0] != '\0' && (line = my_line(buff + nbchar, &nbchar, 0)) != NULL)
    return (line);
  while ((len = read(fd, buff + offset, READ_SIZE)) > 0 && (offset += len) > 0)
    {
      if ((buff = my_strloc(buff, offset)) == NULL)
	return (NULL);
      if ((line = my_line(buff + nbchar, &nbchar, 0)) != NULL)
	return (line);
    }
  if ((line = my_line(buff + nbchar, &nbchar, 1)) != NULL)
    return (line);
  gnl_clear(&buff, &offset, &nbchar);
  return (NULL);
}
