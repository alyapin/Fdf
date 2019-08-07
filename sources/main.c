/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzina <kzina@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 15:24:18 by kzina             #+#    #+#             */
/*   Updated: 2019/08/07 18:47:54 by kzina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../libft/libft.h"
#include "mlx.h"

void	swap_coor(int *x, int *y)
{
	*x = *x + *y;
	*y = *x - *y;
	*x = *x - *y;
}

char	*reader(int fd)
{
	char	*input;
	char	*temp;
	char	*to_free;
	int		ct_str;

	ct_str = 0;
	input = (char*)ft_memalloc(sizeof(char));
	while (get_next_line(fd, &temp) > 0)
	{
		to_free = input;
		input = ft_strjoin(input, temp);
		ft_strdel((void **)&to_free);
		to_free = input;
		input = ft_strjoin(input, "\n");
		ft_strdel((void **)&to_free);
		ft_strdel((void **)&temp);
		ct_str++;
	}
	ft_strdel((void **)&temp);
	if (ct_str == 0)
		return (NULL);
	return (input);
}

int		main(int ac, char **av)
{
	t_mlx	*t;
	char	*str;
	t_cord	**map;
	int		x;

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
	t->cord = map;
	controls(t);
	render(map, t);
	mlx_loop(t->mlx);
	return (0);
}
