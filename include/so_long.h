/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbouidd <ilbouidd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 14:24:36 by ilbouidd          #+#    #+#             */
/*   Updated: 2026/03/04 00:22:26 by ilbouidd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"

typedef struct s_game
{
	char	**map;
	int		width;
	int		height;
	int		player_x;
	int		player_y;
	int		piece;
	void	*mlx;
	void	*interface;
	void	*player_img;
	void	*wall_img;
	void	*floor_img;
	void	*piece_img;
	void	*exit_img;
	int		img_height;
	int		img_width;
	int		moves;
}			t_game;

/*Parsing*/
int			error_outline(char *map);
int			error_outline_mid(char *map);
int			error_e_p(char **map);
int			error_c(char **map);
int			error_ber(char *av);
int			error_all(int ac, char **map, char **av);
int			error_second(char **map);
int			error_rectangle(char **map);
int			error_only_valid_char(char **map);
int			error_playable(char **map);
char		**copy_map(char **map);
void		find_player(char **map, int *px, int *py);
void		flood_fill(char **map, int x, int y);
int			check_accessible(char **map);

/*MAP*/
int			count_lines(char *file);
char		**read_map(char *file);
void		free_map(char **map);
int			map_height(char **map);
int			map_width(char **map);
void		map_size(t_game *game);
void		game_start_P_C(t_game *game);
void		game_start(t_game *game);
void		fill_game_window(t_game *game);
int			keyboard_game(int keycode, t_game *game);
void		move_player(t_game *game, int x, int y);
int			close_game(t_game *game);

#endif
