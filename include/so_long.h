/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbouidd <ilbouidd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 14:24:36 by ilbouidd          #+#    #+#             */
/*   Updated: 2026/02/16 12:06:23 by ilbouidd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "../libft/libft.h"
#include "../minilibx-linux/mlx.h"

typedef struct s_game 
{
    char **map;
    int count_cos;
    int pos_x;
    int pos_y;
    char *file_name;
}   t_game;


/*Parsing*/
int error_outline(char *map);
int error_outline_mid(char *map);
int error_e_p(char **map);
int error_c(char **map);
int error_ber(char  *av);
int error_all(int ac, char **map, char **av);
int error_second(char **map);
int error_rectangle(char **map);
int	error_only_valid_char(char **map);

/*MAP*/
int count_lines(char *file);
char **read_map(char *file);
void free_map(char **map);

#endif
