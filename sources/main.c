/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzina <kzina@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 15:24:18 by kzina             #+#    #+#             */
/*   Updated: 2019/07/26 15:03:57 by kzina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../libft/libft.h"
#include "mlx.h"
#include <errno.h>
#include <fcntl.h>
#include <stdlib.h>

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
        printf("%d -- x, %d -- y, %d -- z", map->x, map->y, map->z);
        map = map->next;
    }
    mlx_pixel_put(param->mlx, param->win, 100, 100, 0xFFFFFF);
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
    t_mlx   *t;
    char    *str;
    t_cord  *map;

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
    draw_map(map, t);
    mlx_loop(t->mlx);
    return (0);
}
