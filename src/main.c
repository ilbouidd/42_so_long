/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbouidd <ilbouidd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 00:49:15 by ilbouidd          #+#    #+#             */
/*   Updated: 2026/03/06 01:03:38 by ilbouidd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(int ac, char **av)
{
	t_game	game;

	game.map = read_map(av[1]);
	if (!game.map)
		return (ft_printf("Error\nMap reading failed\n"), 1);
	if (error_all(ac, game.map, av))
		return (free_map(game.map), 1);
	map_size(&game);
	game_start_p_c(&game);
	if (error_playable(&game, game.map))
		return (ft_printf("Error\n Is not possible to finish the map\n"), 1);
	game_start(&game);
	if (!game.mlx || !game.interface)
		return (free_map(game.map), 1);
	game.moves = 0;
	fill_game_window(&game);
	mlx_hook(game.interface, 17, 0, close_game, &game);
	mlx_loop(game.mlx);
	return (0);
}
