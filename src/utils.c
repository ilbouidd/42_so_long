/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbouidd <ilbouidd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 15:15:26 by ilbouidd          #+#    #+#             */
/*   Updated: 2026/02/19 01:48:38 by ilbouidd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int count_lines(const char *file)
{
    int     fd;
    char    *line;
    int     lines;

    fd = open(file, O_RDONLY);
    if (fd < 0)
        return (-1);
    lines = 0;
    while ((line = get_next_line(fd)) != NULL)
    {
        lines++;
        free(line);
    }
    close(fd);
    return (lines);
}


char **read_map(const char *file)
{
    int     fd;
    char    *line;
    char    **map;
    int     i;
    int     height;

    height = count_lines(file);
    if (height <= 0)
        return NULL;

    map = malloc(sizeof(char *) * (height + 1));
    if (!map)
        return NULL;

    fd = open(file, O_RDONLY);
    if (fd < 0)
    {
        free(map);
        return NULL;
    }

    i = 0;
    while ((line = get_next_line(fd)) != NULL)
    {
        map[i++] = ft_strtrim(line, "\n"); // supprime le \n
        free(line);
    }
    map[i] = NULL;
    close(fd);
    return map;
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