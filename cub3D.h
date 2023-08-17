#ifndef CUB3D_H
#define CUB3D_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <mlx.h>
#include "./gnln/get_next_line.h"

typedef struct t_img
{
  char **no;
  char **so;
  char **we;
  char **ea;
} t_img;

typedef struct map_color_rgb
{
  char **floor;
  char **ceil;
} t_rgb;

typedef struct map_data
{
  t_img *img;
  t_rgb *rgb;
  char  **map;
} t_data;

char	**ft_split(char const *s, char c);
char	*ft_strndup(char const *str, size_t max);
int strlen_2d_array(char **array);
char **read_map(char *mapfile);
int	ft_atoi(const char *str);
void free_double(char **array);
int ft_isdigit(int nbr);
void check_valid_map(t_data *data);
// PARSING 
int parsing_map(t_data *data, char **map);

// check MAP
int check_south(char **sorth);
void  check_nswe(t_data *data);
int error_fd_not_found(char *msg);
int error_map(char *msg);
void check_rgb(t_data *data);
#endif
