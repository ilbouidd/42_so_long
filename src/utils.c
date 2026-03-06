/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbouidd <ilbouidd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 15:15:26 by ilbouidd          #+#    #+#             */
/*   Updated: 2026/03/06 01:51:31 by ilbouidd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	count_lines(char *file)
{
	int		fd;
	char	*line;
	int		lines;
	int		tmp;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (-1);
	lines = 0;
	tmp = 1;
	while (tmp)
	{
		line = get_next_line(fd);
		if (!line)
			tmp = 0;
		else
		{
			lines++;
			free(line);
		}
	}
	close(fd);
	return (lines);
}
// char	**read_map(char *file)
// {
// 	char	**map;
// 	int		height;
// 	int		i;
// 	int		fd;
// 	char	*line;

// 	height = count_lines(file);
// 	if (height <= 0)
// 		return (NULL);
// 	map = malloc(sizeof(char *) * (height + 1));
// 	if (!map)
// 		return (NULL);
// 	fd = open(file, O_RDONLY);
// 	if (fd < 0)
// 	{
// 		free(map);
// 		return (NULL);
// 	}
// 	i = 0;
// 	line = get_next_line(fd);
// 	while (line)
// 	{
// 		map[i++] = ft_strtrim(line, "\n");
// 		free(line);
// 		line = get_next_line(fd);
// 	}
// 	map[i] = NULL;
// 	close(fd);
// 	return (map);
// }

void	free_map(char **map)
{
	int	i;

	if (!map)
		return ;
	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}
