/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzina <kzina@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 15:24:18 by kzina             #+#    #+#             */
/*   Updated: 2019/08/03 15:35:45 by kzina            ###   ########.fr       */
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
    t_cord      **map;
    int         x;

    //xy = (t_linecor *)ft_memalloc(sizeof(t_linecor));
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
    x = -1;
    t = init_map();
    map = pars(str, t);
    temp_draw_map(map, t);
    controls(t);
    mlx_loop(t->mlx);
    return (0);
}
