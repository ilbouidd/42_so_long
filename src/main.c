#include "../include/so_long.h"

int main(int ac, char **av)
{
    t_game  game;

    game.map = read_map(av[1]);
    if (!game.map)
        return (ft_printf("Error reading map\n"), 1);
    if (error_all(ac, game.map, av))
        return (free_map(game.map), 1);
    map_size(&game);
    game_start_P_C(&game);
    game_start(&game);
    fill_game_window(&game);
    mlx_loop(game.mlx);
    return (0);
}
