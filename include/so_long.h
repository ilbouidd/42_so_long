/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbouidd <ilbouidd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 14:24:36 by ilbouidd          #+#    #+#             */
/*   Updated: 2026/02/19 01:48:56 by ilbouidd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "../libft/libft.h"
#include "../minilibx-linux/mlx.h"

typedef struct s_game
{
    char    **map;       // la map
    int     width;       // largeur de la map
    int     height;      // hauteur de la map
    int     player_x;    // position du joueur
    int     player_y;
    int     piece; // nombre de C restants
    void	*mlx;        // pointeur mlx
    void	*interface;        // fenêtre mlx
    void    *player_img;
    void    *wall_img;
    void    *floor_img;
    void    *piece_img;
    void    *exit_img;
    int     img_height;
    int     img_width;
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
int error_playable(char **map);
char **copy_map(char **map);
void find_player(char **map, int *px, int *py);
void flood_fill(char **map, int x, int y);
int check_accessible(char **map);

/*MAP*/
int count_lines(const char *file);
char **read_map(const char *file);
void free_map(char **map);
int map_height(char **map);
int map_width(char **map);
void    map_size(t_game *game);
void    game_start_P_C(t_game *game);
void    game_start(t_game *game);
void fill_game_window(t_game *game);


#endif
