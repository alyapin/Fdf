/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzina <kzina@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/27 13:35:52 by kzina             #+#    #+#             */
/*   Updated: 2019/08/03 13:58:52 by kzina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../libft/libft.h"
#include "math.h"
#include "mlx.h"

void    swap_coor(int *x, int *y)
{
    *x = *x + *y;
    *y = *x - *y;
    *x = *x - *y;
}

void    draw_line(t_line *line, int x1, t_mlx *params)
{
    int     x;
    int     y;
    int     k;
    t_image *param;

    param = params->img;
    x = line->x;
    y = line->y;
    k = line->k;
    while (x <= x1)
    {
        if (x > WIDTH || x < 0 || y > HEIGH || y < 0)
            return ;
        param->data_address[(k == 1 ? y : x) * param->line_size + (k == 1 ? x : y)] = 0xFFFFFF;
        line->error -= line->dy;
        if (line->error < 0)
        {
            y +=line->ystep;
            line->error += line->dx;
        }
        x++;
    }
}

void    draw(t_linecor  *xy, t_mlx *param)
{
    t_line  *line;

    line = (t_line *)ft_memalloc(sizeof(t_line));
    line->k = labs(xy->y1 - xy->y0) > labs(xy->x1 - xy->x0) ? 1 : 0;
    if (line->k)
    {
        swap_coor(&xy->x0, &xy->y0);
        swap_coor(&xy->x1, &xy->y1);
    }
    if (xy->x0 > xy->x1)
    {
        swap_coor(&xy->x0, &xy->x1);
        swap_coor(&xy->y0, &xy->y1);
    }
    line->dx = xy->x1 - xy->x0;
    line->dy = labs(xy->y1 - xy->y0);
    line->error = line->dx / 2;
    line->ystep = xy->y0 < xy->y1 ? 1 : -1;
    line->y = xy->y0;
    line->x = xy->x0;
    draw_line(line, xy->x1, param);
}