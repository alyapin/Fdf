/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtruman <mtruman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 15:24:18 by kzina             #+#    #+#             */
<<<<<<< HEAD:main.c
<<<<<<< HEAD
/*   Updated: 2019/07/23 16:39:01 by kzina            ###   ########.fr       */
=======
/*   Updated: 2019/07/24 15:32:10 by mtruman          ###   ########.fr       */
>>>>>>> petya
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
<<<<<<< HEAD
=======
<<<<<<< HEAD:main.c
/*   Updated: 2019/07/23 17:04:41 by kzina            ###   ########.fr       */
=======
/*   Updated: 2019/07/24 17:51:01 by kzina            ###   ########.fr       */
>>>>>>> alyapin:sources/main.c
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
>>>>>>> d8e0533aa0ac10e99b4a1aa7c533e14a410bbcff:sources/main.c
#include "mlx.h"
=======
//#include "mlx.h"
>>>>>>> petya
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
<<<<<<< HEAD:main.c
    //ft_putstr(input);
    //printf("%d",check(input));
    pars(input);
    //if (ct_str == 0)
  //      return NULL;
=======
    if (ct_str == 0)
        return 1;
>>>>>>> d8e0533aa0ac10e99b4a1aa7c533e14a410bbcff:sources/main.c
    return 0;
}

int     key_press(int keycode, void *param)
{
    if (keycode == 53)
        exit(0);
    return (0);
}

int     main(int ac, char **av)
{   
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
<<<<<<< HEAD:main.c
    mlx_ptr = mlx_init();
    win_ptr = mlx_new_window(mlx_ptr, 500, 500, "First window");
    t = (t_mlx*)malloc(sizeof(t_mlx));
    t->mlx = mlx_ptr;
    t->win = win_ptr;
    mlx_pixel_put(mlx_ptr, win_ptr, 250, 250, 0xFFFFFF);
<<<<<<< HEAD:main.c
    mlx_hook(t->win, 17, 0, close, (void *)0);
<<<<<<< HEAD
    mlx_loop(win_ptr);
=======
    mlx_loop(win_ptr);*/
>>>>>>> petya
=======
    mlx_hook(t->win, 2, 0, key_press, t);
    mlx_loop(win_ptr);
=======
    t = init_map();
    controls(t);
    mlx_loop(t->mlx);
>>>>>>> alyapin:sources/main.c
>>>>>>> d8e0533aa0ac10e99b4a1aa7c533e14a410bbcff:sources/main.c
    return (0);
}
