/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzina <kzina@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 16:41:55 by kzina             #+#    #+#             */
/*   Updated: 2019/07/27 14:45:35 by kzina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../libft/libft.h"

typedef struct      s_mlx
{
    void    *mlx;
    void    *win;
}                   t_mlx;

typedef struct      s_cord
{
    int             x;
    int             y;
    int             color;
    int             z;
    struct s_cord   *next;
}                   t_cord;
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
}                   t_linecor;



int     check(char *str);
t_cord  *pars(char *str);
int		ft_atoi_base(char *nb, int base);
void    controls(t_mlx *param);
t_mlx   *init_map(void);
int		ft_atoi_base(char *nb, int base);
t_cord  *new_t_cord(int x, int y, int z, int color);
void    push_back_t_cord(t_cord **head, int x, int y, int z, int color);
void    draw(t_linecor  *xy, t_mlx *param);

#endif
