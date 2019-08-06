/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzina <kzina@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 17:10:19 by kzina             #+#    #+#             */
/*   Updated: 2019/08/06 18:55:26 by kzina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../libft/libft.h"
#include "mlx.h"

void	xy_rotate(int keycode, t_mlx *param)
{
	if (keycode == 91)
		param->y += 0.1;
	if (keycode == 84)
		param->y -= 0.1;
	if (keycode == 86)
		param->x -= 0.1;
	if (keycode == 88)
		param->x += 0.1;
	render(param->cord, param);
}

void	offset(int keycode, t_mlx *param)
{
	if (keycode == 125)
		param->dx -= 10;
	if (keycode == 126)
		param->dx += 10;
	if (keycode == 123)
		param->dy += 10;
	if (keycode == 124)
		param->dy -= 10;
	render(param->cord, param);
}

void	inc_fact(int keycode, t_mlx *param)
{
	if (keycode == 69)
		param->fact += 1;
	if (keycode == 78)
		param->fact -= 1;
	render(param->cord, param);
}

int		key_press(int keycode, t_mlx *param)
{
	if (keycode == 53)
	{
		exit(0);
		mlx_destroy_image(param->mlx, param->img->image);
	}
	if (keycode == 91 || keycode == 88 || keycode == 84 || keycode == 86)
		xy_rotate(keycode, param);
	if (keycode == 125 || keycode == 126 || keycode == 123 || keycode == 124)
		offset(keycode, param);
	if (keycode == 69 || keycode == 78)
		inc_fact(keycode, param);
	return (0);
}

void	controls(t_mlx *param)
{
	mlx_hook(param->win, 2, 0, key_press, param);
	/* mlx_hook(param->win, 3, 0, key_release, param);
	mlx_hook(param->win, 4, 0, mouse_press, param);
	mlx_hook(param->win, 5, 0, mouse_release, param);
	mlx_hook(param->win, 6, 0, mouse_move, param);
	mlx_hook(param->win, 12, 0, expose, param);*/
	mlx_hook(param->win, 17, 0, close, param);
}
