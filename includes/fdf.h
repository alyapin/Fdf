/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzina <kzina@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 16:41:55 by kzina             #+#    #+#             */
/*   Updated: 2019/07/23 18:23:18 by kzina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "/Users/kzina/fdf/libft/libft.h"

struct          s_mlx
{
    void    *mlx;
    void    *win;
}typedef        t_mlx;

struct          s_cord
{
    int             x;
    int             y;
    int             color;
    int             z;
    struct s_cord   *next;
}typedef        t_cord;

void    controls(void *param);