#include "../include/so_long.h"

int main(int ac, char **av)
{
    char **map;

    if (ac != 2)
        return (ft_printf("Error\n"), 1);
    map = read_map(av[1]);
    if (!map)
        return (ft_printf("Error reading map\n"), 1);
    if (error_all(ac, map, av))
        return (1);
    free_map(map);
    return (0);
}

