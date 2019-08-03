/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   temp_draw_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzina <kzina@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/27 16:40:34 by kzina             #+#    #+#             */
/*   Updated: 2019/08/03 15:36:00 by kzina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../libft/libft.h"
#include "math.h"
#include "mlx.h"

void        render(t_mlx *param, t_cord **map)
{
    int x;
    int x1;
    int y;
    int z;

    x = 0;
    while(x < param->lines * param->coloms)
    {
        map[x]->x *= param->fact;
        x1 = map[x]->x;
        map[x]->y *= param->fact;
        y = map[x]->y;
        map[x]->z *= param->fact;
        z = map[x]->z;
        x++;
    }
}

t_linecor   *write_cor(t_cord *map, t_cord *map2)
{
    t_linecor   *line;

    line = (t_linecor *)ft_memalloc(sizeof(t_linecor));
    //rotate(&map);
    //rotate(&map2);
    //iso(&map->x, &map->y, map->z);
    //iso(&map2->x, &map2->y, map2->z);
    line->x0 = (map->x + map->y) * sin(0.523599) - map->z + 500;
    line->y0 = (map->x - map->y) * cos(0.523599) + 500;
    line->x1 = (map2->x + map2->y) * sin(0.523599) - map2->z + 500;
    line->y1 = (map2->x - map2->y) * cos(0.523599) + 500;
    return (line);
}

void        temp_draw_map(t_cord **map, t_mlx *param)
{
    int         x;
    int         y;
    t_linecor   *xy;

    y = 0;
    render(param, map);
    while (y < param->lines)
    {
        x = 0;
        while (x < param->coloms)
        {
            if (y > 0)
            {
                xy = write_cor(map[x + (y * param->coloms)], map[x + ((y - 1) * param->coloms)]);
                draw(xy, param);
            }
            if (x != param->coloms - 1)
            {
                xy = write_cor(map[x + (y * param->coloms)], map[x + 1 +(y * param->coloms)]);
                draw(xy, param);
            }
            x++;
        }
        y++;
    }
    mlx_put_image_to_window(param->mlx, param->win, param->img->image, 0, 0);
}