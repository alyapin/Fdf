/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzina <kzina@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 17:10:19 by kzina             #+#    #+#             */
/*   Updated: 2019/07/24 17:28:39 by kzina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../libft/libft.h"
#include "mlx.h"

int     key_press(int keycode, t_mlx *param)
{
    if (keycode == 53)
        exit(0);
    if (keycode == 18)
        mlx_pixel_put(param->mlx, param->win, 250, 250, 0xEAEAEA);
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