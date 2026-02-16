/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbouidd <ilbouidd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 15:15:26 by ilbouidd          #+#    #+#             */
/*   Updated: 2026/02/15 15:48:12 by ilbouidd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int count_lines(char *av)
{
    int fd;
    int count;
    char *line;

    count = 0;
    fd = open(av, O_RDONLY);
    if (fd < 0)
        return (0);
    line = get_next_line(fd);
    while (line)
    {
        count++;
        free(line);
        line = get_next_line(fd);
    }
    close(fd);
    return (count);
}

char **read_map(char *av)
{
    int fd;
    int i;
    int lines;
    char **map;

    lines = count_lines(av);
    if (lines == 0)
        return (NULL);

    map = malloc(sizeof(char *) * (lines + 1));
    if (!map)
        return (NULL);

    fd = open(av, O_RDONLY);
    i = 0;
    map[i] = get_next_line(fd);
    while (map[i])
    {
        i++;
        map[i] = get_next_line(fd);
    }
    close(fd);
    return (map);
}

void free_map(char **map)
{
    int i;

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