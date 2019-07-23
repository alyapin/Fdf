/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzina <kzina@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 17:10:19 by kzina             #+#    #+#             */
/*   Updated: 2019/07/23 18:22:37 by kzina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "/Users/kzina/fdf/includes/fdf.h"
#include "/Users/kzina/fdf/libft/libft.h"
#include "mlx.h"

int     key_press(int keycode, t_mlx *param)
{
    if (keycode == 53)
        exit(0);
    if (keycode == 18)
        mlx_string_put(param->mlx, param->win, 250, 250, 0xEAEAEA, "what the fuck is this?");
    return 0;
}
/* int     close(void *param)
{
    exit(0);
}*/

void    controls(void *param)
{
    t_mlx *t;

    t = (t_mlx *) param;
    mlx_hook(t->win, 2, 0, key_press, t);
    /* mlx_hook(param->win, 3, 0, key_release, param);
    mlx_hook(param->win, 4, 0, mouse_press, param);
    mlx_hook(param->win, 5, 0, mouse_release, param);
    mlx_hook(param->win, 6, 0, mouse_move, param);
    mlx_hook(param->win, 12, 0, expose, param);*/
    mlx_hook(t->win, 17, 0, close, t);
}