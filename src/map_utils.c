/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbouidd <ilbouidd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 18:48:38 by ilbouidd          #+#    #+#             */
/*   Updated: 2026/02/19 01:18:38 by ilbouidd         ###   ########.fr       */
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

void map_size(t_game *game)
{
    int i = 0;

    // Hauteur = nombre de lignes
    while (game->map[i])
        i++;
    game->height = i;

    // Largeur = longueur de la première ligne
    if (game->height > 0)
        game->width = ft_strlen(game->map[0]);
    else
        game->width = 0;
}
