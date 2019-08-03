/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzina <kzina@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 12:27:41 by kzina             #+#    #+#             */
/*   Updated: 2019/08/03 15:14:10 by kzina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../libft/libft.h"
#include "math.h"
#include "mlx.h"

void        x_rotation(t_cord **map, double angle)
{
    int     prev_y;
    int     prev_z;
    t_cord  *res;

    res = *map;    
    prev_y = res->y;
    prev_z = res->y;
    res->y = prev_y * cos(angle) + prev_z * sin(angle);
    res->z = -prev_y * sin(angle) + prev_z * cos(angle);
}

void        y_rotation(t_cord **map, double angle)
{
    int     prev_x;
    int     prev_z;
    t_cord  *res;

    res = *map;
    prev_x = res->x;
    prev_z = res->z;
    res->x = prev_x * cos(angle) + prev_z * sin(angle);
    res->z = -prev_x * sin(angle) + prev_z * cos(angle);
}

void        z_rotation(t_cord **map, double angle)
{
    int     prev_x;
    int     prev_y;
    t_cord *res;
    
    res = *map;
    prev_x = res->x;
    prev_y = res->y;
    res->x = prev_x * cos(angle) - prev_y * sin(angle);
    res->y = prev_x * sin(angle) + prev_y * cos(angle);
}

void    iso(int *x, int *y, int z)
{
    int previous_x;
    int previous_y;

    previous_x = *x;
    previous_y = *y;
    *x = ((previous_x - previous_y) * sin(0.523599)  - z) * 100 + 500;
    *y = ((previous_x + previous_y) * cos(0.523599)) * 100 + 500;
}

void   rotate(t_cord **z)
{
    x_rotation(z, 47*3.14/180);
    y_rotation(z, 30*3.14/180);
    z_rotation(z, 0);
}