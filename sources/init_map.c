/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzina <kzina@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 17:40:57 by kzina             #+#    #+#             */
/*   Updated: 2019/07/31 14:53:07 by kzina            ###   ########.fr       */
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
    ses->win = mlx_new_window(ses->mlx, 1000, 1000, "FDF");
    ses->img = init_image(ses);
    return (ses);
}

t_image *init_image(t_mlx *ses)
{
    t_image *img;
    
    if ((img = (t_image *)ft_memalloc(sizeof(t_image))) == NULL)
        return (NULL);
    if ((img->image = mlx_new_image(ses->mlx, 500, 500)) == NULL)
        return(NULL);
    img->data_address = (int *)mlx_get_data_addr(img->image, &img->bpp, &img->line_size, &img->endian);
    img->bpp /= 4;
    return (img);
}