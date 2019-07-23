/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzina <kzina@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 15:24:18 by kzina             #+#    #+#             */
/*   Updated: 2019/07/23 16:39:01 by kzina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
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
int     reader(int fd)
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
    ft_putstr(input);
    if (ct_str == 0)
        return NULL;
    return 0;
}

int     main(int ac, char **av)
{   
    void    *mlx_ptr;
    void    *win_ptr;
    t_mlx   *t;

    if (ac != 2)
    {
        ft_putstr("usage: fdf input_file\n");
        return (1);
    }
    if (reader(open(av[1], O_RDONLY)) == 1)
    {
        ft_putstr("reading from file error\n");
        return (1);
    }
    mlx_ptr = mlx_init();
    win_ptr = mlx_new_window(mlx_ptr, 500, 500, "First window");
    t = (t_mlx*)malloc(sizeof(t_mlx));
    t->mlx = mlx_ptr;
    t->win = win_ptr;
    mlx_pixel_put(mlx_ptr, win_ptr, 250, 250, 0xFFFFFF);
    mlx_hook(t->win, 17, 0, close, (void *)0);
    mlx_loop(win_ptr);
    return (0);
}
