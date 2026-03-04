/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_two.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbouidd <ilbouidd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 00:37:20 by ilbouidd          #+#    #+#             */
/*   Updated: 2026/03/04 00:41:31 by ilbouidd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	fill_game_window(t_game *game)
{
	int x;
	int y;

	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			mlx_put_image_to_window(game->mlx, game->interface, game->floor_img,
				x * game->img_width, y * game->img_height);
			if (game->map[y][x] == '1')
				mlx_put_image_to_window(game->mlx, game->interface,
					game->wall_img, x * game->img_width, y * game->img_height);
			else if (game->map[y][x] == 'P')
				mlx_put_image_to_window(game->mlx, game->interface,
					game->player_img, x * game->img_width, y
					* game->img_height);
			else if (game->map[y][x] == 'C')
				mlx_put_image_to_window(game->mlx, game->interface,
					game->piece_img, x * game->img_width, y * game->img_height);
			else if (game->map[y][x] == 'E')
				mlx_put_image_to_window(game->mlx, game->interface,
					game->exit_img, x * game->img_width, y * game->img_height);
			x++;
		}
		y++;
	}
}