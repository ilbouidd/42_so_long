/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_player_second.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbouidd <ilbouidd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 00:44:59 by ilbouidd          #+#    #+#             */
/*   Updated: 2026/03/07 01:06:21 by ilbouidd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	flood_fill_e(char **map, int x, int y)
{
	if (map[y][x] == '1' || map[y][x] == 'E' || map[y][x] == 'f')
		return ;
	map[y][x] = 'f';
	flood_fill_e(map, x + 1, y);
	flood_fill_e(map, x - 1, y);
	flood_fill_e(map, x, y + 1);
	flood_fill_e(map, x, y - 1);
}

int	check_accessible_e(char **map)
{
	int	y;
	int	x;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'C')
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}

int	error_playable_e(t_game *game, char **map)
{
	char	**copy_e;
	int		px;
	int		py;
	int		res;

	px = game->player_x;
	py = game->player_y;
	copy_e = copy_map(map);
	if (!copy_e)
		return (1);
	find_player(copy_e, &px, &py);
	flood_fill_e(copy_e, px, py);
	res = check_accessible_e(copy_e);
	free_map(copy_e);
	return (res);
}
