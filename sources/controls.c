/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzina <kzina@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 17:10:19 by kzina             #+#    #+#             */
/*   Updated: 2019/08/03 20:06:13 by kzina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../libft/libft.h"
#include "mlx.h"

void    clear_img(t_mlx *win)
{
    ft_bzero(win->img->data_address, WIDTH * HEIGH * 4);
    mlx_put_image_to_window(win->mlx, win->win, win->img->image, 0, 0);
}

int     key_press(int keycode, t_mlx *param)
{
    if (keycode == 53)
    {
        exit(0);
        mlx_destroy_image(param->mlx, param->img->image);
    }
    if (keycode == 12)
    {
        param->dz += 1;
        clear_img(param);
        temp_draw_map(param->cord, param);
    }
    if (keycode == 13)
    {
        param->dz -= 1;
        clear_img(param);
        temp_draw_map(param->cord, param);
    }
    if (keycode == 125)
    {
        param->dx -= 10;
        clear_img(param);
        temp_draw_map(param->cord, param);
    }
    if (keycode == 126)
    {
        param->dx += 10;
        clear_img(param);
        temp_draw_map(param->cord, param);
    }
    if (keycode == 123)
    {
        param->dy += 10;
        clear_img(param);
        temp_draw_map(param->cord, param);
    }
    if (keycode == 124)
    {
        param->dy -= 10;
        clear_img(param);
        temp_draw_map(param->cord, param);
    }
    if (keycode == 69)
    {
        param->fact += 1;
        clear_img(param);
        temp_draw_map(param->cord, param);
    }
    if (keycode == 78)
    {
        param->fact -= 1;
        clear_img(param);
        temp_draw_map(param->cord, param);
    }
    return 0;
}

void    controls(t_mlx *param)
{
    mlx_hook(param->win, 2, 0, key_press, param);
    /* mlx_hook(param->win, 3, 0, key_release, param);
    mlx_hook(param->win, 4, 0, mouse_press, param);
    mlx_hook(param->win, 5, 0, mouse_release, param);
    mlx_hook(param->win, 6, 0, mouse_move, param);
    mlx_hook(param->win, 12, 0, expose, param);*/
    mlx_hook(param->win, 17, 0, close, param);
}