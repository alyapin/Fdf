/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_cord_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzina <kzina@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 16:39:02 by kzina             #+#    #+#             */
/*   Updated: 2019/07/26 18:12:03 by kzina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../libft/libft.h"
#include "mlx.h"

t_cord      *new_t_cord(int x, int y, int z, int color)
{
    t_cord  *new;

    new = (t_cord *)ft_memalloc(sizeof(t_cord));
    new->x = x;
    new->y = y;
    new->z = z;
    new->color = color;
    new->next = NULL;
    return (new);
}

void        push_back_t_cord(t_cord **head, int x, int y, int z, int color)
{
    t_cord  *temp;
    t_cord  *iter;

    temp = new_t_cord(x, y, z, color);
    iter = *head;
    if (iter == NULL)
    {
        *head = temp;
        return ;
    }
    while (iter->next)
        iter = iter->next;
    iter->next = temp;
}