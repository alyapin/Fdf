/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzina <kzina@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 16:41:55 by kzina             #+#    #+#             */
/*   Updated: 2019/08/03 15:20:52 by kzina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../libft/libft.h"
# define WIDTH 1000
# define HEIGH 1000

typedef struct      s_image
{
    void            *mlx;
    void            *w;
    int             *image;
    int             *data_address;
    int             bpp;
    int             line_size;
    int             endian;
}                   t_image;

typedef struct      s_cord
{
    int             x;
    int             y;
    int             z;
    int             color;
}                   t_cord;

typedef struct      s_res
{
    int             x;
    int             y;
    int             z;
    int             color;
}                   t_res;

typedef struct      s_mlx
{
    void            *mlx;
    void            *win;
    t_image         *img;
    t_cord          **cord;
    int             coloms;
    int             lines;
    int             fact;
}                   t_mlx;

typedef struct      s_line
{
    int             dx;
    int             dy;
    int             error;
    int             k;
    int             ystep;
    int             y;
    int             x;
}                   t_line;

typedef struct      s_linecor
{
    int             x0;
    int             y0;
    int             x1;
    int             y1;
    int             color0;
    int             color1;
}                   t_linecor;

int     check(char *str);
t_cord  **pars(char *str, t_mlx *map);
int		ft_atoi_base(char *nb, int base);
void    controls(t_mlx *param);
t_mlx   *init_map(void);
int		ft_atoi_base(char *nb, int base);
t_cord  *new_t_cord(int x, int y, int z, int color);
void    push_back_t_cord(t_cord **head, int x, int y, int z, int color);
void    draw(t_linecor  *xy, t_mlx *param);
void    temp_draw_map(t_cord **map, t_mlx *param);
t_image *init_image(t_mlx *ses);
void    rotate(t_cord **z);
void    iso(int *x, int *y, int z);

#endif
