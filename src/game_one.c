/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_one.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbouidd <ilbouidd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 12:22:35 by ilbouidd          #+#    #+#             */
/*   Updated: 2026/02/17 13:08:47 by ilbouidd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void    game_start_P_C(t_game *game)
{
    int x;
    int y;
    
    y = 0;
    game->piece = 0;
    while (y < game->height)
    {
        x = 0;
        while (x < game->width)
        {
            if (game->map[y][x] == 'P')
            {
                game->player_x = x;
                game->player_y = y;
            }
            if (game->map[y][x] == 'C')
                game->piece = game->piece + 1;
            x++;
        }
        y++;
    }
}
 