/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzina <kzina@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 17:40:57 by kzina             #+#    #+#             */
/*   Updated: 2019/07/24 17:52:54 by kzina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../libft/libft.h"
#include "mlx.h"

t_mlx   *init_map(void)
{
    t_mlx   *ses;

    if ((ses = (t_mlx *)ft_memalloc(sizeof(t_mlx))) == NULL)
        return (NULL);
    ses->mlx = mlx_init();
    ses->win = mlx_new_window(ses->mlx, 1000, 1000, "FDF");
    return (ses);
}