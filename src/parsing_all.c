/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_all.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbouidd <ilbouidd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 12:47:14 by ilbouidd          #+#    #+#             */
/*   Updated: 2026/02/16 19:16:38 by ilbouidd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int error_all(int ac, char **map, char **av)
{
    if (ac != 2)
        return (ft_printf("Error: false numbers of argument\n"), 1);
    if (error_ber(av[1]))
        return (ft_printf("Error: av[1] is not .ber\n"), 1);
    if (error_e_p(map))
        return (ft_printf("Error: not just 1 E or P\n"), 1);
    if (error_c(map))
        return (ft_printf("Error: No Commestiuble\n"), 1);
    if (error_only_valid_char(map))
        return (ft_printf("No valid character\n"), 1);
    if (error_playable(map))
        return (ft_printf("Is not possible to finish the map\n"), 1);
    if (error_second(map))
        return (1);
    return (0);
}

int error_second(char **map)
{
    int i;
    int len;
    
    if (!map || !map[0])
        return (1);
    i = 1;
    len = 0;
    while (map[len])
        len++;
    if (error_rectangle(map))
        return (ft_printf("Map not rectangle\n"), 1);
    if (error_outline(map[0]) || error_outline(map[len - 1]))
        return (ft_printf("Error: map outline"), 1);
    while (i < len - 1)
    {
        if (error_outline_mid(map[i]))
            return (1);
        i++;
    }
    return (0);
}

int error_rectangle(char **map)
{
    int i;
    size_t len_map;

    i = 0;
    len_map = ft_strlen(map[0]);
    while (map[i])
    {
        if (ft_strlen(map[i]) != len_map)
            return (1);
        i++;
    }
    return (0);
}

int	error_only_valid_char(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != '0' && map[i][j] != '1'
				&& map[i][j] != 'P' && map[i][j] != 'C'
				&& map[i][j] != 'E')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int error_playable(char **map)
{
    char **copy;
    int px;
    int py;
    int res;

    copy = copy_map(map);
    if (!copy)
        return (1);
    find_player(copy, &px, &py);
    flood_fill(copy, px, py);
    res = check_accessible(copy);
    free_map(copy);
    return (res);
}