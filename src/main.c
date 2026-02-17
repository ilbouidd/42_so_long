#include "../include/so_long.h"

int main(int ac, char **av)
{
    t_game  game;

    if (ac != 2)
        return (ft_printf("Error\n"), 1);
    game.map = read_map(av[1]);
    if (!game.map)
        return (ft_printf("Error reading map\n"), 1);
    if (error_all(ac, game.map, av))
        return (1);
    map_size(&game);
    game_start_P_C(&game);
    ft_printf("%d\n", game.piece);
    free_map(game.map);
    return (0);
}

