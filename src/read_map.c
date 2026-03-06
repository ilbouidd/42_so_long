/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbouidd <ilbouidd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 01:19:34 by ilbouidd          #+#    #+#             */
/*   Updated: 2026/03/06 01:22:00 by ilbouidd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static char	**allocate_map(int height)
{
	char	**map;

	if (height <= 0)
		return (NULL);
	map = malloc(sizeof(char *) * (height + 1));
	if (!map)
		return (NULL);
	return (map);
}

static void	fill_map_line(char **map, int *i, int fd)
{
	char	*line;

	line = get_next_line(fd);
	if (line)
	{
		map[*i] = ft_strtrim(line, "\n");
		free(line);
		(*i)++;
	}
}

static char	**fill_map(char **map, int height, int fd)
{
	int	i;

	i = 0;
	while (i < height)
	{
		fill_map_line(map, &i, fd);
		if (i == 0)
			break ;
	}
	map[i] = NULL;
	return (map);
}

char	**read_map(char *file)
{
	char	**map;
	int		height;
	int		fd;

	height = count_lines(file);
	map = allocate_map(height);
	if (!map)
		return (NULL);
	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		free(map);
		return (NULL);
	}
	map = fill_map(map, height, fd);
	close(fd);
	return (map);
}
