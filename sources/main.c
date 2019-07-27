/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzina <kzina@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 15:24:18 by kzina             #+#    #+#             */
/*   Updated: 2019/07/27 17:56:04 by kzina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../libft/libft.h"
#include "mlx.h"

/*int     deal(t_mlx *t)
{
    char s;
    s = 'a';

    mlx_pixels_put(t->mlx, t->win, 250, 250, 0xFFFFFF); 
    return 0;
}*/
void    draw_map(t_cord *map, t_mlx *param)
{
    while (map)
    {
        mlx_pixel_put(param->mlx, param->win, (map->x * 10) / ((map->z + 10)* 10) + 250, map->y / (map->z + 10) + 250, 0xFFFFFF);
        mlx_pixel_put(param->mlx, param->win, (map->x * 10) / ((map->z + 10)* 10) + 250, map->y / (map->z + 10) + 250, 0xFFFFFF);
        map = map->next; 
    }
}

char    *reader(int fd)
{
    char    *input;
    char    *temp;
    int     ct_str;

    ct_str = 0;
    input = (char*)ft_memalloc(sizeof(char));
    while (get_next_line(fd, &temp) > 0)
    {
        input = ft_strjoin(input, temp);
        input = ft_strjoin(input, "\n");
        ct_str++;
    }
    if (ct_str == 0)
        return NULL;
    return (input);
}

int     main(int ac, char **av)
{   
    t_mlx       *t;
    char        *str;
    //t_linecor   *xy;
    t_cord      *map;
    t_image     *img;
    int         z[10][10] = {{1,1,1,1,1,1,1,1,1,1},{1,1,1,1,1,1,1,1,1,1},{1,1,1,1,1,1,1,1,1,1},{1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1},{1,1,1,1,1,1,1,1,1,1},{1,1,1,1,1,1,1,1,1,1},{1,1,1,1,1,1,1,1,1,1},{1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1}};

    //xy = (t_linecor *)ft_memalloc(sizeof(t_linecor));
    img = (t_image *)ft_memalloc(sizeof(t_image));
    if (ac != 2)
    {
        ft_putstr("usage: fdf input_file\n");
        return (1);
    }
    if ((str = reader(open(av[1], O_RDONLY))) == NULL)
    {
        ft_putstr("reading from file error\n");
        return (1);
    }
    t = init_map();
    controls(t);
    map = pars(str);
    //draw_map(map, t);
    img->image = mlx_new_image(t->mlx, 1000, 1000);
    img->data_address = (int *) mlx_get_data_addr(img->image, &img->bpp, &img->line_size, &img->endian);
    img->line_size /= 4;
    img->t = t;
    temp_draw_map(z, img);
    mlx_loop(t->mlx);
    return (0);
}
