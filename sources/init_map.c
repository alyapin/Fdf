/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzina <kzina@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 17:40:57 by kzina             #+#    #+#             */
/*   Updated: 2019/08/03 19:02:21 by kzina            ###   ########.fr       */
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
    if ((ses->img = (t_image *)ft_memalloc(sizeof(t_image))) == NULL)
        return (NULL);
    ses->mlx = mlx_init();
    ses->win = mlx_new_window(ses->mlx, WIDTH, HEIGH, "FDF");
    ses->img = init_image(ses);
    ses->dx = 0;
    ses->dy = 0;
    return (ses);
}

t_image *init_image(t_mlx *ses)
{
    t_image *img;
    
    if ((img = (t_image *)ft_memalloc(sizeof(t_image))) == NULL)
        return (NULL);
    if ((img->image = mlx_new_image(ses->mlx, WIDTH, HEIGH)) == NULL)
        return(NULL);
    img->data_address = (int *)mlx_get_data_addr(img->image, &img->bpp, &img->line_size, &img->endian);
    img->line_size /= 4;
    return (img);
}