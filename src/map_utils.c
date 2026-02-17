/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbouidd <ilbouidd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 18:48:38 by ilbouidd          #+#    #+#             */
/*   Updated: 2026/02/17 22:27:59 by ilbouidd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int map_height(char **map)
{
    int i;

    i = 0;
    while (map[i])
        i++;
    return (i);
}

int map_width(char **map)
{
    int i;

    if (!map || !map[0])
        return (0);

    i = 0;
    while (map[0][i])
        i++;
    return (i);
}

void    map_size(t_game *game)
{
    game->height = map_height(game->map);
    game->width = map_width(game->map);
}