/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_two.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbouidd <ilbouidd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 00:37:20 by ilbouidd          #+#    #+#             */
/*   Updated: 2026/03/06 01:32:02 by ilbouidd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	put_image(t_game *game, void *img, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->interface, img, x
		* game->img_width, y * game->img_height);
}

static void	put_all(t_game *game, int x, int y)
{
	if (game->map[y][x] == '1')
		put_image(game, game->wall_img, x, y);
	else if (game->map[y][x] == 'P')
		put_image(game, game->player_img, x, y);
	else if (game->map[y][x] == 'C')
		put_image(game, game->piece_img, x, y);
	else if (game->map[y][x] == 'E')
		put_image(game, game->exit_img, x, y);
}

static void	fill_game_row(t_game *game, int y)
{
	int	x;

	x = 0;
	while (x < game->width)
	{
		put_image(game, game->floor_img, x, y);
		put_all(game, x, y);
		x++;
	}
}

void	fill_game_window(t_game *game)
{
	int	y;

	y = 0;
	while (y < game->height)
	{
		fill_game_row(game, y);
		y++;
	}
}
