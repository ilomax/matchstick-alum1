/*
** alum.h for alum in /home/shielder/Projects/CPE/CPE_2016_matchstick
** 
** Made by Maxime PICOT
** Login   <shielder@epitech.net>
** 
** Started on  Tue Feb 14 13:49:20 2017 Maxime PICOT
** Last update Wed Feb 22 16:02:45 2017 Maxime PICOT
*/

#ifndef ALUM_H_
# define ALUM_H_

# define READ_SIZE 32

typedef struct	s_game
{
  int	cnt;
  int	line;
}		t_game;

void	display_map(char **map);
void	reprot_norm(t_game *game, int limit, char *line, int size);
void	my_putchar_err(char c);
void	my_putsterr(char *str);
void	my_putnbr_err(int nb);
void	my_putchar(char c);
void	my_putnbr(int nb);
void	my_putstr(char *str);

int     my_getnbr(char *str);
int	count_matches(char *line);
int	get_matches_count(int limit, char *line, int size, t_game *game);
int	my_strlen(char *str);
int	random_gen(int min, int max);
int	isnum(char *str);
int	check_win(char **map);

char	*get_next_line(const int fd);
char    *my_memset(char *tab, char c, int size);
char	*my_strdup(char	*str);

char	**create_map(int size);
char	**fill_map(int size);
char	**add_alums(char **map, int size);
char	**map_cpy(char **map);
char	**my_turn(int size, int limit, char **map);
char	**ia_turn(char **map, int size, int limit);
char	**rmv_matches(char **map, int line, int cnt, int size);

#endif /* !ALUM_H_ */
