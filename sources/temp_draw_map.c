/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   temp_draw_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzina <kzina@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/27 16:40:34 by kzina             #+#    #+#             */
/*   Updated: 2019/07/31 18:07:17 by kzina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../libft/libft.h"
#include "math.h"
#include "mlx.h"

void        temp_draw_map(t_cord *map, t_mlx *param, int fact)
{
    int         x;
    int         y;
    t_linecor   *xy;

    y = 0;
    xy = (t_linecor *)ft_memalloc(sizeof(t_linecor));
    while (y < map->lines)
    {
        x = 0;
        while (x < map->coloms)
        {
            if (y > 0)
            {
                xy->x0 = (((x - y) * sin(0.523599) - map->z[y * x])* fact) + 500;
                xy->y0 = ((x + y) * cos(0.523599)  * fact) + 500;
                xy->x1 = (((x - (y - 1)) * sin(0.523599)- map->z[(y-1) * x])* fact) + 500;
                xy->y1 = ((x + (y - 1)) * cos(0.523599)  * fact) + 500;
                draw(xy, param);
            }
            if (x != map->coloms - 1)
            {
                xy->x0 = (((x - y) * sin(0.523599)- map->z[y * x]) * fact) + 500;
                xy->y0 = ((x + y) * cos(0.523599)  * fact) + 500;
                xy->x1 = (((x + 1 - y) * sin(0.523599)- map->z[y * (x+1)]) * fact) + 500;
                xy->y1 = ((x + 1 + y) * cos(0.523599)  * fact) + 500;
                draw(xy, param);
            }
            x++;
        }
        y++;
    }
}