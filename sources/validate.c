/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzina <kzina@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 14:05:02 by kzina             #+#    #+#             */
/*   Updated: 2019/08/03 15:24:22 by kzina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../libft/libft.h"
#include <string.h>
#include <stdio.h>

int     color(char *str)
{
    char *tmp;
    int i;
    int j;

    i = 0;
    j = 0;
    tmp = malloc(8);
    while(str[i] != ',' && str[i])
        i++;
    i = str[i] ? i + 3 : i;
    while (str[i] != '\0')
    {
        tmp[j] = str[i];
        i++;
        j++;
    }
    j = ft_atoi_base(tmp, 16);
    free(tmp);
    return (j);
}

int		ft_count_word1(char const *str, char c)
{
	int		count;

	count = 0;
	while (*str)
	{
		while (*str == c)
			str++;
		while (*str && *str != c)
			str++;
		if (*str == c || (*str == '\0' && *(str - 1) != c))
			count++;
	}
	return (count);
}
int  check_point(char *line)
{
    int i;

    i = 0;
    if (line[i] == '-')
        i++;
    while (line[i]>= '0' && line[i]<= '9')
        i++;
    if(line[i] == '\0')
        return (1);
    if(line[i] == ',' && line[i + 1]=='0' && line[i + 2] == 'x')
        return (color(&line[i]));
    return (-1);
}

int check(char *str)
{
    int i;
    int k;
    int n;

    i = 0;
    k = 0;
    n = 0;
    while(str[i] != '\n')
    {
        if (str[i] == ' ')
            k++;
        i++;
    }
    i = 0;
    while(str[i] != '\0')
    {
        if(str[i] == ' ')
            n++;
        if(str[i] == '\n')
        {
            if(k != n)
                return (0);
            else 
                n = 0;
        }
        i++;
    }
    return (1);
}

void    ft_corddel(t_cord *head)
{
    t_cord *temp;
    temp = head;
    free(temp);
}
int     put_cord(char **str, t_cord **cord, int i, int l)
{
    int j;

    j = 0;
    while (j < l)
        {
            if(check_point(str[j]) != -1)
                {
                    cord[i] = (t_cord *)ft_memalloc(sizeof(t_cord));
                    cord[i]->y = i / l;
                    cord[i]->x = i - (cord[i]->y * l);
                    cord[i]->z = ft_atoi(str[j]);
                    cord[i]->color = check_point(str[j]);
                    i++;
                }
            else 
            {
                ft_strdel((void **)cord);
                return (0);
            }
            j++;
        }
    return(i);
}

t_cord  **pars(char *str, t_mlx *map)
{
    t_cord  **head;
    char    **line;
    char    **line2;
    int     i;
    int     j;

    i = 0;
    j = 0;
    line = ft_strsplit(str, '\n');
    head = (t_cord **)ft_memalloc(sizeof(t_cord *)*ft_count_word1(str, '\n')
    *ft_count_word1(line[i], ' '));
    while (i < ft_count_word1(str, '\n'))
    {
        line2 = ft_strsplit(line[i], ' ');
        j = put_cord(line2, head, j, ft_count_word1(line[i], ' '));
        i++;
    }
    map->lines = ft_count_word1(str, '\n');
    map->coloms = ft_count_word1(line[1], ' ');
    map->fact = WIDTH / (map->lines > map->coloms ? map->lines * 2 : map->coloms * 2);
    return (head);
}