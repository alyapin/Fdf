/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtruman <mtruman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 16:41:55 by kzina             #+#    #+#             */
<<<<<<< HEAD:fdf.h
/*   Updated: 2019/07/24 18:16:28 by mtruman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "libft/libft.h"
=======
/*   Updated: 2019/07/24 17:50:37 by kzina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
>>>>>>> d8e0533aa0ac10e99b4a1aa7c533e14a410bbcff:includes/fdf.h

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
<<<<<<< HEAD:fdf.h
int check(char *str);
int pars(char *str);
int			ft_atoi_base(char *nb, int base);

#endif
=======

void    controls(t_mlx *param);
t_mlx   *init_map(void);
>>>>>>> d8e0533aa0ac10e99b4a1aa7c533e14a410bbcff:includes/fdf.h
