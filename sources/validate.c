/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzina <kzina@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 14:05:02 by kzina             #+#    #+#             */
/*   Updated: 2019/07/26 15:06:33 by kzina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
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
    while(str[i] != ',')
        i++;
    i= i + 3;
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

int		ft_count_word(char const *str, char c)
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
	return (count - 1);
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
        return (2);
    return (0);
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

    while (head->next)
    {
        temp = head;
        free(temp);
        head = head->next;
    }
}

t_cord  *pars(char *str)
{
    t_cord      *head;
    t_cord      *points;
    char **line;
    char **line2;
    int  i;
    int  j;

    points = (t_cord *)ft_memalloc(sizeof(t_cord*));
    head = points;
    i = 0;
    j = 0;
    line = ft_strsplit(str, '\n');
    while (i <= ft_count_word (str, '\n'))
    {
        line2 = ft_strsplit(line[i], ' ');
        while (j <= ft_count_word(line[i], ' '))
        {
            if(check_point(line2[j]) == 1)
            {
                points->x = i;
                points->y = j;
                points->z = ft_atoi(line2[j]);
                points->next = (t_cord *)ft_memalloc(sizeof(t_cord));
                points = points->next;
            }
            else if(check_point(line2[j]) == 2)
            {
                points->x = i;
                points->y = j;
                points->z = ft_atoi(line2[j]);
                points->color = color(line2[j]);
                points->next = (t_cord *)ft_memalloc(sizeof(t_cord*));
                points = points->next;
            }
            else if((check_point(line2[j]) == 0))
            {
                ft_corddel(head);
                return (NULL);
            }
            j++;
        }
        j = 0;
        i++;
    }
    return (head);
}