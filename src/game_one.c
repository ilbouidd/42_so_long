/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_one.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbouidd <ilbouidd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 12:22:35 by ilbouidd          #+#    #+#             */
/*   Updated: 2026/03/04 00:42:07 by ilbouidd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	game_start_p_c(t_game *game)
{
	int	x;
	int	y;

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

void	game_start(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		return ;
	game->moves = 0;
	game->interface = mlx_new_window(game->mlx, game->width * 64, game->height
			* 64, "ilygames");
	if (!game->interface)
		return ;
	game->wall_img = mlx_xpm_file_to_image(game->mlx, "textures/wall_64.xpm",
			&game->img_width, &game->img_height);
	game->floor_img = mlx_xpm_file_to_image(game->mlx, "textures/floor_64.xpm",
			&game->img_width, &game->img_height);
	game->player_img = mlx_xpm_file_to_image(game->mlx,
			"textures/ilbouidd_64.xpm", &game->img_width, &game->img_height);
	game->piece_img = mlx_xpm_file_to_image(game->mlx, "textures/42_64.xpm",
			&game->img_width, &game->img_height);
	game->exit_img = mlx_xpm_file_to_image(game->mlx, "textures/billet_64.xpm",
			&game->img_width, &game->img_height);
	mlx_key_hook(game->interface, keyboard_game, game);
}

int	keyboard_game(int keycode, t_game *game)
{
	if (keycode == 65307)
		close_game(game);
	if (keycode == 119)
		move_player(game, 0, -1);
	if (keycode == 97)
		move_player(game, -1, 0);
	if (keycode == 115)
		move_player(game, 0, 1);
	if (keycode == 100)
		move_player(game, 1, 0);
	return (0);
}

void	move_player(t_game *game, int x, int y)
{
	int	new_x;
	int	new_y;

	new_x = game->player_x + x;
	new_y = game->player_y + y;
	if (game->map[new_y][new_x] == '1')
		return ;
	if (game->map[new_y][new_x] == 'C')
		game->piece--;
	if (game->map[new_y][new_x] == 'E')
	{
		if (game->piece == 0)
		{
			ft_printf("ilyWIN!\n");
			close_game(game);
		}
		return ;
	}
	game->map[game->player_y][game->player_x] = '0';
	game->player_x = new_x;
	game->player_y = new_y;
	game->map[new_y][new_x] = 'P';
	game->moves++;
	ft_printf("Moves: %d\n", game->moves);
	fill_game_window(game);
}

int	close_game(t_game *game)
{
	free_map(game->map);
	mlx_destroy_image(game->mlx, game->exit_img);
	mlx_destroy_image(game->mlx, game->wall_img);
	mlx_destroy_image(game->mlx, game->floor_img);
	mlx_destroy_image(game->mlx, game->player_img);
	mlx_destroy_image(game->mlx, game->piece_img);
	mlx_destroy_window(game->mlx, game->interface);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	exit(0);
}

