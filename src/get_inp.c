/*
** EPITECH PROJECT, 2020
** get
** File description:
** inp
*/

#include "my.h"

int get_inp(char **tab_map, char **av, int ac)
{
    if ((tab_map = get_input(tab_map, av, ac)) == NULL) {
        my_putstr("error map\n");
        return 84;
    }
}
