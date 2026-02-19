/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_one.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbouidd <ilbouidd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 12:22:35 by ilbouidd          #+#    #+#             */
/*   Updated: 2026/02/19 23:15:28 by ilbouidd         ###   ########.fr       */
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
 
void    game_start(t_game *game)
{
    game->mlx = mlx_init();
    if (!game->mlx)
        return ;
    game->interface = mlx_new_window(game->mlx, game->width * 64,
                        game->height * 64, "ilygames");
    if (!game->interface)
        return ;
    game->wall_img = mlx_xpm_file_to_image(game->mlx, "textures/wall_64.xpm",
                        &game->img_width, &game->img_height);
    game->floor_img = mlx_xpm_file_to_image(game->mlx, "textures/floor_64.xpm",
                        &game->img_width, &game->img_height);
    game->player_img = mlx_xpm_file_to_image(game->mlx, "textures/ilbouidd_64.xpm",
                        &game->img_width, &game->img_height);
    game->piece_img = mlx_xpm_file_to_image(game->mlx, "textures/42_64.xpm",
                        &game->img_width, &game->img_height);
    game->exit_img = mlx_xpm_file_to_image(game->mlx, "textures/billet_64.xpm",
                        &game->img_width, &game->img_height);
}

void fill_game_window(t_game *game)
{
    int x;
    int y;

    y = 0;
    while (y < game->height)
    {
        x = 0;
        while (x < game->width)
        {
            mlx_put_image_to_window(game->mlx,
                                    game->interface,
                                    game->floor_img,
                                    x * game->img_width,
                                    y * game->img_height);
            if (game->map[y][x] == '1') // mur
                mlx_put_image_to_window(game->mlx,
                                        game->interface,
                                        game->wall_img,
                                        x * game->img_width,
                                        y * game->img_height);
            else if (game->map[y][x] == 'P') // joueur
                mlx_put_image_to_window(game->mlx,
                                        game->interface,
                                        game->player_img,
                                        x * game->img_width,
                                        y * game->img_height);
            else if (game->map[y][x] == 'C') // pièce
                mlx_put_image_to_window(game->mlx,
                                        game->interface,
                                        game->piece_img,
                                        x * game->img_width,
                                        y * game->img_height);
            else if (game->map[y][x] == 'E') // sortie
                mlx_put_image_to_window(game->mlx,
                                        game->interface,
                                        game->exit_img,
                                        x * game->img_width,
                                        y * game->img_height);

            x++;
        }
        y++;
    }
}
