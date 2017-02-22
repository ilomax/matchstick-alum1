/*
** error.c for matchstick in /home/shielder/Projects/CPE/CPE_2016_matchstick
** 
** Made by Maxime PICOT
** Login   <shielder@epitech.net>
** 
** Started on  Wed Feb 22 14:53:27 2017 Maxime PICOT
** Last update Wed Feb 22 15:07:13 2017 Maxime PICOT
*/

#include <unistd.h>

void	my_putchar_err(char c)
{
  write(2, &c, 1);
}

void	my_putsterr(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      my_putchar_err(str[i]);
      i++;
    }
}

void	my_putnbr_err(int nb)
{
  int	mod;

  if (nb < 0)
    {
      my_putchar_err('-');
      nb *= -1;
    }
  if (nb >= 0)
    {
      if (nb >= 10)
	{
	  mod = (nb % 10);
	  nb = (nb - mod) / 10;
	  my_putnbr_err(nb);
	  my_putchar_err('0' + mod);
	}
      else
	my_putchar_err('0' + (nb % 10));
    }
}
