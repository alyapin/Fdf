/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   temp_draw_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzina <kzina@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/27 16:40:34 by kzina             #+#    #+#             */
/*   Updated: 2019/07/31 15:03:11 by kzina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../libft/libft.h"
#include "math.h"
#include "mlx.h"

void        temp_draw_map(int z[10][10], t_mlx *param, int fact)
{
    int         x;
    int         y;
    t_linecor   *xy;

    y = 0;
    xy = (t_linecor *)ft_memalloc(sizeof(t_linecor));
    (void)z;
    while (y < 10)
    {
        x = 0;
        while (x < 10)
        {
            if (y > 0)
            {
                /* xy->x0 = x * 25;
                xy->y0 = y * 25;
                xy->y1 = (y - 1) * 25;
                xy->x1 = x * 25;*/
                xy->x0 = (x - y) * cos(0.523599) * fact;
                xy->y0 = (-z[y][x] + (x - y) * sin(0.523599)) * fact;
                xy->x1 = (x - y - 1) * cos(0.523599) * fact;
                xy->y1 = (-z[y - 1][x] + (x - y - 1) * sin(0.523599)) * fact;
                draw(xy, param);
            }
            if (x != 9)
            {
                /*xy->x0 = x * 25;
                xy->y0 = y * 25;
                xy->x1 = (x + 1) * 25;
                xy->y1 = y * 25;*/
                xy->x0 = (x - y) * cos(0.523599) * fact;
                xy->y0 = (-z[y][x] + (x - y) * sin(0.523599)) * fact;
                xy->x1 = (x + 1 - y) * cos(0.523599) * fact;
                xy->y1 = (-z[y][x + 1] + (x + 1 - y) * sin(0.523599)) * fact;
                draw(xy, param);
            }
            x++;
        }
        y++;
    }
}