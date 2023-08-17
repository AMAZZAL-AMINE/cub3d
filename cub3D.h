#ifndef CUB3D_H
#define CUB3D_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <mlx.h>
#include "./gnl/get_next_line.h"

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
#endif
