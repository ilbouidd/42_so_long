/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbouidd <ilbouidd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 14:24:01 by ilbouidd          #+#    #+#             */
/*   Updated: 2026/02/16 18:11:06 by ilbouidd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int error_outline(char *map)
{
    int i;

    i = 0;
    while (map[i])
    {
        if (map[i] != '1')
            return (1);
        i++;
    }
    return (0);
}

int error_outline_mid(char *map)
{
    int i;

    i = ft_strlen(map) - 1;
    if (map[0] != '1')
        return (1);
    else if (map[i] != '1')
        return (1);
    return (0);
}


int error_e_p(char **map)
{
    int i;
    int j;
    int count_e;
    int count_p;

    i = 0;
    count_e = 0;
    count_p = 0;
    while (map[i])
    {
        j = 0;
        while (map[i][j])
        {
            if (map[i][j] == 'E')
                count_e++;
            else if (map[i][j] == 'P')
                count_p++;
            j++;
        }
        i++;
    }
    if (count_e != 1 || count_p != 1)
        return (1);
    return (0);
}


int error_c(char **map)
{
    int i;
    int j;
    int count_c;

    i = 0;
    count_c = 0;
    while (map[i])
    {
        j = 0;
        while (map[i][j])
        {
            if (map[i][j] == 'C')
                count_c++;
            j++;
        }
        i++;
    }
    if (count_c <= 0)
        return (1);
    return (0);
}

int error_ber(char  *av)
{
    int i;

    i = 0;
    while (av[i])
        i++;
    if (i < 4)
        return (1);
    if (av[i - 4] == '.' && av[i -3] == 'b'
                && av[i - 2] == 'e' && av[i - 1] == 'r')
                return(0);
    return (1);
}
