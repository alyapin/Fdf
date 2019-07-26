/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzina <kzina@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 16:41:55 by kzina             #+#    #+#             */
/*   Updated: 2019/07/26 18:11:39 by kzina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../libft/libft.h"

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

int     check(char *str);
t_cord  *pars(char *str);
int		ft_atoi_base(char *nb, int base);
void    controls(t_mlx *param);
t_mlx   *init_map(void);
int			ft_atoi_base(char *nb, int base);
t_cord      *new_t_cord(int x, int y, int z, int color);
void        push_back_t_cord(t_cord **head, int x, int y, int z, int color);

#endif
