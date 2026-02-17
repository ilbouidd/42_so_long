/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbouidd <ilbouidd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 18:36:03 by ilbouidd          #+#    #+#             */
/*   Updated: 2026/02/17 22:59:20 by ilbouidd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

char **copy_map(char **map)
{
    int i = 0;
    int j;
    int len;
    char **copy;

    while (map[i])
        i++;
    copy = malloc(sizeof(char *) * (i + 1));
    if (!copy)
        return (NULL);
    i = 0;
    while (map[i])
    {
        len = 0;
        while (map[i][len])
            len++;
        copy[i] = malloc(sizeof(char) * (len + 1));
        if (!copy[i])
        {
            while (i > 0)
                free(copy[--i]);
            free(copy);
            return (NULL);
        }
        j = 0;
        while (map[i][j])
        {
            copy[i][j] = map[i][j];
            j++;
        }
        copy[i][j] = '\0';
        i++;
    }
    copy[i] = NULL;
    return (copy);
}

void find_player(char **map, int *px, int *py)
{
    int y = 0;
    int x;

    while (map[y])
    {
        x = 0;
        while (map[y][x])
        {
            if (map[y][x] == 'P')
            {
                *px = x;
                *py = y;
                return ;
            }
            x++;
        }
        y++;
    }
}

void flood_fill(char **map, int x, int y)
{
    if (map[y][x] == '1' || map[y][x] == 'f')
        return ;
    map[y][x] = 'f';

    flood_fill(map, x + 1, y);
    flood_fill(map, x - 1, y);
    flood_fill(map, x, y + 1);
    flood_fill(map, x, y - 1);
}

int check_accessible(char **map)
{
    int y = 0;
    int x;

    while (map[y])
    {
        x = 0;
        while (map[y][x])
        {
            if (map[y][x] == 'C' || map[y][x] == 'E')
                return (1);
            x++;
        }
        y++;
    }
    return (0);
}

